/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : Class Quality
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Theory/Quality.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Quality::Quality(ImperfectQuality a_ImperfectQuality) noexcept
   : m_Quality{ static_cast<uint8_t>(a_ImperfectQuality) }
   {
   }

   Quality::Quality(PerfAugDimQuality a_PerfAugDimQuality) noexcept
   : m_Quality{ static_cast<uint8_t>(a_PerfAugDimQuality) }
   {
   }


   /************************************************************************/
   /* Comparison operators                                                 */
   /************************************************************************/

   bool Quality::operator==(Quality const & a_RHS) const
   {
      return m_Quality == a_RHS.m_Quality;
   }

   bool Quality::operator!=(Quality const & a_RHS) const
   {
      return !(*this == a_RHS);
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   ImperfectQuality Quality::getImperfectQuality() const
   {
      assert(getQualityType() == Type::IMPERFECT);
      return ImperfectQuality(m_Quality);
   }

   PerfAugDimQuality Quality::getPerfAugDimQuality() const
   {
      assert(getQualityType() == Type::PERF_AUG_DIM);
      return PerfAugDimQuality(m_Quality);
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   Quality::Type Quality::getQualityType() const
   {
      return m_Quality <= static_cast<uint8_t>(ImperfectQuality::MAJOR) ? Type::IMPERFECT
                                                                        : Type::PERF_AUG_DIM;
   }
}
