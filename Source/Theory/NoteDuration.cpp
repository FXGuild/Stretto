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
   /************************************************************************/
   /* Conversions                                                          */
   /************************************************************************/

   uint32_t convertDurationToTU(NoteDuration a_DurationToDivide, NoteDuration a_SubDuration)
   {
      uint8_t subDur  = static_cast<uint8_t>(a_SubDuration);
      uint8_t dur2Div = static_cast<uint8_t>(a_DurationToDivide);
      int8_t  delta   = subDur - dur2Div;
      return delta >= 0 ? 1 << delta : 0;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, NoteDuration const & a_Note)
   {
      switch (a_Note)
      {
      case NoteDuration::WHOLE: a_OS << 'w'; break;
      case NoteDuration::HALF: a_OS << 'h'; break;
      case NoteDuration::QUARTER: a_OS << 'q'; break;
      case NoteDuration::EIGHT: a_OS << 'e'; break;
      case NoteDuration::SIXTEENTH: a_OS << 's'; break;
      case NoteDuration::THIRTYSECOND: a_OS << 't'; break;
      case NoteDuration::SIXTYFOURTH: a_OS << 'x'; break;
      }
      return a_OS;
   }
}
