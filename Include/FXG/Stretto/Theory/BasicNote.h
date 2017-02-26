/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class BasicNote
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/NoteDuration.h>
#include <FXG/Stretto/Theory/Pitch.h>

namespace FXG::Stretto::Theory
{
   class BasicNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      BasicNote(Pitch a_Pitch, NoteDuration a_Duration) noexcept;
      BasicNote(NoteLetter   a_NoteLetter,
                Accidental   a_Accidental,
                uint8_t      a_Octave,
                NoteDuration a_Duration) noexcept;
      BasicNote(BasicNote const &) noexcept = default;
      BasicNote(BasicNote &&) noexcept      = default;
      ~BasicNote() noexcept                 = default;

      BasicNote & operator=(BasicNote const &) noexcept = default;
      BasicNote & operator=(BasicNote &&) noexcept = default;

      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const &        getPitch() const;
      NoteDuration const & getDuration() const;

   private:
      Pitch        m_Pitch;
      NoteDuration m_Duration;
   };
}
