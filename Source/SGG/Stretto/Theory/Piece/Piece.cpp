#include <SGG/Stretto/Theory/Piece/Piece.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Piece::Piece ( Vec< Part > && io_Parts ) noexcept
   : m_Parts{ std::move ( io_Parts ) }
   {
   }
}
