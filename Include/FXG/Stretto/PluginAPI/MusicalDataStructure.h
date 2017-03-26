/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Derivable class MusicalDataStructure
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/Piece/Piece.h>

namespace FXG::Stretto::PluginAPI
{
   // TODO: avec le member piece, on assume Sub-piece MDS
   class MusicalDataStructure
   {
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MusicalDataStructure(Theory::Piece::Piece const & a_CurrPiece) noexcept;
      ~MusicalDataStructure() noexcept = default;

   private:
      Theory::Piece::Piece const & m_CurrPiece;
   };
}
