/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Elementary/Accidental.h>
#include <SGG/Stretto/Theory/Elementary/NoteLetter.h>

namespace SGG::Stretto::Theory
{
   class Tone final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Tone ( NoteLetter i_NoteLetter, Accidental i_Accidental = Accidental::NATURAL ) noexcept;
      Tone ( Tone const & ) noexcept = default;
      Tone ( Tone && ) noexcept      = default;
      ~Tone () noexcept              = default;

      Tone & operator= ( Tone const & ) noexcept = default;
      Tone & operator= ( Tone && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      NoteLetter getNoteLetter () const;
      Accidental getAccidental () const;


      /************************************************************************/
      /* Comparison Operators                                                 */
      /************************************************************************/

      bool operator== ( Tone const & i_RHS ) const;
      bool operator!= ( Tone const & i_RHS ) const;

   private:
      NoteLetter m_NoteLetter : 3;
      Accidental m_Accidental : 2;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, Tone const & i_Tone );
}
