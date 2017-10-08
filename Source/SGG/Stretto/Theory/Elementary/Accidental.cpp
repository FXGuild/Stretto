#include <SGG/Stretto/Theory/Elementary/Accidental.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator<< ( std::wostream & i_OS, Accidental const & i_Accidental )
   {
      if ( i_Accidental == Accidental::FLAT )
      {
         i_OS << 'b';
      }
      else if ( i_Accidental == Accidental::SHARP )
      {
         i_OS << '#';
      }
      else
      {
         i_OS << ' ';
      }
      return i_OS;
   }
}
