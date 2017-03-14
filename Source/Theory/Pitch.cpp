/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Pitch
\**************************************************************************************************/

#include <string>

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

   bool Pitch::operator==(Pitch const & a_RHS) const
   {
      return !(*this != a_RHS);
   }

   bool Pitch::operator!=(Pitch const & a_RHS) const
   {
      return m_Tone != a_RHS.m_Tone && m_Octave != a_RHS.m_Octave;
   }


   /************************************************************************/
   /* Helper constants                                                     */
   /************************************************************************/

   const Pitch Pitch::A_440HZ{ { NoteLetter::A }, 4 };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Pitch const & a_Pitch)
   {
      a_OS << a_Pitch.getTone() << std::to_string(a_Pitch.getOctave());
      return a_OS;
   }
}
