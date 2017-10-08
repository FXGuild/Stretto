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

#include <SGG/Stretto/Schema/SchemaAPI.h>
#include <SGG/Utils/ConstexprUtils.h>

namespace SGG::Stretto::Schema
{
   namespace
   {
      template < typename THierarchyID,
                 uint32_t dimIdx,
                 uint32_t currRank,
                 uint32_t nextRank,
                 uint32_t maxRank,
                 uint32_t destRank >
      struct SCIVDCRecursive
      {
         constexpr bool operator() ()
         {
            if ( currRank == destRank )
            {
               return true;
            }

            using Dim     = DimensionInfo< THierarchyID, dimIdx >::Type;
            using Extract = Extractor< THierarchyID, Dim, Dim ( nextRank ), Dim ( currRank ) >;

            if constexpr ( Utils::is_defined< Extract >::value )
            {
               if ( SCIVDCRecursive< THierarchyID, dimIdx, nextRank, 0, maxRank, destRank > () () )
               {
                  return true;
               }
            }

            return SCIVDCRecursive< THierarchyID, dimIdx, currRank, nextRank + 1, maxRank,
                                    destRank > () ();
         }
      };

      template < typename THierarchyID,
                 uint32_t dimIdx,
                 uint32_t currRank,
                 uint32_t maxRank,
                 uint32_t destRank >
      struct SCIVDCRecursive< THierarchyID, dimIdx, currRank, maxRank, maxRank, destRank >
      {
         constexpr bool operator() ()
         {
            return false;
         }
      };

      template < typename TFragA, typename TFragB >
      struct StaticCheckIfValidDimensionConversion
      {
         template < size_t dimIdx >
         void operator() ()
         {
            static_assert (
               SCIVDCRecursive< TFragA::HierarchyID_t, dimIdx, TFragB::getRank ( dimIdx ), 0,
                                DimensionInfo< TFragA::HierarchyID_t, dimIdx >::NumRanks,
                                TFragA::getRank ( dimIdx ) > () (),
               // TODO_SGG better assert msg
               "Invalid fragment conversion" );
         }
      };
   }

   template < typename TFragA, typename TFragB >
   constexpr void staticCheckIfValidFragmentConversion ()
   {
      static_assert ( std::is_same_v< TFragA::HierarchyID_t, TFragB::HierarchyID_t >,
                      "Sub-fragment type must be in the same hierarchy as the current fragment" );

      // TODO_SGG Use templated lambda when available in MSVC++
      Utils::for_each_compile_time_index< HierarchyNumDimensions< TFragA::HierarchyID_t > > (
         StaticCheckIfValidDimensionConversion< TFragA, TFragB > () );
   }
}
