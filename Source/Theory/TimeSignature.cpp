/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class TimeSignature
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Theory/TimeSignature.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   TimeSignature::TimeSignature(uint8_t m_Numerator, uint8_t m_DenominatorPower) noexcept
   : m_Numerator{ m_Numerator }
   , m_DenominatorPower{ m_DenominatorPower }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   uint32_t TimeSignature::getNumTimeUnitsInABar(NoteDuration a_TimeUnitDuration) const
   {
      uint32_t count = convertDurationToTU(NoteDuration(m_DenominatorPower), a_TimeUnitDuration);
      assert(count != 0);
      return m_Numerator * count;
   }


   /************************************************************************/
   /* Helper constants                                                     */
   /************************************************************************/

   TimeSignature const TimeSignature::STANDARD_4_4 { 4, 2 };
}