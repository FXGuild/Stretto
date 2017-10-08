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
#include <SGG/Stretto/Schema/StaticFragmentExtractionCheck.h>
#include <SGG/Utils/ConstexprUtils.h>
#include <SGG/Utils/StdAliases.h>

namespace SGG::Stretto::Schema
{
   template < typename THierarchyID, uint32_t... ranks >
   class Fragment final
   {
      static_assert ( sizeof...( ranks ) == HierarchyNumDimensions< THierarchyID >,
                      "Number of ranks is different than what the hierarchy describes" );

   public:
      using HierarchyID_t = THierarchyID;

      static constexpr uint32_t getNumDimension ()
      {
         return sizeof...( ranks );
      }

      static constexpr std::array< uint32_t, sizeof...( ranks ) > const getRanks ()
      {
         return { ranks... };
      }

      static constexpr uint32_t getRank ( size_t i_Dim )
      {
         return getRanks ()[ i_Dim ];
      }

      template < typename TSubFrag >
      Vec< TSubFrag > getSubFragments () const
      {
         using TThis = Fragment< HierarchyID_t, ranks... >;

         staticCheckIfValidFragmentConversion< TThis, TSubFrag > ();

         return {};
      }
   };
}
