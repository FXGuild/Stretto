/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class Piece
\**************************************************************************************************/

#include <FXG/Stretto/Piece/Monophonic/Piece.h>

namespace FXG::Stretto::Piece::Monophonic
{
   /************************************************************************/
   /* Add                                                                  */
   /************************************************************************/

   void Piece::addPart(Part && a_Part)
   {
      m_Parts.emplace_back(std::move(a_Part));
   }
}
