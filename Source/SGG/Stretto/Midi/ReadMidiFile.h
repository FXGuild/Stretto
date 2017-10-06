/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 2, 2017
 Project     : Midi
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Midi/MidiPiece.h>
#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>
#include <SGG/Utils/Result.h>

namespace SGG::Stretto::Midi
{
   Result readMidiFile ( String const &       i_FilePath,
                         Theory::NoteDuration i_DurationUnit,
                         MidiPiece &          o_Piece );
}
