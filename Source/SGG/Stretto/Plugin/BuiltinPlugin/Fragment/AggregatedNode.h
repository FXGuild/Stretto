/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <iostream>

#include <SGG/Stretto/Theory/Elementary/AggregatedNote.h>

namespace SGG::Stretto::Theory
{
   class AggregatedNode final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedNode ( Theory::AggregatedNote const & i_Note ) noexcept;
      AggregatedNode ( uint32_t i_RestDuration ) noexcept;
      AggregatedNode ( AggregatedNode const & ) noexcept = default;
      AggregatedNode ( AggregatedNode && ) noexcept      = default;
      ~AggregatedNode () noexcept                        = default;

      AggregatedNode & operator= ( AggregatedNode const & ) noexcept = default;
      AggregatedNode & operator= ( AggregatedNode && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Theory::AggregatedNote const & getNote () const;
      uint32_t                       getDurationTU () const;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool isRest () const;

   private:
      Theory::AggregatedNote m_Note;
      bool                   m_IsRest;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, AggregatedNode const & i_Node );
}
