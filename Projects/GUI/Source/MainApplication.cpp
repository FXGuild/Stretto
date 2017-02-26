/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainApplication
\**************************************************************************************************/

#include <FXG/Stretto/GUI/Internal/MainApplication.h>

namespace FXG::Stretto::GUI
{
   void MainApplication::initialise(const juce::String & /*a_CmdLine*/)
   {
      m_MainWindow = new MainWindow();
   }

   void MainApplication::shutdown()
   {
      m_MainWindow = nullptr;
   }

   juce::String const MainApplication::getApplicationName()
   {
      return "Hello World for JUCE";
   }

   juce::String const MainApplication::getApplicationVersion()
   {
      return "Implement me";
   }

   bool MainApplication::moreThanOneInstanceAllowed()
   {
      return true;
   }
}
