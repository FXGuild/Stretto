#include <assert.h>

#include <SGG/Stretto/Theory/Elementary/Interval.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Interval::Interval ( Direction i_Direction, Quality i_Quality, Number i_Number ) noexcept
   : m_Direction{ i_Direction }
   , m_Quality{ i_Quality }
   , m_Number{ i_Number }
   {
      // Prevent things like a minor fourth or perfect third
      assert ( m_Quality.getQualityType () == associatedQualityType ( m_Number ) );

      // Perfect unisons must be ascending
      assert ( !( m_Number == Number::UNISON && m_Direction == Direction::DESCENDING &&
                  m_Quality == Quality{ PerfAugDimQuality::PERFECT } ) );
   }

   Interval::Interval ( Quality i_Quality, Number i_Number ) noexcept
   : Interval{ Direction::ASCENDING, i_Quality, i_Number }
   {
   }

   Interval::Interval ( Number i_Number ) noexcept
   : Interval{ PerfAugDimQuality::PERFECT, i_Number }
   {
      assert ( associatedQualityType ( i_Number ) == Quality::Type::PERF_AUG_DIM );
   }


   /************************************************************************/
   /* Comparison operators                                                 */
   /************************************************************************/

   bool Interval::operator== ( Interval const & i_RHS ) const
   {
      return m_Number == i_RHS.m_Number && m_Quality == i_RHS.m_Quality &&
             m_Direction == i_RHS.m_Direction;
   }

   bool Interval::operator!= ( Interval const & i_RHS ) const
   {
      return !( *this == i_RHS );
   }

   bool Interval::operator< ( Interval const & i_RHS ) const
   {
      if ( m_Direction != i_RHS.m_Direction )
      {
         return m_Direction == Direction::DESCENDING;
      }

      if ( m_Number != i_RHS.m_Number )
      {
         return m_Number < i_RHS.m_Number;
      }

      if ( m_Quality.getQualityType () == Quality::Type::IMPERFECT )
      {
         return m_Quality.getImperfectQuality () < i_RHS.m_Quality.getImperfectQuality ();
      }
      else
      {
         return m_Quality.getPerfAugDimQuality () < i_RHS.m_Quality.getPerfAugDimQuality ();
      }
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Interval::Direction Interval::getDirection () const
   {
      return m_Direction;
   }

   Quality Interval::getQuality () const
   {
      return m_Quality;
   }

   Interval::Number Interval::getNumber () const
   {
      return m_Number;
   }


   /************************************************************************/
   /* Utilities                                                            */
   /************************************************************************/

   Interval::Number normalize ( Interval::Number i_Number )
   {
      return Interval::Number ( static_cast< uint8_t > ( i_Number ) % 7 );
   }

   Quality::Type associatedQualityType ( Interval::Number i_Number )
   {
      Interval::Number normalized{ normalize ( i_Number ) };
      return normalized == Interval::Number::UNISON || normalized == Interval::Number::FOURTH ||
                   normalized == Interval::Number::FIFTH
                ? Quality::Type::PERF_AUG_DIM
                : Quality::Type::IMPERFECT;
   }
}
