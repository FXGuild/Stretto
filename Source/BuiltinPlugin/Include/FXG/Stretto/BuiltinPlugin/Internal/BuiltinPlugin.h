/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::BuiltinPlugin
 Content   : class BuiltinPlugin
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/PluginAPI/IAnalysisProfile.h>
#include <FXG/Stretto/PluginAPI/IPlugin.h>

namespace FXG::Stretto::BuiltinPlugin
{
   std::string const BUILTIN_PIECE_HIERARCHY_NAME = "Builtin Piece";

   class BuiltinPlugin final : public PluginAPI::IPlugin
   {
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/
   public:
      enum class PieceHierarchyDim;
      enum class PieceHierarchyLayeringDimLevel;
      enum class PieceHierarchyTemporalDimLevel;
      enum class PieceHierarchyTexturalDimLevel;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/
   public:
      BuiltinPlugin() noexcept;


      /************************************************************************/
      /* Initialize                                                           */
      /************************************************************************/
   protected:
      void registerAnalysisModules() override;
      void createAndUpgradeStructualHierarchies(
         StringMap<PluginAPI::StructuralHierarchy> & a_Hierarchies) override;
   };


   /************************************************************************/
   /* Nested types                                                         */
   /************************************************************************/

   DECLARE_STRING_ENUM(BuiltinPlugin::PieceHierarchyDim, Layering, Temporal, Textural);
   DECLARE_STRING_ENUM(BuiltinPlugin::PieceHierarchyLayeringDimLevel, Piece, Part, Octave, Pitch);
   DECLARE_STRING_ENUM(BuiltinPlugin::PieceHierarchyTemporalDimLevel,
                       Piece,
                       FullyAggregatedStack,
                       TimeSignatureSection,
                       TempoSection,
                       Bar,
                       InBarAggregatedStack,
                       CanonicStack,
                       Slice);
   DECLARE_STRING_ENUM(BuiltinPlugin::PieceHierarchyTexturalDimLevel,
                       Monophonic,
                       ChordsOnly,
                       Freeform);
}
