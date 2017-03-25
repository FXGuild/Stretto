/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Dll api definitions
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/PluginAPI/IPlugin.h>

#ifdef _WINDLL
#define STRETTO_PLUGIN_API __declspec(dllexport)
#else
#define STRETTO_PLUGIN_API __declspec(dllimport)
#endif

// PluginDllRAII needs to know the name of the dlls entry point function
#define PLUGIN_FACTORY_FUNC_NAME CreatePluginClassInstance

namespace FXG::Stretto::PluginAPI
{
   extern "C" STRETTO_PLUGIN_API IPlugin * PLUGIN_FACTORY_FUNC_NAME();
}
