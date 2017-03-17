/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 12, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Interval
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Theory/Interval.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Interval::Interval(Direction a_Direction, Quality a_Quality, Number a_Number) noexcept
   : m_Direction{ a_Direction }
   , m_Quality{ a_Quality }
   , m_Number{ a_Number }
   {
      // Prevent things like a minor fourth or perfect third
      assert(a_Quality.getQualityType() == associatedQualityType(a_Number));

      // Perfect unisons must be ascending
      assert(!(m_Number == Number::UNISON && m_Direction == Direction::DESCENDING &&
               m_Quality == Quality{ PerfAugDimQuality::PERFECT }));
   }

   Interval::Interval(Quality a_Quality, Number a_Number) noexcept
   : Interval{ Direction::ASCENDING, a_Quality, a_Number }
   {
   }

   Interval::Interval(Number a_Number) noexcept
   : Interval{ PerfAugDimQuality::PERFECT, a_Number }
   {
      assert(associatedQualityType(a_Number) == Quality::Type::PERF_AUG_DIM);
   }


   /************************************************************************/
   /* Comparison operators                                                 */
   /************************************************************************/

   bool Interval::operator==(Interval const & a_RHS) const
   {
      return m_Number == a_RHS.m_Number && m_Quality == a_RHS.m_Quality &&
             m_Direction == a_RHS.m_Direction;
   }

   bool Interval::operator!=(Interval const & a_RHS) const
   {
      return !(*this == a_RHS);
   }

   bool Interval::operator<(Interval const & a_RHS) const
   {
      if (m_Direction != a_RHS.m_Direction)
      {
         return m_Direction == Direction::DESCENDING;
      }

      if (m_Number != a_RHS.m_Number)
      {
         return m_Number < a_RHS.m_Number;
      }

      if (m_Quality.getQualityType() == Quality::Type::IMPERFECT)
      {
         return m_Quality.getImperfectQuality() < a_RHS.m_Quality.getImperfectQuality();
      }
      else
      {
         return m_Quality.getPerfAugDimQuality() < a_RHS.m_Quality.getPerfAugDimQuality();
      }
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Interval::Direction Interval::getDirection() const
   {
      return m_Direction;
   }

   Quality Interval::getQuality() const
   {
      return m_Quality;
   }

   Interval::Number Interval::getNumber() const
   {
      return m_Number;
   }


   /************************************************************************/
   /* Utilities                                                            */
   /************************************************************************/

   Interval::Number normalize(Interval::Number a_Number)
   {
      return Interval::Number(static_cast<uint8_t>(a_Number) % 7);
   }

   Quality::Type associatedQualityType(Interval::Number a_Number)
   {
      Interval::Number normalized{ normalize(a_Number) };
      return normalized == Interval::Number::UNISON || normalized == Interval::Number::FOURTH ||
                   normalized == Interval::Number::FIFTH
                ? Quality::Type::PERF_AUG_DIM
                : Quality::Type::IMPERFECT;
   }

   Result computeInterval(Pitch const & a_From, Pitch const & a_To)
   {

   }
}
