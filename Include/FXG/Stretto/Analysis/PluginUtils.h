/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : March 11, 2017
Namespace : FXG::Stretto::Analysis
Content   : Plugin utilities
\**************************************************************************************************/

#pragma once

#include <string>
#include <memory>

#include <JUCE/Core.h>

#include <FXG/Stretto/PluginAPI/IPlugin.h>

namespace FXG::Stretto::Analysis
{
   class PluginDllRAII final : private juce::DynamicLibrary
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      PluginDllRAII(std::string const & a_PluginName) noexcept;
      ~PluginDllRAII() noexcept = default;


      /************************************************************************/
      /* Factory methods                                                      */
      /************************************************************************/

      std::unique_ptr<PluginAPI::IPlugin> createPluginInstance();
   };
}
