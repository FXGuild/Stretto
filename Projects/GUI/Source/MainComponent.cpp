// MIT License
//
// Copyright (c) 2017 FXGuild
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once

#include <FXG/Stretto/GUI/Internal/MainComponent.h>
#include <FXG/Stretto/Theory/NoteDuration.h>

namespace FXG {
namespace Stretto {
namespace GUI {

MainComponent::MainComponent()
: juce::Component{}
, m_MidiFileFilter{ "*mid;*midi", "", "Midi Files" }
, m_FileBrowser{ nullptr }
{
   using namespace FXG::Stretto::Theory;
   CountSubDurations(NoteDuration::QUARTER, NoteDuration::SIXTYSECOND);

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

void MainComponent::paint(juce::Graphics & a_Graphics)
{
   a_Graphics.fillAll(juce::Colour(0xffc1d0ff));
}

void MainComponent::resized()
{
   m_FileBrowser->setBounds(0, 0, getWidth(), getHeight());
}

}  // Namespace end
}
}
