/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 2, 2017
 Namespace : FXG::Stretto::Midi
 Content   : Function for reading a piece
\**************************************************************************************************/

#pragma once

#include <Juce/AudioBasics.h>

#include <FXG/Stretto/Piece/Monophonic/Piece.h>

namespace FXG::Stretto::Midi
{
   bool readMidiFile(juce::File const & a_File, juce::MidiFile & a_MidiFile);

   Piece::Monophonic::Piece buildMonophonicPiece(juce::MidiFile const & a_MidiFile,
                                                Theory::NoteDuration   a_DurationUnit);
}
