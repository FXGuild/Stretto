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
{
   using namespace FXG::Stretto::Theory;
   CountSubDurations(NoteDuration::QUARTER, NoteDuration::SIXTYSECOND);

   addAndMakeVisible(m_HelloWorldLabel = new juce::Label(juce::String(), "Stretto"));
   m_HelloWorldLabel->setFont(juce::Font(40.00f, juce::Font::bold));
   m_HelloWorldLabel->setJustificationType(juce::Justification::centred);
   m_HelloWorldLabel->setEditable(false, false, false);
   m_HelloWorldLabel->setColour(juce::Label::textColourId, juce::Colours::black);
   m_HelloWorldLabel->setColour(juce::TextEditor::textColourId, juce::Colours::black);
   m_HelloWorldLabel->setColour(juce::TextEditor::backgroundColourId, juce::Colour(0x00000000));

   setSize(600, 300);
}

MainComponent::~MainComponent()
{
   m_HelloWorldLabel = nullptr;
}

void MainComponent::paint(juce::Graphics & a_Graphics)
{
    a_Graphics.fillAll(juce::Colour(0xffc1d0ff));
}

void MainComponent::resized()
{
   m_HelloWorldLabel->setBounds(152, 80, 296, 48);
}

}  // Namespace end
}
}
