/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 2, 2017
 Namespace : FXG::Stretto::Piece
 Content   : Function for reading a piece
\**************************************************************************************************/

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <JuceHeader.h>

#include <FXG/Stretto/Piece/MidiReader.h>

namespace FXG::Stretto::Piece
{
   Monophonic::Piece read(std::string const & a_FilePath)
   {
      // Read midi file
      juce::File workingDir = juce::File::getCurrentWorkingDirectory();
      std::cout << "Working directory: " << workingDir.getFullPathName() << std::endl;
      std::cout << "Reading midi file: " << a_FilePath << std::endl;
      juce::File            file = workingDir.getChildFile(a_FilePath.c_str());
      juce::FileInputStream stream{ file };
      juce::MidiFile        midiFile;
      midiFile.readFrom(stream);

      // Check if time format is supported
      short timeFormat = midiFile.getTimeFormat();
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
            auto const &              event     = *track.getEventPointer(j);
            juce::MidiMessage const & msg       = event.message;
            double                    timestamp = msg.getTimeStamp();

            std::cout << "\t" << timestamp << "\t" << msg.getDescription() << std::endl;
         }
      }

      return Monophonic::Piece();
   }
}
