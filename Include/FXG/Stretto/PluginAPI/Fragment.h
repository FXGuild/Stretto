/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : June 10, 2017
Namespace : FXG::Stretto::PluginAPI
Content   : template class Fragment
\**************************************************************************************************/

#include <array>
#include <stdint.h>
#include <type_traits>

#include <FXG/Stretto/Utils/ConstexprHelpers.h>

#pragma once

namespace FXG::Stretto::PluginAPI
{
   template < typename HierarchyID, uint32_t DimIdx >
   struct DimensionType;
 //{ 
 //   using Type = ?; 
 //}

   template < typename HierarchyID, uint32_t DimIdx >
   uint32_t const DimensionNumRanks;

   template < typename HierarchyID >
   struct Converter;
 //{
 //   std::unique_ptr< ? > convert( Piece const & a_Piece );
 //}

   template < typename HierarchyID, typename Dim, Dim SrcRank, Dim DestRank >
   struct Extractor;
 //{
 //   bool extract( Piece const & a_Piece );
 //}

   template < bool Cond >
   struct ExecuteExtractionFuncIf
   {
      template < uint32_t a_SrcRank, uint32_t a_DestRank, typename Func >
      constexpr void operator()( Func a_ExtractionFunc ) const
      {
         a_ExtractionFunc.operator()< a_SrcRank, a_DestRank >();
      }
   };

   template < >
   struct ExecuteExtractionFuncIf< false >
   {
      template < uint32_t a_SrcRank, uint32_t a_DestRank, typename Func >
      constexpr void operator()( Func ) const
      {

      }
   };
   
   template < typename HierarchyID, 
              uint32_t DimIdx, 
              uint32_t CurrRank, 
              uint32_t NextRank, 
              uint32_t MaxRank, 
              uint32_t DestRank >
      struct DimensionExtractionPathFinder
   {
      template < typename Func >
      constexpr bool operator()( Func a_ExtractionFunc ) const
      {
         if ( CurrRank == DestRank)
         {
            return true;
         }

         using Dim = typename DimensionType< HierarchyID, DimIdx >::Type;
         using isExtractionPossible =
            std::is_default_constructible< Extractor< HierarchyID,
                                                      Dim,
                                                      Dim(NextRank),
                                                      Dim(CurrRank) > >;

         if ( isExtractionPossible() )
         {
            if ( DimensionExtractionPathFinder< HierarchyID, 
                                                DimIdx, 
                                                NextRank, 
                                                0, 
                                                MaxRank, 
                                                DestRank >()( a_ExtractionFunc ) )
            {
               ExecuteExtractionFuncIf< isExtractionPossible() >()
                  .operator()< NextRank, CurrRank >( a_ExtractionFunc );
               return true;
            }
         }

         return DimensionExtractionPathFinder< HierarchyID, 
                                               DimIdx, 
                                               CurrRank, 
                                               NextRank + 1, 
                                               MaxRank, 
                                               DestRank >()( a_ExtractionFunc );
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
      constexpr bool operator()( Func a_ExtractionFunc ) const
      {
         return false;
      }
   };

   struct Dummy
   {
      template < uint32_t, uint32_t >
      constexpr void operator()() const {}
   };
   
   template < typename HierarchyID, uint32_t... Ranks >
   struct Fragment
   {
      using HierarchyID_t = HierarchyID;

      virtual ~Fragment() {};

      static constexpr std::array< uint32_t, sizeof...( Ranks ) > const getRanks()
      {
         return { Ranks... };
      }

      static constexpr uint32_t getRank( size_t a_Dim )
      {
         return getRanks()[ a_Dim ];
      }
      
   private:
      template < size_t DimIdx >
      struct Dummy2
      {
         template < uint32_t a_SrcRank, uint32_t a_DestRank >
         constexpr void operator()() const
         {
            using Dim = typename DimensionType< HierarchyID_t, DimIdx >::Type;
            Extractor< HierarchyID, Dim, Dim(a_SrcRank), Dim(a_DestRank) > extractor;
            FXG::Stretto::Piece::Monophonic::Piece piece;
            extractor.extract(piece);
         }
      };

      template < typename SubFrag >
      struct Dummy
      {
         template < size_t DimIdx >
         constexpr void operator()() const
         {
            DimensionExtractionPathFinder< HierarchyID_t,
                                           DimIdx,
                                           SubFrag::getRank(DimIdx),
                                           0,
                                           DimensionNumRanks< HierarchyID, DimIdx >,
                                           getRank(DimIdx) > depf;

            static_assert(depf(Dummy()), "");

            depf(Dummy2<DimIdx>());
         }
      };

   public:
      template < typename SubFrag >
      std::vector< SubFrag > getSubFragments() const
      {
         static_assert( std::is_same< HierarchyID_t, typename SubFrag::HierarchyID_t >::value, "" );

         Utils::for_each_static_index< 2 /* getNumDimension()*/ >( Dummy<SubFrag>() );

         return {};
      }
   };
   
}
