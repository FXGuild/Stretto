/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : March 11, 2017
Namespace : FXG::Stretto::Analysis
Content   : Plugin utilities
\**************************************************************************************************/

#include <functional>

#include <FXG/Stretto/Analysis/PluginUtils.h>

namespace FXG::Stretto::Analysis
{
   PluginDllRAII::PluginDllRAII(std::string const & a_PluginName) noexcept 
   : juce::DynamicLibrary { a_PluginName }
   {}

   std::unique_ptr<PluginAPI::IPlugin> PluginDllRAII::createPluginInstance()
   {
      std::string const factoryFuncName = "CreatePluginClassInstance";
      auto factory = static_cast<PluginAPI::IPlugin *(*)()>(getFunction(factoryFuncName));
      if (factory == nullptr)
      {
         return nullptr;
      }
      return std::unique_ptr<PluginAPI::IPlugin>(factory());
   }
}
