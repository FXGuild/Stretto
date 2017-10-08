#include <SGG/Stretto/Midi/ReadMidiFile.h>
#include <SGG/Stretto/Theory/Elementary/Pitch.h>
#include <ThirdParty/Juce/AudioBasics.h>

namespace SGG::Stretto::Midi
{
   using EventPtr = juce::MidiMessage const *;

   struct ExtractedTrackMidiEvents
   {
      // NoteOn Event + NoteOff timestamp
      Vec< Pair< EventPtr, uint32_t > > m_NoteOnEvents;
      Vec< EventPtr >                   m_InstrChangeEvents;
   };

   struct ExtractedPieceMidiEvents
   {
      Vec< ExtractedTrackMidiEvents > m_PerTrackEvents;
      Vec< EventPtr >                 m_TempoChangeEvents;
      Vec< EventPtr >                 m_TimeSignChangeEvents;
   };

   Result extractMidiEvents ( juce::MidiFile const &     i_MidiFile,
                              ExtractedPieceMidiEvents & o_ExtractedEvents,
                              Set< uint32_t > &          o_Ticks )
   {
      uint8_t const numTracks = i_MidiFile.getNumTracks ();
      o_ExtractedEvents.m_PerTrackEvents.resize ( numTracks );

      for ( uint32_t i = 0; i < numTracks; ++i )
      {
         juce::MidiMessageSequence const & midiTrack = *i_MidiFile.getTrack ( i );

         ExtractedTrackMidiEvents & trackEvents = o_ExtractedEvents.m_PerTrackEvents[ i ];

         for ( int32_t j = 0; j < midiTrack.getNumEvents (); ++j )
         {
            auto const &   eventHolder = *midiTrack.getEventPointer ( j );
            auto const &   event       = eventHolder.message;
            uint32_t const tick        = static_cast< uint32_t > ( event.getTimeStamp () );

            // TODO_SGG remove me
            std::wcout << L"\t" << tick << L"\t" << event.getDescription () << std::endl;

            if ( event.isNoteOn () )
            {
               auto const * noteOffEventHolder = eventHolder.noteOffObject;
               ERROR_ON_NULL ( noteOffEventHolder );
               auto const &   pNoteOffEvent = noteOffEventHolder->message;
               uint32_t const tick = static_cast< uint32_t > ( pNoteOffEvent.getTimeStamp () );
               o_Ticks.emplace ( tick );
               trackEvents.m_NoteOnEvents.emplace_back ( std::make_pair ( &event, tick ) );
            }
            else if ( event.isProgramChange () )
            {
               trackEvents.m_InstrChangeEvents.emplace_back ( &event );
            }
            else if ( event.isTempoMetaEvent () )
            {
               o_ExtractedEvents.m_TempoChangeEvents.emplace_back ( &event );
            }
            else if ( event.isTimeSignatureMetaEvent () )
            {
               o_ExtractedEvents.m_TimeSignChangeEvents.emplace_back ( &event );
            }
            else
            {
               continue;
            }

            o_Ticks.emplace ( tick );
         }
      }

      return Result::ok ();
   }

   static Result createTickToTimeUnitMap ( Set< uint32_t > &           i_Ticks,
                                           Theory::NoteDuration const  i_DurationUnit,
                                           short const                 i_TimeFormat,
                                           Map< uint32_t, TimeUnit > & o_TickToTU )
   {
      o_TickToTU.clear ();

      ERROR_ON_FALSE ( i_TimeFormat > 0, L"Unsupported time format" );

      Theory::NoteDuration const quarter = Theory::NoteDuration::QUARTER;
      uint32_t const tuPerQuarter        = convertDurationToTimeunit ( quarter, i_DurationUnit );

      ERROR_ON_FALSE ( i_TimeFormat % tuPerQuarter == 0, L"Invalid duration unit" );

      uint32_t const ticksPerTU = i_TimeFormat / tuPerQuarter;
      double const   tuPerTick  = 1.0 / static_cast< double > ( ticksPerTU );

      int32_t currDeltaTick = 0;

      for ( uint32_t const tick : i_Ticks )
      {
         // Delta corrected tick value
         uint32_t const corrTick = tick + currDeltaTick;

         // Timeunit value
         uint32_t const tu = static_cast< uint32_t > ( std::rint ( corrTick * tuPerTick ) );
         o_TickToTU.emplace ( tick, tu );

         // Rounded tick value
         uint32_t const roundedTick = tu * ticksPerTU;

         // Update current delta
         currDeltaTick = roundedTick - tick;
      }

      return Result::ok ();
   }

