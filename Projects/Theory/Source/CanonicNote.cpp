/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class BasicNote
\**************************************************************************************************/

#include <FXG/Stretto/Theory/CanonicNote.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   CanonicNote::CanonicNote(Pitch const & a_Pitch, NoteDuration a_Duration) noexcept
   : m_Pitch{ a_Pitch }
   , m_Duration{ a_Duration }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Pitch const & CanonicNote::getPitch() const
   {
      return m_Pitch;
   }

   NoteDuration const & CanonicNote::getDuration() const
   {
      return m_Duration;
   }

   uint64_t CanonicNote::getDurationTU(NoteDuration a_DurationUnit) const
   {
      return convertDurationToTU(m_Duration, a_DurationUnit);
   }
}
