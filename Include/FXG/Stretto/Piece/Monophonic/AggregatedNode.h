/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class AggregatedNode
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/AggregatedNote.h>

namespace FXG::Stretto::Piece::Monophonic
{
   class AggregatedNode final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedNode(Theory::AggregatedNote const & a_Note) noexcept;
      AggregatedNode(uint32_t a_RestDuration) noexcept;
      AggregatedNode(AggregatedNode const &) noexcept = default;
      AggregatedNode(AggregatedNode &&) noexcept      = default;
      ~AggregatedNode() noexcept                      = default;

      AggregatedNode & operator=(AggregatedNode const &) noexcept = default;
      AggregatedNode & operator=(AggregatedNode &&) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Theory::AggregatedNote const & getNote() const;
      uint32_t                       getDurationTU() const;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool isRest() const;

   private:
      Theory::AggregatedNote m_Note;
      bool                   m_IsRest;
   };
}
