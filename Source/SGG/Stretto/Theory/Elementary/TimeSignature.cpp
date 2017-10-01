#include <assert.h>

#include <SGG/Stretto/Theory/Elementary/TimeSignature.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   TimeSignature::TimeSignature ( uint8_t i_Numerator, uint8_t i_DenominatorPower ) noexcept
   : m_Numerator{ i_Numerator }
   , m_DenominatorPower{ i_DenominatorPower }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   uint32_t TimeSignature::getNumTimeUnitsInABar ( NoteDuration i_TimeUnitDuration ) const
   {
      uint32_t count =
         convertDurationToTU ( NoteDuration ( m_DenominatorPower ), i_TimeUnitDuration );
      assert ( count != 0 );
      return m_Numerator * count;
   }


   /************************************************************************/
   /* Helper constants                                                     */
   /************************************************************************/

   TimeSignature const TimeSignature::STANDARD_4_4{ 4, 2 };
}
