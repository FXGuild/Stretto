/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Tone
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Tone.h>

namespace FXG::Stretto::Theory
{
   Tone::Tone(NoteLetter a_NoteLetter, Accidental a_Accidental /* = Accidental::NATURAL */) noexcept
   : m_NoteLetter{ a_NoteLetter }
   , m_Accidental{ a_Accidental }
   {
   }

   NoteLetter Tone::getNoteLetter() const
   {
      return m_NoteLetter;
   }

   Accidental Tone::getAccidental() const
   {
      return m_Accidental;
   }
}
