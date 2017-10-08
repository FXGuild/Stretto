/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : October 7, 2017
 Summary     : Unit tests for ReadMidiFile.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Stretto/Midi/ReadMidiFile.h>

namespace SGG::UnitTests
{
   TEST ( SGG_Stretto_Midi_ReadMidiFile, General )
   {
      Stretto::Midi::MidiPiece            piece;
      Stretto::Theory::NoteDuration const durUnit = Stretto::Theory::NoteDuration::SIXTYFOURTH;
      // TODO_SGG no abs path
      String const                        filePath =
         L"C:\\Users\\jerem\\Git\\FXGuild\\Stretto\\Resource\\UnitTests\\Midi\\mtpdk.mid";
      EXPECT_TRUE ( Stretto::Midi::readMidiFile ( filePath, durUnit, piece ).IsSuccess () );
   }
}
