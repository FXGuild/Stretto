/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 12, 2017
 Namespace : FXG::Stretto::Theory
 Content   : Unit tests for class Interval
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Theory/Interval.h>

namespace FXG::Stretto::Theory
{
   TEST(Theory_Interval, Constructors)
   {
      Interval i1{ Interval::Direction::ASCENDING, ImperfectQuality::MINOR,
                   Interval::Number::THIRD };
      Interval i2{ PerfAugDimQuality::AUGMENTED, Interval::Number::TWELVTH };
      Interval i3{ Interval::Number::FOURTH };

      EXPECT_DEATH(Interval i4{ Interval::Number::SIXTH }, ".");
      EXPECT_DEATH(Interval i5(PerfAugDimQuality::DIMINISHED, Interval::Number::SECOND), ".");
      EXPECT_DEATH(Interval i6(Interval::Direction::DESCENDING, PerfAugDimQuality::PERFECT,
                               Interval::Number::UNISON),
                   ".");
   }

   TEST(Theory_Interval, ComparisonOps)
   {
      Interval i1{ Interval::Direction::ASCENDING, ImperfectQuality::MAJOR,
                   Interval::Number::THIRD };
      Interval i2{ ImperfectQuality::MAJOR, Interval::Number::THIRD };
      Interval i3{ ImperfectQuality::MINOR, Interval::Number::THIRD };
      Interval i4{ ImperfectQuality::MAJOR, Interval::Number::SEVENTH };
      Interval i5{ Interval::Direction::DESCENDING, ImperfectQuality::MAJOR,
                   Interval::Number::SEVENTH };

      EXPECT_EQ(i1, i2);
      EXPECT_NE(i1, i3);
      EXPECT_LT(i3, i2);
      EXPECT_LT(i2, i4);
      EXPECT_LT(i5, i4);
   }

   TEST(Theory_Interval, Utilities_normalize)
   {
      Interval i1{ ImperfectQuality::MAJOR, Interval::Number::NINTH };
      Interval i2{ Interval::Number::OCTAVE };
      Interval i3{ Interval::Number::DOUBLE_OCTAVE };

      EXPECT_EQ(normalize(i1.getNumber()), Interval::Number::SECOND);
      EXPECT_EQ(normalize(i2.getNumber()), Interval::Number::UNISON);
      EXPECT_EQ(normalize(i3.getNumber()), Interval::Number::UNISON);
   }

   TEST(Theory_Interval, Utilities_associatedQualityTypeOf)
   {
      Interval i1{ ImperfectQuality::MAJOR, Interval::Number::NINTH };
      Interval i2{ Interval::Number::OCTAVE };

      EXPECT_EQ(associatedQualityType(i1.getNumber()), Quality::Type::IMPERFECT);
      EXPECT_EQ(associatedQualityType(i2.getNumber()), Quality::Type::PERF_AUG_DIM);
   }
}
