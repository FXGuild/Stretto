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

#include <stdint.h>

namespace SGG::Stretto::Schema
{
   template < typename HierarchyID, uint32_t DimIdx >
   uint32_t const DimensionNumRanks;

   template < typename HierarchyID, uint32_t DimIdx >
   struct DimensionType;
// {
//    using Type = ?;
// };

   template < typename HierarchyID >
   struct Converter;
// {
//    std::unique_ptr< ? > convert( Theory::Piece const & i_Piece );
// };

   template < typename HierarchyID, typename Dim, Dim SrcRank, Dim DestRank >
   struct Extractor;
// {
//    bool extract( Theory::Piece const & i_Piece );
// };
}
