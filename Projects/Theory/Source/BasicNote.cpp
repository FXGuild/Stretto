/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class BasicNote
\**************************************************************************************************/

#include <FXG/Stretto/Theory/BasicNote.h>

namespace FXG::Stretto::Theory
{
   BasicNote::BasicNote(Pitch a_Pitch, NoteDuration a_Duration) noexcept
   : m_Pitch{ a_Pitch }
   , m_Duration{ a_Duration }
   {
   }

   BasicNote::BasicNote(NoteLetter   a_NoteLetter,
                        Accidental   a_Accidental,
                        uint8_t      a_Octave,
                        NoteDuration a_Duration) noexcept
   : m_Pitch{ Tone{ a_NoteLetter, a_Accidental }, a_Octave }
   , m_Duration{ a_Duration }
   {
   }

   Pitch const & BasicNote::getPitch() const
   {
      return m_Pitch;
   }

   NoteDuration const & BasicNote::getDuration() const
   {
      return m_Duration;
   }
}
