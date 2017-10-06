/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : October 1, 2017
 Project     : Midi
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>

namespace SGG::Stretto::Midi
{
   template < typename T >
   class Event final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Event ( T & i_Event, TimeUnit i_Time )
      : m_Event{ i_Event }
      , m_Time{ i_Time }
      {
      }
      Event ( Event const & ) noexcept = default;
      Event ( Event && ) noexcept      = default;
      ~Event () noexcept               = default;

      Event & operator= ( Event const & ) noexcept = default;
      Event & operator= ( Event && ) noexcept = default;


      /************************************************************************/
      /* Comparison                                                           */
      /************************************************************************/

      bool operator< ( Event const & i_Rhs ) const
      {
         return m_Time < i_Rhs.m_Time;
      }

   private:
      T        m_Event;
      TimeUnit m_Time;
   };
}
