/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class Piece
\**************************************************************************************************/

#pragma once

#include <vector>

#include <FXG/Stretto/Theory/Piece/Part.h>
#include <FXG/Stretto/ClassDeclHelpers.h>

namespace FXG::Stretto::Theory::Piece
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
