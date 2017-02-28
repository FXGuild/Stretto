/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Quality
\**************************************************************************************************/

#pragma once

#include <stdint.h>

#include <FXG/Stretto/Theory/ImperfectQuality.h>
#include <FXG/Stretto/Theory/PerfectQuality.h>

namespace FXG::Stretto::Theory
{
   class Quality final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      // Voluntarily non-explicit
      Quality(ImperfectQuality a_ImperfectQuality) noexcept;
      // Voluntarily non-explicit
      Quality(PerfectQuality a_PerfectQuality) noexcept;
      Quality(Quality const &) noexcept = default;
      Quality(Quality &&) noexcept      = default;
      ~Quality() noexcept               = default;

      Quality & operator=(Quality const &) noexcept = default;
      Quality & operator=(Quality &&) noexcept = default;

      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      ImperfectQuality getImperfectQuality() const;
      PerfectQuality   getPerfectQuality() const;

      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool isImperfect() const;
      bool isPerfect() const;

   private:
      uint8_t m_Quality;
   };
}
