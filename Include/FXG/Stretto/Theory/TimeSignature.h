/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class TimeSignature
\**************************************************************************************************/

#pragma once

#include <stdint.h>

#include <FXG/Stretto/Theory/NoteDuration.h>

namespace FXG::Stretto::Theory
{
   class TimeSignature final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      TimeSignature(uint8_t m_Numerator, uint8_t m_DenominatorPower) noexcept;
      TimeSignature(TimeSignature const &) noexcept = default;
      TimeSignature(TimeSignature &&) noexcept      = default;
      ~TimeSignature() noexcept                     = default;

      TimeSignature & operator=(TimeSignature const &) noexcept = default;
      TimeSignature & operator=(TimeSignature &&) noexcept = default;

      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      uint32_t getNumTimeUnitsInABar(NoteDuration a_TimeUnitDuration) const;

   private:
      uint8_t m_Numerator;
      uint8_t m_DenominatorPower;
   };
}
