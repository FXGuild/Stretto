/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Midi
 Content   : Unit tests for function read (midi file)
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Midi/MidiReader.h>

namespace FXG::Stretto::Midi
{
   TEST(Piece_MidiReader, General)
   {
      std::string const testFilePath = "../Resource/UnitTests/runascape.mid";
      juce::MidiFile    midiFile;
      EXPECT_TRUE(readMidiFile(testFilePath, midiFile));
      auto piece = readMonophonicPiece(midiFile, Theory::NoteDuration::SIXTYFOURTH);
      for (auto const & part : piece)
      {
         std::cout << part.aggregatedView() << std::endl;
      }
   }
}
