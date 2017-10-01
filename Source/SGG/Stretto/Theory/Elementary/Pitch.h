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

#include <SGG/Stretto/Theory/Elementary/Tone.h>

namespace SGG::Stretto::Theory
{
   class Pitch final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Pitch ( NoteLetter i_NoteLetter, int8_t i_Octave ) noexcept;
      Pitch ( Tone i_Tone, int8_t i_Octave ) noexcept;
      Pitch ( Pitch const & ) noexcept = default;
      Pitch ( Pitch && ) noexcept      = default;
      ~Pitch () noexcept               = default;

      Pitch & operator= ( Pitch const & ) noexcept = default;
      Pitch & operator= ( Pitch && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Tone const &   getTone () const;
      int8_t const & getOctave () const;


      /************************************************************************/
      /* Comparison Operators                                                 */
      /************************************************************************/

      bool operator== ( Pitch const & i_RHS ) const;
      bool operator!= ( Pitch const & i_RHS ) const;


      /************************************************************************/
      /* Helper constants                                                     */
      /************************************************************************/

      static Pitch const A_440HZ;

   private:
      Tone   m_Tone;
      int8_t m_Octave;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, Pitch const & i_Pitch );
}
