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
#include <FXG/Stretto/Midi/MidiReader.h>

namespace FXG::Stretto::GUI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   MainComponent::MainComponent()
   : juce::Component{}
   , m_FileChooser{ "Open MIDI file", juce::File(), "*.mid", true, false }
   , m_OpenFileButton{ "Open MIDI file", "Opens a file browser dialog for choosing a .mid file" }
   , m_FileNameLabel{ "File name label", "No file selected" }
   {
      addAndMakeVisible(m_OpenFileButton);
      addAndMakeVisible(m_FileNameLabel);

      m_OpenFileButton.addListener(this);

      setSize(600, 400);
   }

   MainComponent::~MainComponent()
   {
   }


   /************************************************************************/
   /* GUI appearance                                                       */
   /************************************************************************/

   void MainComponent::paint(juce::Graphics & a_Graphics)
   {
      a_Graphics.fillAll(juce::Colour(0xffc1d0ff));
   }

   void MainComponent::resized()
   {
      m_OpenFileButton.setBounds(10, 10, getWidth() - 20, 40);
      m_FileNameLabel.setBounds(10, 60, getWidth() - 20, 40);
   }


   /************************************************************************/
   /* GUI callbacks                                                        */
   /************************************************************************/

   void MainComponent::buttonClicked(juce::Button * a_Button)
   {
      // Open file browser
      if (!m_FileChooser.browseForFileToOpen())
      {
         m_FileNameLabel.setText("No file selected", juce::sendNotification);
         return;
      }

      // Get result
      juce::File file = m_FileChooser.getResult();

      // Read midi file content
      juce::MidiFile midiFile;
      if (!Midi::readMidiFile(file, midiFile))
      {
         m_FileNameLabel.setText("Invalid midi file", juce::sendNotification);
         return;
      }

      // Build monophonic piece structure
      Midi::buildMonophonicPiece(midiFile, Theory::NoteDuration::THIRTYSECOND);
      
      // Update label
      m_FileNameLabel.setText(file.getFileName(), juce::sendNotification);
   }
}
