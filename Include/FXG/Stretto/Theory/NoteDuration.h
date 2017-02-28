/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : - enum NoteDuration
             - Utility methods for NoteDuration
\**************************************************************************************************/

#pragma once

#include <stdint.h>

namespace FXG::Stretto::Theory
{
   enum class NoteDuration : uint8_t
   {
      WHOLE,
      HALF,
      QUARTER,
      EIGHT,
      SIXTEENTH,
      THIRTYSECOND,
      SIXTYSECOND
   };

   uint32_t countSubDurations(NoteDuration a_DurationToDivide, NoteDuration a_SubDuration);
}
