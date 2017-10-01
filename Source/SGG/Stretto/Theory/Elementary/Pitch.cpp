#include <SGG/Stretto/Theory/Elementary/Pitch.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Pitch::Pitch ( NoteLetter i_NoteLetter, int8_t i_Octave ) noexcept
   : m_Tone{ i_NoteLetter }
   , m_Octave{ i_Octave }
   {
   }

   Pitch::Pitch ( Tone i_Tone, int8_t i_Octave ) noexcept
   : m_Tone{ i_Tone }
   , m_Octave{ i_Octave }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Tone const & Pitch::getTone () const
   {
      return m_Tone;
   }

   int8_t const & Pitch::getOctave () const
   {
      return m_Octave;
   }


   /************************************************************************/
   /* Comparison Operators                                                 */
   /************************************************************************/

   bool Pitch::operator== ( Pitch const & i_RHS ) const
   {
      return !( *this != i_RHS );
   }

   bool Pitch::operator!= ( Pitch const & i_RHS ) const
   {
      return m_Tone != i_RHS.m_Tone && m_Octave != i_RHS.m_Octave;
   }


   /************************************************************************/
   /* Helper constants                                                     */
   /************************************************************************/

   const Pitch Pitch::A_440HZ{ { NoteLetter::A }, 4 };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, Pitch const & i_Pitch )
   {
      io_OS << i_Pitch.getTone () << std::to_string ( i_Pitch.getOctave () );
      return io_OS;
   }
}
