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

namespace FXG::Stretto::PluginAPI
{
   extern "C" STRETTO_PLUGIN_API IPlugin * CreatePluginClassInstance();
}
