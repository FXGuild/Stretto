#include <assert.h>

#include <SGG/Stretto/Midi/ReadMidiFile.h>
#include <SGG/Stretto/Theory/Elementary/Pitch.h>
#include <ThirdParty/Juce/AudioBasics.h>

namespace SGG::Stretto::Midi
{
   static Theory::Piece::Part assemblePart ( std::vector< Theory::Pitch > a_Pitches,
                                             std::vector< uint32_t >      a_TimeUnits,
                                             Theory::NoteDuration         a_DurationUnit )
   {
      assert ( 2 * a_Pitches.size () == a_TimeUnits.size () );

      Theory::Piece::PartBuilder builder{ a_DurationUnit };

      uint32_t prevNoteEnd = 0;

      for ( uint32_t i = 0; i < a_Pitches.size (); ++i )
      {
         uint32_t noteBeg = a_TimeUnits[ i * 2 ];
         uint32_t noteEnd = a_TimeUnits[ i * 2 + 1 ];
         assert ( noteBeg < noteEnd );
         assert ( noteBeg >= prevNoteEnd );

         // If needed, add rest between previous note (or track beginning) and current note
         if ( noteBeg > prevNoteEnd )
         {
            builder.addRest ( noteBeg - prevNoteEnd );
         }

         // Add note to part
         Theory::AggregatedNote note{ a_Pitches[ i ], noteEnd - noteBeg };
         builder.addNote ( note );

         // Update previous note end
         prevNoteEnd = noteEnd;
      }

      // TODO: add rest at the end until the actual end of the part

      return builder.build ();
   }

   static void convertTicksToTimeUnits ( std::vector< uint32_t > & a_Ticks,
                                         uint32_t                  a_TicksPerTU,
                                         uint32_t                  a_AnacrusisCorrection )
   {
      int32_t currDeltaTick = 0;
      double  tuPerTick     = 1.0 / static_cast< double > ( a_TicksPerTU );

      // For all Midi ticks timestamps
      for ( uint32_t i = 0; i < a_Ticks.size (); ++i )
      {
         // Raw midi tick value
         uint32_t tick = a_Ticks[ i ] + ( rand () % 11 - 5 );

         // Anacrusis correction tick value
         uint32_t corrTick = tick + a_AnacrusisCorrection;

         // Anacrusis and delta correction tick value
         uint32_t deltaCorrTick = corrTick + currDeltaTick;

         // Rounded final timeunit value
         uint32_t roundedTU = static_cast< uint32_t > ( std::rint ( deltaCorrTick * tuPerTick ) );
         a_Ticks[ i ]       = roundedTU;

         // Rounded tick value
         uint32_t roundedTick = roundedTU * a_TicksPerTU;

         // Delta tick
         int32_t deltaTick = roundedTick - corrTick;

         // Delta delta
         int32_t deltaDelta = deltaTick - currDeltaTick;

         // Update current delta
         currDeltaTick = deltaTick;
      }
   }

   static Result readTrack ( juce::MidiMessageSequence const & i_MidiTrack,
                             uint32_t const                    i_TicksPerTU,
                             Theory::NoteDuration const        i_DurationUnit,
                             MidiTrack &                       o_Track )
   {
      using namespace Theory;

      static Tone const DEFAULT_TONES[] = {
         { NoteLetter::C, Accidental::NATURAL }, { NoteLetter::C, Accidental::SHARP },
         { NoteLetter::D, Accidental::NATURAL }, { NoteLetter::E, Accidental::FLAT },
         { NoteLetter::E, Accidental::NATURAL }, { NoteLetter::F, Accidental::NATURAL },
         { NoteLetter::F, Accidental::SHARP },   { NoteLetter::G, Accidental::NATURAL },
         { NoteLetter::A, Accidental::FLAT },    { NoteLetter::A, Accidental::NATURAL },
         { NoteLetter::B, Accidental::FLAT },    { NoteLetter::B, Accidental::FLAT }
      };

      // Sequential note pitches
      Vec< Pitch > pitches;

      // Chronologically sorted timestamps
      Vec< uint32_t > ticks;

      // Used to verify that part is monophonic
      juce::MidiMessageSequence::MidiEventHolder * lastNoteOff{ nullptr };

      // Process Midi events in track
      for ( int32_t j = 0; j < i_MidiTrack.getNumEvents (); ++j )
      {
         auto const & eventPtr = i_MidiTrack.getEventPointer ( j );
         auto const & msg      = eventPtr->message;
         uint32_t     tick     = static_cast< uint32_t > ( msg.getTimeStamp () );

         // TODO remove me
         std::cout << "\t" << tick << "\t" << msg.getDescription () << std::endl;

         if ( msg.isNoteOn () )
         {
            // Check that part is monophonic
            assert ( lastNoteOff == nullptr );

            // Create Pitch from midi note number
            int8_t midiNote = static_cast< int8_t > ( msg.getNoteNumber () );
            pitches.emplace_back ( DEFAULT_TONES[ midiNote % 12 ], ( midiNote / 12 ) - 1 );
            ticks.push_back ( tick );

            // Get note off tick
            lastNoteOff = eventPtr->noteOffObject;
            ticks.push_back ( static_cast< uint32_t > ( lastNoteOff->message.getTimeStamp () ) );
         }
         else if ( msg.isNoteOff () )
         {
            // Check that part is monophonic
            assert ( eventPtr == lastNoteOff );
            lastNoteOff = nullptr;
         }
      }

      // We don't want last note not to end...
      assert ( lastNoteOff == nullptr );

      // TODO: anacrusis correction
      convertTicksToTimeUnits ( ticks, i_TicksPerTU, 0 );

      return assemblePart ( pitches, ticks, i_DurationUnit );
   }

   Result readMidiFile ( String const &             i_FilePath,
                         Theory::NoteDuration const i_DurationUnit,
                         MidiPiece &                o_Piece )
   {
      o_Piece.clear ();

      // Open file
      juce::File const file{ juce::String{ i_FilePath.c_str () } };
      ERROR_ON_FALSE ( file.existsAsFile (), L"File not found" );

      // Read midi file using JUCE
      juce::FileInputStream stream{ file };
      ERROR_ON_FALSE ( stream.openedOk (), L"Error opening file" );
      juce::MidiFile midiFile;
      ERROR_ON_FALSE ( midiFile.readFrom ( stream ), L"Could not read midi file" );

      // Check if time format is supported
      short const timeFormat{ midiFile.getTimeFormat () };
      ERROR_ON_FALSE ( timeFormat > 0, L"Unsupported time format" );

      // Compute timeunit to midi tick conversion factor
      uint32_t const tuPerQuarter{ convertDurationToTU ( Theory::NoteDuration::QUARTER,
                                                         i_DurationUnit ) };
      ERROR_ON_FALSE ( timeFormat % tuPerQuarter == 0, L"Invalid duration unit" );
      uint32_t const ticksPerTU{ timeFormat / tuPerQuarter };

      // Process tracks
      for ( uint32_t i = 0; i < midiFile.getNumTracks (); ++i )
      {
         // TODO remove me
         std::wcout << "Processing track #" << ( i + 1 ) << std::endl;

         juce::MidiMessageSequence const & midiTrack{ *midiFile.getTrack ( i ) };
         MidiTrack                         track;
         PROPAGATE_ERROR ( readTrack ( midiTrack, ticksPerTU, i_DurationUnit, track ),
                           L"Error processing track #" + ( i + 1 ) );

         o_Piece.addTrack ( std::move ( track ) );
      }

      return Result::ok ();
   }
}
