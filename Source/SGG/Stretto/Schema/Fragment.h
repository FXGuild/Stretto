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
#include <SGG/Stretto/Theory/Piece/Piece.h>
#include <SGG/Utils/ConstexprUtils.h>

namespace SGG::Stretto::Schema
{
   /************************************************************************/
   /* getSubFragments()                                                    */
   /************************************************************************/

   namespace
   {
      template < typename HierarchyID,
                 uint32_t DimIdx,
                 uint32_t CurrRank,
                 uint32_t NextRank,
                 uint32_t MaxRank,
                 uint32_t DestRank >
      struct DimensionExtractionPathFinder
      {
         template < typename Func >
         constexpr bool operator() ( Func i_ExtractionFunc )
         {
            if ( CurrRank == DestRank )
            {
               return true;
            }

            using Dim = typename DimensionType< HierarchyID, DimIdx >::Type;

            if constexpr ( Utils::is_defined< Extractor< HierarchyID, Dim, Dim ( NextRank ),
                                                         Dim ( CurrRank ) > >::value )
            {
               if ( DimensionExtractionPathFinder< HierarchyID, DimIdx, NextRank, 0, MaxRank,
                                                   DestRank > () ( i_ExtractionFunc ) )
               {
                  i_ExtractionFunc.template operator()< NextRank, CurrRank > ();
                  return true;
               }
            }

            return DimensionExtractionPathFinder< HierarchyID, DimIdx, CurrRank, NextRank + 1,
                                                  MaxRank, DestRank > () ( i_ExtractionFunc );
         }
      };

      template < typename HierarchyID,
                 uint32_t DimIdx,
                 uint32_t CurrRank,
                 uint32_t MaxRank,
                 uint32_t DestRank >
      struct DimensionExtractionPathFinder< HierarchyID,
                                            DimIdx,
                                            CurrRank,
                                            MaxRank,
                                            MaxRank,
                                            DestRank >
      {
         template < typename Func >
         constexpr bool operator() ( Func i_ExtractionFunc )
         {
            return false;
         }
      };

      struct Dummy
      {
         template < uint32_t, uint32_t >
         constexpr void operator() ()
         {
         }
      };

      template < typename HierarchyID, typename Dim >
      struct NotDummy
      {
         explicit NotDummy ( const Theory::Piece & i_Piece )
         : m_Piece{ i_Piece }
         {
         }

         template < uint32_t i_SrcRank, uint32_t i_DestRank >
         constexpr void operator() ()
         {
            Extractor< HierarchyID, Dim, Dim ( i_SrcRank ), Dim ( i_DestRank ) > extractor;
            extractor.extract ( m_Piece );
         }

         const Theory::Piece & m_Piece;
      };

      template < typename SubFrag, typename HierarchyID, typename this_t >
      struct DigDug
      {
         explicit DigDug ( const Theory::Piece & i_Piece )
         : m_Piece{ i_Piece }
         {
         }

         template < size_t DimIdx >
         void operator() ()
         {
            DimensionExtractionPathFinder< HierarchyID_t, DimIdx, SubFrag::getRank ( DimIdx ), 0,
                                           DimensionNumRanks< HierarchyID, DimIdx >,
                                           this_t::getRank ( DimIdx ) >
               depf;

            static_assert ( depf ( Dummy () ) );

            using Dim = typename DimensionType< HierarchyID_t, DimIdx >::Type;
            depf ( NotDummy< HierarchyID, Dim > ( m_Piece ) );
         }

         const Theory::Piece & m_Piece;
      };
   }

   template < typename HierarchyID, uint32_t... Ranks >
   class Fragment
   {
   public:
      using HierarchyID_t = HierarchyID;

      virtual ~Fragment (){};

      static constexpr uint32_t getNumDimension ()
      {
         return sizeof...( Ranks );
      }

      static constexpr std::array< uint32_t, sizeof...( Ranks ) > const getRanks ()
      {
         return { Ranks... };
      }

      static constexpr uint32_t getRank ( size_t i_Dim )
      {
         return getRanks ()[ i_Dim ];
      }

      template < typename SubFrag >
      std::vector< SubFrag > getSubFragments () const
      {
         using this_t = Fragment< HierarchyID_t, Ranks... >;

         static_assert ( std::is_same< HierarchyID_t, typename SubFrag::HierarchyID_t >::value );

         Theory::Piece piece{ {} };

         Utils::for_each_compile_time_index< getNumDimension () > (
            DigDug< SubFrag, HierarchyID_t, this_t > ( piece ) );

         return {};
      }
   };
}
