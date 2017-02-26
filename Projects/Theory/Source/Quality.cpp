/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Quality
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Theory/Quality.h>

namespace FXG::Stretto::Theory
{
   Quality::Quality(ImperfectQuality a_ImperfectQuality) noexcept
   : m_Quality{ static_cast<uint8_t>(a_ImperfectQuality) }
   {
   }

   Quality::Quality(PerfectQuality a_PerfectQuality) noexcept
   : m_Quality{ static_cast<uint8_t>(a_PerfectQuality) }
   {
   }

   ImperfectQuality Quality::GetImperfectQuality() const
   {
      assert(IsImperfect());
      return ImperfectQuality(m_Quality);
   }

   PerfectQuality Quality::GetPerfectQuality() const
   {
      assert(IsPerfect());
      return PerfectQuality(m_Quality);
   }

   bool Quality::IsImperfect() const
   {
      return m_Quality <= static_cast<uint8_t>(ImperfectQuality::MAJOR);
   }

   bool Quality::IsPerfect() const
   {
      return !IsImperfect();
   }
}
