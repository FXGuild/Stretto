/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 27, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Piece/Part.h>

namespace SGG::Stretto::Theory
{
   class PartBuilder final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      PartBuilder ( Theory::NoteDuration i_DurationUnit ) noexcept;
      PartBuilder ( PartBuilder const & )     = default;
      PartBuilder ( PartBuilder && ) noexcept = default;
      ~PartBuilder () noexcept                = default;

      PartBuilder & operator= ( PartBuilder const & ) = default;
      PartBuilder & operator= ( PartBuilder && ) noexcept = default;


      /************************************************************************/
      /* Builder methods                                                      */
      /************************************************************************/

      void addNote ( Theory::AggregatedNote const & i_Note );
      void addRest ( uint32_t i_DurationTU );

      Part build ();

   private:
      Part m_Part;
   };
}
