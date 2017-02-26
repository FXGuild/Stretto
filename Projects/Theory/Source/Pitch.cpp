/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Pitch
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Pitch.h>

namespace FXG::Stretto::Theory
{
   Pitch::Pitch(Tone a_Tone, uint8_t a_Octave) noexcept
   : m_Tone{ a_Tone }
   , m_Octave{ a_Octave }
   {
   }

   Tone const & Pitch::getTone() const
   {
      return m_Tone;
   }

   uint8_t const & Pitch::getOctave() const
   {
      return m_Octave;
   }
}
