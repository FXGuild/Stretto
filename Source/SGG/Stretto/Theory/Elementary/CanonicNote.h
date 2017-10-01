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
   class CanonicNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicNote ( Pitch const & i_Pitch, NoteDuration i_Duration ) noexcept;
      CanonicNote ( CanonicNote const & ) noexcept = default;
      CanonicNote ( CanonicNote && ) noexcept      = default;
      ~CanonicNote () noexcept                     = default;

      CanonicNote & operator= ( CanonicNote const & ) noexcept = default;
      CanonicNote & operator= ( CanonicNote && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const &        getPitch () const;
      NoteDuration const & getDuration () const;
      uint64_t             getDurationTU ( NoteDuration i_DurationUnit ) const;

   private:
      Pitch        m_Pitch;
      NoteDuration m_Duration;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, CanonicNote const & i_Note );
}
