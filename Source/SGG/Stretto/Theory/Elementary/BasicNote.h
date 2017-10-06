/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : October 1, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Elementary/NoteDuration.h>
#include <SGG/Stretto/Theory/Elementary/Pitch.h>

namespace SGG::Stretto::Theory
{
   class BasicNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      BasicNote ( Pitch const & i_Pitch, TimeUnit const i_Duration ) noexcept;
      BasicNote ( BasicNote const & ) noexcept = default;
      BasicNote ( BasicNote && ) noexcept      = default;
      ~BasicNote () noexcept                   = default;

      BasicNote & operator= ( BasicNote const & ) noexcept = default;
      BasicNote & operator= ( BasicNote && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const & getPitch () const;
      uint32_t      getDurationTU () const;

   private:
      Pitch    m_Pitch;
      TimeUnit m_Duration;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, BasicNote const & i_Note );
}
