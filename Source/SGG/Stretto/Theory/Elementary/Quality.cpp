#include <assert.h>

#include <SGG/Stretto/Theory/Elementary/Quality.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Quality::Quality ( ImperfectQuality i_ImperfectQuality ) noexcept
   : m_Quality{ static_cast< uint8_t > ( i_ImperfectQuality ) }
   {
   }

   Quality::Quality ( PerfAugDimQuality i_PerfAugDimQuality ) noexcept
   : m_Quality{ static_cast< uint8_t > ( i_PerfAugDimQuality ) }
   {
   }


   /************************************************************************/
   /* Comparison operators                                                 */
   /************************************************************************/

   bool Quality::operator== ( Quality const & i_RHS ) const
   {
      return m_Quality == i_RHS.m_Quality;
   }

   bool Quality::operator!= ( Quality const & i_RHS ) const
   {
      return !( *this == i_RHS );
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   ImperfectQuality Quality::getImperfectQuality () const
   {
      assert ( getQualityType () == Type::IMPERFECT );
      return ImperfectQuality ( m_Quality );
   }

   PerfAugDimQuality Quality::getPerfAugDimQuality () const
   {
      assert ( getQualityType () == Type::PERF_AUG_DIM );
      return PerfAugDimQuality ( m_Quality );
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   Quality::Type Quality::getQualityType () const
   {
      return m_Quality <= static_cast< uint8_t > ( ImperfectQuality::MAJOR ) ? Type::IMPERFECT
                                                                             : Type::PERF_AUG_DIM;
   }
}
