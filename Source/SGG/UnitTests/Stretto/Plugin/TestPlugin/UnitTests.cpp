/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for TestPlugin.vcxproj
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Stretto/Plugin/TestPlugin/Hierarchy/Converter.h>
#include <SGG/Stretto/Plugin/TestPlugin/Hierarchy/Extractor.h>
#include <SGG/Stretto/Theory/Piece/Piece.h>

namespace SGG::UnitTests
{
   TEST ( SGG_Stretto_Plugin_TestPlugin, General )
   {
      using namespace SGG::Stretto;
      using namespace SGG::Stretto::Plugin::TestPlugin;

      // Theory
      UPtr< Theory::Piece > pTheoryPiece{ nullptr };

      // FragmentTypeInfo
      static_assert ( std::is_same_v< Bar::HierarchyID_t, HierarchyID_t > );
      static_assert ( Bar::getRank ( 1 ) == 1 );

      // convert
      Schema::Converter< HierarchyID_t > converter;
      UPtr< Piece >                      pPiece{ converter.convert ( *pTheoryPiece ) };

      // getSubFragments
      pPiece->getSubFragments< MonophonicNoteNode > ();
   }
}
