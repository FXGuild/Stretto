/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class Piece
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Piece/Piece.h>

namespace FXG::Stretto::Theory::Piece
{
   /************************************************************************/
   /* Add                                                                  */
   /************************************************************************/

   void Piece::addPart(Part && a_Part)
   {
      m_Parts.emplace_back(std::move(a_Part));
   }
}
