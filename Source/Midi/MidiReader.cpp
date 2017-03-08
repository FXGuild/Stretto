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
#include <stdio.h>

#include <Juce/AudioBasics.h>

#include <FXG/Stretto/Midi/MidiReader.h>
#include <FXG/Stretto/JUCEUtils/FileUtils.h>

namespace FXG::Stretto::Midi
{
   static void processMsg(juce::MidiMessage const & a_Msg, double a_Timestamp)
   {
   }

   Piece::Monophonic::Piece read(std::string const & a_FilePath)
   {
      // Read midi file
      juce::File file = Utils::openFile(a_FilePath);
      std::cout << "Reading midi file " << file.getFullPathName() << std::endl;
      juce::FileInputStream stream{ file };
      juce::MidiFile        midiFile;
      midiFile.readFrom(stream);

      // Check if time format is supported
      short timeFormat = midiFile.getTimeFormat();
      // TODO upgrade assert system to incorporate messages
      assert(timeFormat > 0);
      // TODO use me
      uint16_t numMidiTicksPerQuarterNote = static_cast<uint16_t>(timeFormat);
      std::cout << "Num midi ticks per quarter note: " << numMidiTicksPerQuarterNote << std::endl;

      // Process tracks
      for (uint8_t i = 0; i < midiFile.getNumTracks(); ++i)
      {
         std::cout << "Processing track #" << (static_cast<uint32_t>(i) + 1) << std::endl;
         auto const & track = *midiFile.getTrack(i);

         for (int32_t j = 0; j < track.getNumEvents(); ++j)
         {
            auto const & event     = *track.getEventPointer(j);
            auto const & msg       = event.message;
            double       timestamp = msg.getTimeStamp();

            std::cout << "\t" << timestamp << "\t" << msg.getDescription() << std::endl;
         }
      }

      return Piece::Monophonic::Piece();
   }
}
