/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class Piece
\**************************************************************************************************/

#pragma once

#include <vector>

#include <FXG/Stretto/Piece/Monophonic/Part.h>
#include <FXG/Stretto/Utils/ClassDeclHelpers.h>

namespace FXG::Stretto::Piece::Monophonic
{
   class Piece final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Piece() noexcept         = default;
      Piece(Piece const &)     = default;
      Piece(Piece &&) noexcept = default;
      ~Piece() noexcept        = default;

      Piece & operator=(Piece const &) = default;
      Piece & operator=(Piece &&) noexcept = default;

      /************************************************************************/
      /* Add                                                                  */
      /************************************************************************/

      void addPart(Part && a_Part);

   private:
      std::vector<Part> m_Parts;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON(m_Parts)
   };
}
