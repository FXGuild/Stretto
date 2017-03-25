/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Unit tests for plugin framework
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Analysis/PluginDllRAII.h>

namespace FXG::Stretto::Analysis
{
   TEST(Analysis_Plugin, General)
   {
      PluginDllRAII pluginDll{ "BuiltinPlugin.dll" };
      pluginDll.createPluginInstance();
   }
}
