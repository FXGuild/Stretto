/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : Utility methods for NoteDuration
\**************************************************************************************************/

#include <FXG/Stretto/Theory/NoteDuration.h>

namespace FXG::Stretto::Theory
{
   uint32_t CountSubDurations(NoteDuration a_DurationToDivide, NoteDuration a_SubDuration)
   {
      uint8_t subDur  = static_cast<uint8_t>(a_SubDuration);
      uint8_t dur2Div = static_cast<uint8_t>(a_DurationToDivide);
      int8_t  delta   = subDur - dur2Div;
      return delta >= 0 ? 1 << delta : 0;
   }
}
