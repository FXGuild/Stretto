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
   class CanonicNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicNote(Pitch const & a_Pitch, NoteDuration a_Duration) noexcept;
      CanonicNote(CanonicNote const &) noexcept = default;
      CanonicNote(CanonicNote &&) noexcept      = default;
      ~CanonicNote() noexcept                   = default;

      CanonicNote & operator=(CanonicNote const &) noexcept = default;
      CanonicNote & operator=(CanonicNote &&) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const &        getPitch() const;
      NoteDuration const & getDuration() const;
      uint64_t getDurationTU(NoteDuration a_DurationUnit) const;

   private:
      Pitch        m_Pitch;
      NoteDuration m_Duration;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, CanonicNote const & a_Note);
}
