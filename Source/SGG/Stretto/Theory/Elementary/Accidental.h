/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Project     : Theory
 Summary     : Flat (b), sharp (#) and natural accidentals
 Description : NA
\**************************************************************************************************/

#pragma once

#include <iostream>

namespace SGG::Stretto::Theory
{
   enum class Accidental : uint8_t
   {
      FLAT,
      NATURAL,
      SHARP
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & i_OS, Accidental const & i_Accidental );
}
