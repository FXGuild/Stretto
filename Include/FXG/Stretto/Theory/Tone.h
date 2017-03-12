/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Tone
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/Accidental.h>
#include <FXG/Stretto/Theory/NoteLetter.h>

namespace FXG::Stretto::Theory
{
   class Tone final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Tone(NoteLetter a_NoteLetter, Accidental a_Accidental = Accidental::NATURAL) noexcept;
      Tone(Tone const &) noexcept = default;
      Tone(Tone &&) noexcept      = default;
      ~Tone() noexcept            = default;

      Tone & operator=(Tone const &) noexcept = default;
      Tone & operator=(Tone &&) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      NoteLetter getNoteLetter() const;
      Accidental getAccidental() const;


      /************************************************************************/
      /* Comparison Operators                                                 */
      /************************************************************************/

      bool operator==(Tone const & a_Other) const;
      bool operator!=(Tone const & a_Other) const;

   private:
      NoteLetter m_NoteLetter : 3;
      Accidental m_Accidental : 2;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Tone const & a_Tone);
}
