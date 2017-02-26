/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license 
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : enum Accidental
\**************************************************************************************************/

#pragma once

#include <stdint.h>

namespace FXG::Stretto::Theory
{
   enum class Accidental : uint8_t
   {
      FLAT,
      NATURAL,
      SHARP
   };
}
