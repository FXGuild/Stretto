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
#include <FXG/Stretto/PluginAPI/IMDS.h>
#include <FXG/Stretto/PluginAPI/IPlugin.h>

namespace FXG::Stretto::BuiltinPlugin
{
   ////////////////////////////// DUMMY STUFF //////////////////////////////

   struct Note : public PluginAPI::IMDS
   {
      std::string note;
   };
   struct Bar : public PluginAPI::IMDS
   {
      std::vector<Note> notes;
   };
   struct Part : public PluginAPI::IMDS
   {
      std::vector<Bar> bars;
   };
   struct Piece : public PluginAPI::IMDS
   {
      std::vector<Part> parts;
   };

   static UPtrs<Part> extractPartsFromPiece(Piece const & a_Piece)
   {
      UPtrs<Part> parts;
      // for ( Part const & part : a_Piece.parts )
      {
         parts.emplace_back(std::make_unique<Part>());
      }
      return parts;
   }

   class BarCount final : public PluginAPI::IAnalysisProfile
   {
   };

   static std::unique_ptr<BarCount> countBars(Part const & a_Part)
   {
      return std::make_unique<BarCount>();
   }

   ////////////////////////////// DUMMY STUFF //////////////////////////////


   class BuiltinPlugin final : public PluginAPI::IPlugin
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      BuiltinPlugin() noexcept;
      BuiltinPlugin(BuiltinPlugin const &)     = default;
      BuiltinPlugin(BuiltinPlugin &&) noexcept = default;
      ~BuiltinPlugin() noexcept                = default;

      BuiltinPlugin & operator=(BuiltinPlugin const &) = default;
      BuiltinPlugin & operator=(BuiltinPlugin &&) noexcept = default;


   protected:
      /************************************************************************/
      /* Initialize                                                           */
      /************************************************************************/

      void createAnalysisModules() override;
      void createStructuralHierarchyLinks() override;
   };
}
