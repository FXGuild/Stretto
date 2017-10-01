/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <vector>

#include <SGG/Stretto/Theory/Piece/Part.h>
#include <SGG/Utils/ClassDeclarationUtils.h>

namespace SGG::Stretto::Theory
{
   class Piece final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Piece ( Vec< Part > && io_Parts ) noexcept;
      Piece ( Piece const & )     = default;
      Piece ( Piece && ) noexcept = default;
      ~Piece () noexcept          = default;

      Piece & operator= ( Piece const & ) = default;
      Piece & operator= ( Piece && ) noexcept = default;

   private:
      Vec< Part > m_Parts;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON_CONTAINER ( m_Parts )
   };
}
