/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 27, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class PartBuilder
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/Piece/Part.h>

namespace FXG::Stretto::Theory::Piece
{
   class PartBuilder final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      PartBuilder(Theory::NoteDuration a_DurationUnit) noexcept;
      PartBuilder(PartBuilder const &)     = default;
      PartBuilder(PartBuilder &&) noexcept = default;
      ~PartBuilder() noexcept              = default;

      PartBuilder & operator=(PartBuilder const &) = default;
      PartBuilder & operator=(PartBuilder &&) noexcept = default;


      /************************************************************************/
      /* Builder methods                                                      */
      /************************************************************************/

      void addNote(Theory::AggregatedNote const & a_Note);
      void addRest(uint32_t a_DurationTU);

      Part build();

   private:
      Part m_Part;
   };
}
