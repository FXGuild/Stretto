/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <stdint.h>

#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>

namespace SGG::Stretto::Theory
{
   class TimeSignature final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      TimeSignature ( uint8_t i_Numerator, uint8_t i_DenominatorPower ) noexcept;
      TimeSignature ( TimeSignature const & ) noexcept = default;
      TimeSignature ( TimeSignature && ) noexcept      = default;
      ~TimeSignature () noexcept                       = default;

      TimeSignature & operator= ( TimeSignature const & ) noexcept = default;
      TimeSignature & operator= ( TimeSignature && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      uint32_t getNumTimeUnitsInABar ( NoteDuration i_TimeUnitDuration ) const;


      /************************************************************************/
      /* Helper constants                                                     */
      /************************************************************************/

      static TimeSignature const STANDARD_4_4;

   private:
      uint8_t m_Numerator;
      uint8_t m_DenominatorPower;
   };
}
