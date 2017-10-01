/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for SGGAlgorithms.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Utils/SGGAlgorithms.h>

namespace SGG::UnitTests
{
   TEST ( SGG_Utils_SGGAlgorithms, General )
   {
      std::vector< uint32_t > vec{ 3, 5, 6, 4 };

      std::vector< int32_t > derivative;

      Utils::for_each_overlapping_adjacent_pair (
         vec.cbegin (), vec.cend (),
         [&derivative]( uint32_t i_A, uint32_t i_B ) { derivative.emplace_back ( i_B - i_A ); } );

      std::vector< int32_t > expected{ 2, 1, -2 };

      EXPECT_EQ ( derivative, expected );
   }
}