   static Result buildMidiTrack ( ExtractedTrackMidiEvents const &  i_Events,
                                  Map< uint32_t, TimeUnit > const & i_TickToTU,
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

      for ( auto const & noteOnAndOff : i_Events.m_NoteOnEvents )
      {
         auto const &   noteOnEvent = *noteOnAndOff.first;
         uint32_t const startTick   = static_cast< uint32_t > ( noteOnEvent.getTimeStamp () );
         TimeUnit const startTU     = i_TickToTU.at ( startTick );
         TimeUnit const endTU       = i_TickToTU.at ( noteOnAndOff.second );
         int8_t const   midiNote    = static_cast< int8_t > ( noteOnEvent.getNoteNumber () );

         Theory::Pitch const pitch{ DEFAULT_TONES[ midiNote % 12 ], ( midiNote / 12 ) - 1 };
         Theory::BasicNote   note{ pitch, endTU - startTick };

         PROPAGATE_ERROR ( o_Track.addNoteEvent ( note, startTU ), L"Could not add note" );
      }

      for ( EventPtr pEvent : i_Events.m_InstrChangeEvents )
      {
         MidiInstrument const instr = MidiInstrument ( pEvent->getProgramChangeNumber () );
         uint32_t const       tick  = static_cast< uint32_t > ( pEvent->getTimeStamp () );
         PROPAGATE_ERROR ( o_Track.addInstrumentChange ( instr, i_TickToTU.at ( tick ) ),
                           L"Could not add instrument change" );
      }

      return Result::ok ();
   }

   static Result buildMidiPiece ( ExtractedPieceMidiEvents const &  i_MidiEvents,
                                  Map< uint32_t, TimeUnit > const & i_TickToTU,
                                  MidiPiece &                       o_Piece )
   {
      for ( EventPtr pEvent : i_MidiEvents.m_TempoChangeEvents )
      {
         // TODO_SGG
      }

      for ( EventPtr pEvent : i_MidiEvents.m_TimeSignChangeEvents )
      {
         int num, denom;
         pEvent->getTimeSignatureInfo ( num, denom );
         Theory::TimeSignature const timeSign{ static_cast< uint8_t > ( num ),
                                               static_cast< uint8_t > ( denom ) };
         uint32_t const              tick = static_cast< uint32_t > ( pEvent->getTimeStamp () );
         PROPAGATE_ERROR ( o_Piece.addTimeSignatureChange ( timeSign, i_TickToTU.at ( tick ) ),
                           L"Could not add time signature change" );
      }

      for ( ExtractedTrackMidiEvents const & trackEvents : i_MidiEvents.m_PerTrackEvents )
      {
         MidiTrack track;
         PROPAGATE_ERROR ( buildMidiTrack ( trackEvents, i_TickToTU, track ),
                           L"Error building track" );
         o_Piece.addTrack ( std::move ( track ) );
      }

      return Result::ok ();
   }

   Result readMidiFile ( String const &             i_FilePath,
                         Theory::NoteDuration const i_DurationUnit,
                         MidiPiece &                o_Piece )
   {
      o_Piece.clear ();

      // Open file
      juce::File const file = juce::String{ i_FilePath.c_str () };
      ERROR_ON_FALSE ( file.existsAsFile (), L"File not found" );

      // Read midi file using JUCE
      juce::FileInputStream stream{ file };
      ERROR_ON_FALSE ( stream.openedOk (), L"Error opening file" );
      juce::MidiFile midiFile;
      ERROR_ON_FALSE ( midiFile.readFrom ( stream ), L"Could not read midi file" );

      // Extract relevant midi events and their timestamps
      ExtractedPieceMidiEvents extractedEvents;
      Set< uint32_t >          ticks;
      PROPAGATE_ERROR ( extractMidiEvents ( midiFile, extractedEvents, ticks ),
                        L"Error extracting midi events" );

      // Convert midi tick timestamps to time units
      short const               timeFormat = midiFile.getTimeFormat ();
      Map< uint32_t, TimeUnit > tickToTU;
      PROPAGATE_ERROR ( createTickToTimeUnitMap ( ticks, i_DurationUnit, timeFormat, tickToTU ),
                        L"Error creating tick to timeunit map" );

      // Interpret midi events
      return buildMidiPiece ( extractedEvents, tickToTU, o_Piece );
   }
}
