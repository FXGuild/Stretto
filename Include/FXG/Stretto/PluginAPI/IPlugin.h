/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : March 11, 2017
Namespace : FXG::Stretto::PluginAPI
Content   : class interface IPlugin
\**************************************************************************************************/

#pragma once

namespace FXG::Stretto::PluginAPI
{
   class IPlugin
   {
   public:
      virtual ~IPlugin() noexcept = default;
      virtual void doStuff()      = 0;
   };
}
