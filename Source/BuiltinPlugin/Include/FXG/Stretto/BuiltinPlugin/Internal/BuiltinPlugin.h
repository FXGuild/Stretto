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

#include <FXG/Stretto/PluginAPI/IPlugin.h>

namespace FXG::Stretto::BuiltinPlugin
{
   class BuiltinPlugin final : public PluginAPI::IPlugin
   {
   public:
      virtual ~BuiltinPlugin() noexcept = default;
      virtual void doStuff() override;
   };
}
