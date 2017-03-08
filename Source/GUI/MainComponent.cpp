/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainComponent
\**************************************************************************************************/

#include <FXG/Stretto/GUI/Internal/MainComponent.h>
#include <FXG/Stretto/Theory/NoteDuration.h>

namespace FXG::Stretto::GUI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   MainComponent::MainComponent()
   : juce::Component{}
   , m_MidiFileFilter{ "*mid;*midi", "", "Midi Files" }
   , m_FileBrowser{ nullptr }
   {
      using namespace FXG::Stretto::Theory;
      convertDurationToTU(NoteDuration::QUARTER, NoteDuration::SIXTYSECOND);

      addAndMakeVisible(
         m_FileBrowser = new juce::FileBrowserComponent{
            juce::FileBrowserComponent::openMode | juce::FileBrowserComponent::canSelectFiles,
            juce::File{}, &m_MidiFileFilter, nullptr });

      setSize(600, 400);
   }

   MainComponent::~MainComponent()
   {
      m_FileBrowser = nullptr;
   }


   /************************************************************************/
   /* GUI                                                                  */
   /************************************************************************/

   void MainComponent::paint(juce::Graphics & a_Graphics)
   {
      a_Graphics.fillAll(juce::Colour(0xffc1d0ff));
   }

   void MainComponent::resized()
   {
      m_FileBrowser->setBounds(0, 0, getWidth(), getHeight());
   }
}
