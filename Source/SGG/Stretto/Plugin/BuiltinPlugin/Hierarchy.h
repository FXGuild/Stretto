#pragma once

#include <SGG/Stretto/Schema/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Plugin::BuiltinPlugin
{
   struct HierarchyID;

   enum class Instrumentation
   {
      FullEnsemble,
      MidiInstrumentFamily,
      MidiInstrument,
      Part
   };

   enum class Frequency
   {
      FullSpectrum,
      VoiceType,
      Octave,
      Pitch
   };

   enum class Time
   {
      Piece,
      Tempo,
      TimeSignature,
      MidiInstrument,
      Chord,
      Bar,
      InBarChord,
      NotationChord,
      TimeUnit
   };
   /*
   enum class Texture
   {
      Monophonic,
      Homophonic,
      Polyphonic
   };
   */
}

namespace SGG::Stretto::Schema
{
   using namespace Plugin::BuiltinPlugin;

   template <>
   uint32_t const HierarchyNumDimensions< HierarchyID > = 3;

   // TODO_SGG utiliser le nombre de valeur des StringEnum, sauf que si un jour on veut pouvoir
   // ajouter des ranks, va falloir etre plus clever que ca
   template <>
   struct DimensionInfo< HierarchyID, 0 >
   {
      using Type                     = Instrumentation;
      static uint32_t const NumRanks = 4;
   };

   template <>
   struct DimensionInfo< HierarchyID, 1 >
   {
      using Type                     = Frequency;
      static uint32_t const NumRanks = 4;
   };

   template <>
   struct DimensionInfo< HierarchyID, 2 >
   {
      using Type                     = Time;
      static uint32_t const NumRanks = 9;
   };
}

namespace SGG::Stretto::Plugin::BuiltinPlugin
{
   template < Instrumentation TInstr, Frequency TFreq, Time TTime >
   using BuiltinFragment = Schema::Fragment< HierarchyID,
                                             static_cast< uint32_t > ( TInstr ),
                                             static_cast< uint32_t > ( TFreq ),
                                             static_cast< uint32_t > ( TTime ) >;
}
