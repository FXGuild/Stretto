/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainApplication
\**************************************************************************************************/

#pragma once

#include <JuceHeader.h>

#include <FXG/Stretto/GUI/Internal/MainWindow.h>

namespace FXG::Stretto::GUI
{
   class MainApplication final : public juce::JUCEApplication
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MainApplication()  = default;
      ~MainApplication() = default;

      /************************************************************************/
      /* Init / Shutdown                                                      */
      /************************************************************************/

      void initialise(const juce::String & a_CmdLine) override;
      void shutdown() override;

      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      juce::String const getApplicationName() override;
      juce::String const getApplicationVersion() override;

      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool moreThanOneInstanceAllowed() override;

   private:
      juce::ScopedPointer<MainWindow> m_MainWindow;

      JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainApplication)
   };
}
