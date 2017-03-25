/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class AggregatedNode
\**************************************************************************************************/

#pragma once

#include <iostream>

#include <FXG/Stretto/Theory/AggregatedNote.h>

namespace FXG::Stretto::Theory::Piece
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


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, AggregatedNode const & a_Node);
}
