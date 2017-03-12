/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainComponent
\**************************************************************************************************/

#pragma once

#include <Juce/GUIBasic.h>

namespace FXG::Stretto::GUI
{
   class MainComponent final : public juce::Component, public juce::Button::Listener
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MainComponent();
      ~MainComponent();


      /************************************************************************/
      /* GUI appearance                                                       */
      /************************************************************************/

      void paint(juce::Graphics & a_Graphics) override;
      void resized() override;


      /************************************************************************/
      /* GUI callbacks                                                        */
      /************************************************************************/

      void buttonClicked(juce::Button * a_Button) override;

   private:
      juce::FileChooser m_FileChooser;
      juce::TextButton  m_OpenFileButton;
      juce::Label       m_FileNameLabel;

      JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
   };
}
