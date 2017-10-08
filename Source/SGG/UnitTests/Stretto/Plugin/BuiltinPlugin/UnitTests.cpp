/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for BuiltinPlugin.vcxproj
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Stretto/Plugin/BuiltinPlugin/Extractor.h>
#include <SGG/Stretto/Plugin/BuiltinPlugin/Hierarchy.h>

namespace SGG::UnitTests
{
   using namespace Stretto::Schema;
   using namespace Stretto::Plugin::BuiltinPlugin;

   using Piece =
      BuiltinFragment< Instrumentation::FullEnsemble, Frequency::FullSpectrum, Time::Piece >;

   using SimpleTimeUnit =
      BuiltinFragment< Instrumentation::Part, Frequency::Pitch, Time::TimeUnit >;

   TEST ( SGG_Stretto_Plugin_BuiltinPlugin, General )
   {
      Piece piece;
      piece.getSubFragments< SimpleTimeUnit > ();
   }
}
