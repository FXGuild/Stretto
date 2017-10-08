/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : September 27, 2017
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <array>
#include <stdint.h>

namespace SGG::Stretto::Schema
{
   template < typename THierarchyID >
   uint32_t const HierarchyNumDimensions;

   template < typename THierarchyID, uint32_t dimIdx >
   struct DimensionInfo;
   // {
   //    using Type = ?;
   //    static uint32_t const NumRanks = ?;
   // };

   template < typename THierarchyID >
   struct Converter;
   // {
   //    std::unique_ptr< ? > convert( Theory::Piece const & i_Piece );
   // };

   template < typename THierarchyID, typename Dim, Dim SrcRank, Dim DestRank >
   struct Extractor;
   // {
   //    bool extract( Theory::Piece const & i_Piece );
   //
   //    TODO_SGG: signature of the extrat method depends on traits:
   //    TODO_SGG: trait that tells if output if contiguous
   //    TODO_SGG: trait that tells if output is continuous (no gaps)
   //
   // };
}
