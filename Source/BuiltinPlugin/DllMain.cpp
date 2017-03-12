/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : March 11, 2017
Namespace : FXG::Stretto::BuiltinPlugin
Content   : Dll entry point
\**************************************************************************************************/

#include <wtypes.h>

#include <FXG/Stretto/BuiltinPlugin/Internal/BuiltinPlugin.h>
#include <FXG/Stretto/PluginAPI/DllAPI.h>

int WINAPI DllEntryPoint(HINSTANCE, unsigned long, void *)
{
   return 1;
}

namespace FXG::Stretto::PluginAPI
{
   STRETTO_PLUGIN_API IPlugin * CreatePluginClassInstance()
   {
      return new BuiltinPlugin::BuiltinPlugin();
   }
}
