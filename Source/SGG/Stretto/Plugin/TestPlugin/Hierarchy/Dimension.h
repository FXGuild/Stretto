#pragma once

#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Plugin::TestPlugin
{
   struct HierarchyID_t;

   enum class Temporal
   {
      Piece,
      TempoSection,
      TimeSignatureSection,
      FullyAggregatedNote,
      Bar,
      InBarAggregatedNote,
      CanonicalNote,
      Timeunit
   };

   enum class Phonal
   {
      Piece,
      Part,
      Octave,
      Pitch
   };

   enum class Textural
   {
      Monophonic,
      Homophonic,
      Polyphonic
   };
}

namespace SGG::Stretto::Schema
{
   using namespace Plugin::TestPlugin;

   template <> struct DimensionType< HierarchyID_t, 0 > { using Type = Temporal; };
   template <> struct DimensionType< HierarchyID_t, 1 > { using Type = Phonal;   };
   template <> struct DimensionType< HierarchyID_t, 2 > { using Type = Textural; };

   // remplacer ça avec les string enums
   // encore mieux: vu que le nombre peux peut-être varier... ben faut etre clever
   template <> uint32_t const DimensionNumRanks< HierarchyID_t, 0 > = 8;
   template <> uint32_t const DimensionNumRanks< HierarchyID_t, 1 > = 4;
   template <> uint32_t const DimensionNumRanks< HierarchyID_t, 2 > = 3;
}
