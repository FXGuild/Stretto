/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Tone
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Tone.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Tone::Tone(NoteLetter a_NoteLetter, Accidental a_Accidental /* = Accidental::NATURAL */) noexcept
   : m_NoteLetter{ a_NoteLetter }
   , m_Accidental{ a_Accidental }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   NoteLetter Tone::getNoteLetter() const
   {
      return m_NoteLetter;
   }

   Accidental Tone::getAccidental() const
   {
      return m_Accidental;
   }


   /************************************************************************/
   /* Comparison Operators                                                 */
   /************************************************************************/

   bool Tone::operator==(Tone const & a_Other) const
   {
      return !(*this != a_Other);
   }

   bool Tone::operator!=(Tone const & a_Other) const
   {
      return m_NoteLetter != a_Other.m_NoteLetter && m_Accidental != a_Other.m_Accidental;
   }
}
