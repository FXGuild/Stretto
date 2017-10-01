#pragma once

#include <SGG/Stretto/Plugin/TestPlugin/Hierarchy/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Schema
{
   using namespace Plugin::TestPlugin;

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Piece,
                     Temporal::TempoSection >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Piece", "TempoSection" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Piece,
                     Temporal::TimeSignatureSection >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Piece", "TimeSignatureSection" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Piece,
                     Temporal::FullyAggregatedNote >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Piece", "FullyAggregatedNote" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::TempoSection,
                     Temporal::Bar >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "TempoSection", "Bar" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::TimeSignatureSection,
                     Temporal::Bar >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "TimeSignatureSection", "Bar" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::FullyAggregatedNote,
                     Temporal::InBarAggregatedNote >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "FullyAggregatedNote", "InBarAggregatedNote" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Bar,
                     Temporal::InBarAggregatedNote >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Bar", "InBarAggregatedNote" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::InBarAggregatedNote,
                     Temporal::CanonicalNote >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "InBarAggregatedNote", "CanonicalNote" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::CanonicalNote,
                     Temporal::Timeunit >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "CanonicalNote", "Timeunit" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Phonal,
                     Phonal::Piece,
                     Phonal::Part >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Phonal", "Piece", "Part" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Phonal,
                     Phonal::Part,
                     Phonal::Octave >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Phonal", "Part", "Octave" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Phonal,
                     Phonal::Octave,
                     Phonal::Pitch >
   {
      bool extract( Theory::Piece const & i_Piece )
      {
         printf( "[%-8s] %-20s -> %s\n", "Phonal", "Octave", "Pitch" );
         return true;
      }
   };
}
