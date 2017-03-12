/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 12, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Accidental
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Accidental.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Accidental const & a_Accidental)
   {
      if (a_Accidental == Accidental::FLAT)
      {
         a_OS << 'b';
      }
      else if (a_Accidental == Accidental::SHARP)
      {
         a_OS << '#';
      }
      else
      {
         a_OS << ' ';
      }
      return a_OS;
   }
}
