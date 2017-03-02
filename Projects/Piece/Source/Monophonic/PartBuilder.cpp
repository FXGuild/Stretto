/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 27, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class PartBuilder
\**************************************************************************************************/

#include <FXG/Stretto/Piece/Monophonic/PartBuilder.h>

namespace FXG::Stretto::Piece::Monophonic
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   PartBuilder::PartBuilder(Theory::NoteDuration a_DurationUnit) noexcept
   : m_Part{ a_DurationUnit }
   {
   }


   /************************************************************************/
   /* Builder methods                                                      */
   /************************************************************************/

   void PartBuilder::addNote(Theory::AggregatedNote a_Note)
   {
      // TODO
   }

   void PartBuilder::addRest(uint32_t a_Duration)
   {
      // TODO
   }

   Part PartBuilder::build()
   {
      Part && output = std::move(m_Part);
      m_Part         = { output.m_DurationUnit };
      return output;
   }
}
