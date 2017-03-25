/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::Utils
 Content   : Unit tests for string enum utilities
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Theory/Accidental.h>
#include <FXG/Stretto/Theory/NoteLetter.h>
#include <FXG/Stretto/StringEnum.h>

namespace FXG::Stretto::Utils
{
   TEST(Utils_StringEnum, General)
   {
      EXPECT_STREQ(toString(Theory::NoteLetter::C).c_str(), "C");
      EXPECT_STRNE(toString(Theory::NoteLetter::D).c_str(), "G");
   }
}
