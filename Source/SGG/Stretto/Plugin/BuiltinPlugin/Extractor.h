#pragma once

#include <SGG/Stretto/Plugin/BuiltinPlugin/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Schema
{
   using namespace Plugin::BuiltinPlugin;

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Track,
                     Temporal::TempoSection >
   {
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Track", "TempoSection" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Track,
                     Temporal::TimeSignatureSection >
   {
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Track", "TimeSignatureSection" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::Track,
                     Temporal::FullyAggregatedNote >
   {
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "Track", "FullyAggregatedNote" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Temporal,
                     Temporal::TempoSection,
                     Temporal::Bar >
   {
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Temporal", "CanonicalNote", "Timeunit" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Phonal,
                     Phonal::Track,
                     Phonal::Part >
   {
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Phonal", "Track", "Part" );
         return true;
      }
   };

   template <>
   struct Extractor< HierarchyID_t,
                     Phonal,
                     Phonal::Part,
                     Phonal::Octave >
   {
      bool extract( Theory::Track const & i_Track )
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
      bool extract( Theory::Track const & i_Track )
      {
         printf( "[%-8s] %-20s -> %s\n", "Phonal", "Octave", "Pitch" );
         return true;
      }
   };
}
