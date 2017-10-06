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

#include <iostream>

namespace SGG::Stretto
{
   using TimeUnit = uint32_t;
}

namespace SGG::Stretto::Theory
{
   enum class NoteDuration : uint8_t
   {
      WHOLE,
      HALF,
      QUARTER,
      EIGHT,
      SIXTEENTH,
      THIRTYSECOND,
      SIXTYFOURTH
   };

   /************************************************************************/
   /* Conversions                                                          */
   /************************************************************************/

   TimeUnit convertDurationToTimeunit ( NoteDuration i_Duration, NoteDuration i_DurationUnit );


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, NoteDuration const & i_Note );
}
