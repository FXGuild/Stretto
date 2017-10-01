/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for Result.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Utils/Result.h>

namespace SGG::UnitTests
{
   Result someSuccessfulFunction ()
   {
      return Result::ok ();
   }

   Result someBadFunction ()
   {
      return Result::fail ( L"Some problem" );
   }

   TEST ( SGG_Utils_Result, General )
   {
      EXPECT_TRUE ( someSuccessfulFunction ().IsSuccess () );
      EXPECT_TRUE ( !someBadFunction ().IsSuccess () );
   }
}
