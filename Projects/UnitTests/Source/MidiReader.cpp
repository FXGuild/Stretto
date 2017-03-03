/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece
 Content   : Unit tests for function read (midi file)
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Piece/MidiReader.h>

namespace FXG::Stretto::Piece
{
   TEST(Piece_MidiReader, General)
   {
      read("../../../TestResources/runascape.mid");
   }
}
