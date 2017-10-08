#include <SGG/Stretto/Theory/Elementary/Tone.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Tone::Tone( NoteLetter i_NoteLetter, 
               Accidental i_Accidental /* = Accidental::NATURAL */ ) noexcept
   : m_NoteLetter { i_NoteLetter }
   , m_Accidental { i_Accidental }
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

   bool Tone::operator == ( Tone const & i_RHS ) const
   {
      return !( *this != i_RHS );
   }

   bool Tone::operator != ( Tone const & i_RHS ) const
   {
      return m_NoteLetter != i_RHS.m_NoteLetter && m_Accidental != i_RHS.m_Accidental;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator << ( std::wostream & io_OS, Tone const & i_Tone )
   {
      io_OS << Utils::Enum::toString( i_Tone.getNoteLetter() ) << i_Tone.getAccidental();
      return io_OS;
   }
}
