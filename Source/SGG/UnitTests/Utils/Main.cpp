/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 7, 2017
 Summary     : Entry point for unit tests
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

int main ( int i_Argc, char ** i_Argv )
{
   testing::InitGoogleTest ( &i_Argc, i_Argv );
   return RUN_ALL_TESTS ();
}
