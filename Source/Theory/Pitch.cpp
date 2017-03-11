/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Pitch
\**************************************************************************************************/

#include <FXG/Stretto/Theory/Pitch.h>

namespace FXG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Pitch::Pitch(Tone a_Tone, int8_t a_Octave) noexcept
   : m_Tone{ a_Tone }
   , m_Octave{ a_Octave }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Tone const & Pitch::getTone() const
   {
      return m_Tone;
   }

   int8_t const & Pitch::getOctave() const
   {
      return m_Octave;
   }


   /************************************************************************/
   /* Comparison Operators                                                 */
   /************************************************************************/

   bool Pitch::operator==(Pitch const & a_Other) const
   {
      return !(*this != a_Other);
   }

   bool Pitch::operator!=(Pitch const & a_Other) const
   {
      return m_Tone != a_Other.m_Tone && m_Octave != a_Other.m_Octave;
   }


   /************************************************************************/
   /* Helper constants                                                     */
   /************************************************************************/

   const Pitch Pitch::A_440HZ{ { NoteLetter::A }, 4 };
}
