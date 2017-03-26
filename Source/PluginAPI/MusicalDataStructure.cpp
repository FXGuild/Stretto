/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Derivable class MusicalDataStructure
 \**************************************************************************************************/

#include <FXG/Stretto/PluginAPI/MusicalDataStructure.h>

namespace FXG::Stretto::PluginAPI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   MusicalDataStructure::MusicalDataStructure(Theory::Piece::Piece const & a_CurrPiece) noexcept
   : m_CurrPiece{ a_CurrPiece }
   {
   }
}
