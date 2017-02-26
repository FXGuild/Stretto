/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece
 Content   : class MonophonicPiece
\**************************************************************************************************/

#pragma once

#include <vector>

#include <FXG/Stretto/Piece/MonophonicPart.h>
#include <FXG/Stretto/Utils/ClassDeclHelpers.h>

namespace FXG::Stretto::Piece
{
   class MonophonicPiece final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MonophonicPiece() noexcept                   = default;
      MonophonicPiece(MonophonicPiece const &)     = default;
      MonophonicPiece(MonophonicPiece &&) noexcept = default;
      ~MonophonicPiece() noexcept                  = default;

      MonophonicPiece & operator=(MonophonicPiece const &) = default;
      MonophonicPiece & operator=(MonophonicPiece &&) noexcept = default;

   private:
      std::vector<MonophonicPart> m_Parts;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON(m_Parts)
   };
}
