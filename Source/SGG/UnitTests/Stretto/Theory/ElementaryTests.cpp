/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 12, 2017
 Summary     : Unit tests for files under Elementary/
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Stretto/Theory/Elementary/Accidental.h>
#include <SGG/Stretto/Theory/Elementary/Interval.h>
#include <SGG/Stretto/Theory/Elementary/NoteLetter.h>
#include <SGG/Stretto/Theory/Elementary/Quality.h>

namespace SGG::UnitTests
{
   using namespace Stretto::Theory;

   TEST ( SGG_Stretto_Theory_Elementary, Accidental )
   {
      std::wostringstream woss;
      woss << Accidental::SHARP;
      EXPECT_EQ ( woss.str (), L"#" );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Interval_Constructors )
   {
      Interval i1{ Interval::Direction::ASCENDING, ImperfectQuality::MINOR,
                   Interval::Number::THIRD };
      Interval i2{ PerfAugDimQuality::AUGMENTED, Interval::Number::TWELVTH };
      Interval i3{ Interval::Number::FOURTH };

      EXPECT_DEATH ( Interval i4{ Interval::Number::SIXTH }, "." );
      EXPECT_DEATH ( Interval i5 ( PerfAugDimQuality::DIMINISHED, Interval::Number::SECOND ), "." );
      EXPECT_DEATH ( Interval i6 ( Interval::Direction::DESCENDING, PerfAugDimQuality::PERFECT,
                                   Interval::Number::UNISON ),
                     "." );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Interval_ComparisonOps )
   {
      Interval i1{ Interval::Direction::ASCENDING, ImperfectQuality::MAJOR,
                   Interval::Number::THIRD };
      Interval i2{ ImperfectQuality::MAJOR, Interval::Number::THIRD };
      Interval i3{ ImperfectQuality::MINOR, Interval::Number::THIRD };
      Interval i4{ ImperfectQuality::MAJOR, Interval::Number::SEVENTH };
      Interval i5{ Interval::Direction::DESCENDING, ImperfectQuality::MAJOR,
                   Interval::Number::SEVENTH };

      EXPECT_EQ ( i1, i2 );
      EXPECT_NE ( i1, i3 );
      EXPECT_LT ( i3, i2 );
      EXPECT_LT ( i2, i4 );
      EXPECT_LT ( i5, i4 );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Interval_Utilities_Output )
   {
      std::wostringstream woss;
      woss << Utils::Enum::toString ( NoteLetter::G );
      EXPECT_EQ ( woss.str (), L"G" );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Interval_Utilities_normalize )
   {
      Interval i1{ ImperfectQuality::MAJOR, Interval::Number::NINTH };
      Interval i2{ Interval::Number::OCTAVE };
      Interval i3{ Interval::Number::DOUBLE_OCTAVE };

      EXPECT_EQ ( normalize ( i1.getNumber () ), Interval::Number::SECOND );
      EXPECT_EQ ( normalize ( i2.getNumber () ), Interval::Number::UNISON );
      EXPECT_EQ ( normalize ( i3.getNumber () ), Interval::Number::UNISON );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Interval_Utilities_associatedQualityTypeOf )
   {
      Interval i1{ ImperfectQuality::MAJOR, Interval::Number::NINTH };
      Interval i2{ Interval::Number::OCTAVE };

      EXPECT_EQ ( associatedQualityType ( i1.getNumber () ), Quality::Type::IMPERFECT );
      EXPECT_EQ ( associatedQualityType ( i2.getNumber () ), Quality::Type::PERF_AUG_DIM );
   }

   TEST ( SGG_Stretto_Theory_Elementary, Quality )
   {
      Quality q1{ ImperfectQuality::MAJOR };
      EXPECT_TRUE ( q1.getQualityType () == Quality::Type::IMPERFECT );
      EXPECT_EQ ( q1.getImperfectQuality (), ImperfectQuality::MAJOR );
      EXPECT_DEATH ( auto q = q1.getPerfAugDimQuality (), "." );

      Quality q2{ PerfAugDimQuality::DIMINISHED };
      EXPECT_TRUE ( q2.getQualityType () == Quality::Type::PERF_AUG_DIM );
      EXPECT_EQ ( q2.getPerfAugDimQuality (), PerfAugDimQuality::DIMINISHED );
      EXPECT_DEATH ( auto q = q2.getImperfectQuality (), "." );

      EXPECT_EQ ( q1, Quality{ ImperfectQuality::MAJOR } );
   }

   TEST ( SGG_Stretto_Theory_Elementary, NoteLetter )
   {
      std::wostringstream woss;
      woss << Utils::Enum::toString ( NoteLetter::G );
      EXPECT_EQ ( woss.str (), L"G" );
   }
}
