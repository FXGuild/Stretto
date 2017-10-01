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

#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>
#include <SGG/Stretto/Theory/Elementary/Pitch.h>

namespace SGG::Stretto::Theory
{
   class AggregatedNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedNote ( Pitch const & i_Pitch, uint32_t i_DurationTU ) noexcept;
      AggregatedNote ( AggregatedNote const & ) noexcept = default;
      AggregatedNote ( AggregatedNote && ) noexcept      = default;
      ~AggregatedNote () noexcept                        = default;

      AggregatedNote & operator= ( AggregatedNote const & ) noexcept = default;
      AggregatedNote & operator= ( AggregatedNote && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const & getPitch () const;
      uint32_t      getDurationTU () const;

   private:
      Pitch    m_Pitch;
      uint32_t m_DurationTU;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, AggregatedNote const & i_Note );
}
