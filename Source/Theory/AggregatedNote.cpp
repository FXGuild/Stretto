/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class AggregatedNote
\**************************************************************************************************/

#include <FXG/Stretto/Theory/AggregatedNote.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   AggregatedNote::AggregatedNote(Pitch const & a_Pitch, uint32_t a_DurationTU) noexcept
   : m_Pitch{ a_Pitch }
   , m_DurationTU{ a_DurationTU }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Pitch const & AggregatedNote::getPitch() const
   {
      return m_Pitch;
   }

   uint32_t AggregatedNote::getDurationTU() const
   {
      return m_DurationTU;
   }
}
