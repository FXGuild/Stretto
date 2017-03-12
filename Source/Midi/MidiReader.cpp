/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 2, 2017
 Namespace : FXG::Stretto::Midi
 Content   : Function for reading a piece
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/JUCEUtils/FileUtils.h>
#include <FXG/Stretto/Midi/MidiReader.h>
#include <FXG/Stretto/Piece/Monophonic/PartBuilder.h>

namespace FXG::Stretto::Midi
{
   static Piece::Monophonic::Part assemblePart(std::vector<Theory::Pitch> a_Pitches,
                                               std::vector<uint32_t>      a_TimeUnits,
                                               Theory::NoteDuration       a_DurationUnit)
   {
      assert(2 * a_Pitches.size() == a_TimeUnits.size());

      Piece::Monophonic::PartBuilder builder{ a_DurationUnit };

      uint32_t prevNoteEnd = 0;

      for (uint32_t i = 0; i < a_Pitches.size(); ++i)
      {
         uint32_t noteBeg = a_TimeUnits[i * 2];
         uint32_t noteEnd = a_TimeUnits[i * 2 + 1];
         assert(noteBeg < noteEnd);
         assert(noteBeg >= prevNoteEnd);

         // If needed, add rest between previous note (or track beginning) and current note
         if (noteBeg > prevNoteEnd)
         {
            builder.addRest(noteBeg - prevNoteEnd);
         }

         // Add note to part
         Theory::AggregatedNote note{ a_Pitches[i], noteEnd - noteBeg };
         builder.addNote(note);

         // Update previous note end
         prevNoteEnd = noteEnd;
      }

      // TODO: add rest at the end until the actual end of the part

      return builder.build();
   }

   static void convertTicksToTimeUnits(std::vector<uint32_t> & a_Ticks,
                                       uint32_t                a_TicksPerTU,
                                       uint32_t                a_AnacrusisCorrection)
   {
      int32_t currDeltaTick = 0;
      double  tuPerTick     = 1.0 / static_cast<double>(a_TicksPerTU);

      // For all Midi ticks timestamps
      for (uint32_t i = 0; i < a_Ticks.size(); ++i)
      {
         // Raw midi tick value
         uint32_t tick = a_Ticks[i] + (rand() % 11 - 5);

         // Anacrusis correction tick value
         uint32_t corrTick = tick + a_AnacrusisCorrection;

         // Anacrusis and delta correction tick value
         uint32_t deltaCorrTick = corrTick + currDeltaTick;

         // Rounded final timeunit value
         uint32_t roundedTU = static_cast<uint32_t>(std::rint(deltaCorrTick * tuPerTick));
         a_Ticks[i]         = roundedTU;

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

   static Piece::Monophonic::Part processMonophonicTrack(juce::MidiMessageSequence const & a_Track,
                                                         uint32_t             a_TicksPerTU,
                                                         Theory::NoteDuration a_DurationUnit)
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
      std::vector<Pitch> pitches;

      // Chronologically sorted timestamps
      std::vector<uint32_t> ticks;

      // Used to verify that part is monophonic
      juce::MidiMessageSequence::MidiEventHolder * lastNoteOff{ nullptr };

      // Process Midi events in track
      for (int32_t j = 0; j < a_Track.getNumEvents(); ++j)
      {
         auto const & eventPtr = a_Track.getEventPointer(j);
         auto const & msg      = eventPtr->message;
         uint32_t     tick     = static_cast<uint32_t>(msg.getTimeStamp());

         // TODO: debug
         std::cout << "\t" << tick << "\t" << msg.getDescription() << std::endl;

         if (msg.isNoteOn())
         {
            // Check that part is monophonic
            assert(lastNoteOff == nullptr);

            // Create Pitch from midi note number
            int8_t midiNote = static_cast<int8_t>(msg.getNoteNumber());
            pitches.emplace_back(DEFAULT_TONES[midiNote % 12], (midiNote / 12) - 1);
            ticks.push_back(tick);

            // Get note off tick
            lastNoteOff = eventPtr->noteOffObject;
            ticks.push_back(static_cast<uint32_t>(lastNoteOff->message.getTimeStamp()));
         }
         else if (msg.isNoteOff())
         {
            // Check that part is monophonic
            assert(eventPtr == lastNoteOff);
            lastNoteOff = nullptr;
         }
      }

      // We don't want last note not to end...
      assert(lastNoteOff == nullptr);

      // TODO: anacrusis correction
      convertTicksToTimeUnits(ticks, a_TicksPerTU, 0);

      return assemblePart(pitches, ticks, a_DurationUnit);
   }

   bool readMidiFile(std::string const & a_FilePath, juce::MidiFile & a_MidiFile)
   {
      juce::FileInputStream stream{ JUCEUtils::createFileReference(a_FilePath) };
      if (stream.openedOk())
      {
         a_MidiFile.readFrom(stream);
         return true;
      }
      return false;
   }

   Piece::Monophonic::Piece readMonophonicPiece(juce::MidiFile const & a_MidiFile,
                                                Theory::NoteDuration   a_DurationUnit)
   {
      // Check if time format is supported
      short timeFormat = a_MidiFile.getTimeFormat();
      // TODO: upgrade error handling
      assert(timeFormat > 0);

      // Compute timeunit to Midi tick conversion factor
      uint32_t tuPerQuarter = convertDurationToTU(Theory::NoteDuration::QUARTER, a_DurationUnit);
      assert(timeFormat % tuPerQuarter == 0);
      uint32_t ticksPerTU = timeFormat / tuPerQuarter;

      // Create empty piece structure
      Piece::Monophonic::Piece piece;

      // Process tracks
      for (uint8_t i = 0; i < a_MidiFile.getNumTracks(); ++i)
      {
         // TODO: debug
         std::cout << "Processing track #" << (static_cast<uint32_t>(i) + 1) << std::endl;
         auto const * track = a_MidiFile.getTrack(i);
         piece.addPart(processMonophonicTrack(*track, ticksPerTU, a_DurationUnit));
      }

      return piece;
   }
}
