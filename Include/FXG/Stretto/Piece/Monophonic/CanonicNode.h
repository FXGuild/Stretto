/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class CanonicNode
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/CanonicNote.h>

namespace FXG::Stretto::Piece::Monophonic
{
   class CanonicNode final
   {
   public:
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/

      enum class Type
      {
         STARTING_NOTE,
         TIED_NOTE,
         REST
      };


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicNode(Theory::CanonicNote const & a_Note, bool a_IsTied) noexcept;
      CanonicNode(Theory::NoteDuration a_RestDuration) noexcept;
      CanonicNode(CanonicNode const &) noexcept = default;
      CanonicNode(CanonicNode &&) noexcept      = default;
      ~CanonicNode() noexcept                   = default;

      CanonicNode & operator=(CanonicNode const &) noexcept = default;
      CanonicNode & operator=(CanonicNode &&) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Theory::CanonicNote const & getNote() const;
      Theory::NoteDuration        getDuration() const;
      Type                        getType() const;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool isRest() const;

   private:
      Theory::CanonicNote m_Note;
      Type                m_Type;
   };
}
