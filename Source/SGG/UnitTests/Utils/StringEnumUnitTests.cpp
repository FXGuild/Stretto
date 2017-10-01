/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for StringEnum.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Utils/StringEnum.h>

DECLARE_STRING_ENUM ( SGG::UnitTests, Color, Red, Blue, Yellow )

DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE ( SGG::UnitTests, Mood, uint16_t, Calm, Angry )

namespace SGG::UnitTests
{
   TEST ( SGG_Utils_StringEnum, General )
   {
      using namespace SGG::Utils::Enum;

      Color const color{ Color::Red };
      EXPECT_EQ ( toString ( color ), L"Red" );

      auto parsed = parse< Color > ( L"Yellow" );
      EXPECT_TRUE ( parsed.first );
      EXPECT_EQ ( parsed.second, Color::Yellow );

      EXPECT_EQ ( numValues< Mood > (), 2 );

      EXPECT_EQ ( typeName< Mood > (), L"Mood" );

      uint32_t numVals{ 0 };
      forEachValue< Color > ( [&numVals]( Color i_Color ) { ++numVals; } );
      EXPECT_EQ ( numVals, 3 );

      std::ostringstream oss;
      oss << Mood::Angry;
      EXPECT_EQ ( oss.str (), L"Angry" );
   }
}
