/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Theory
 Content   : Unit tests for class Quality
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Theory/Quality.h>

namespace FXG::Stretto::Theory
{
   TEST(Theory_Quality, General)
   {
      Quality q1{ ImperfectQuality::MAJOR };
      EXPECT_TRUE(q1.isImperfect());
      EXPECT_EQ(q1.getImperfectQuality(), ImperfectQuality::MAJOR);
      EXPECT_DEATH(auto q = q1.getPerfectQuality(), ".");

      Quality q2{ PerfectQuality::DIMINISHED };
      EXPECT_TRUE(q2.isPerfect());
      EXPECT_EQ(q2.getPerfectQuality(), PerfectQuality::DIMINISHED);
      EXPECT_DEATH(auto q = q2.getImperfectQuality(), ".");
   }
}
