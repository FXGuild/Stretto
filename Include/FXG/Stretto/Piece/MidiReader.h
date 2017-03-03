/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 2, 2017
 Namespace : FXG::Stretto::Piece
 Content   : Function for reading a piece
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Piece/Monophonic/Piece.h>

namespace FXG::Stretto::Piece
{
   Monophonic::Piece read(std::string const & a_FilePath);
}
