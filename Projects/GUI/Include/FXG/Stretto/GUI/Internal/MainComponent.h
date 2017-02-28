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

#include <JuceHeader.h>

namespace FXG::Stretto::GUI
{
   class MainComponent final : public juce::Component
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MainComponent();
      ~MainComponent();


      /************************************************************************/
      /* GUI                                                                  */
      /************************************************************************/

      void paint(juce::Graphics & a_Graphics) override;
      void resized() override;

   private:
      juce::WildcardFileFilter                        m_MidiFileFilter;
      juce::ScopedPointer<juce::FileBrowserComponent> m_FileBrowser;

      JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
   };
}
