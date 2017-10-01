#include <SGG/Stretto/Theory/Elementary/CanonicNote.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   CanonicNote::CanonicNote ( Pitch const & i_Pitch, NoteDuration i_Duration ) noexcept
   : m_Pitch{ i_Pitch }
   , m_Duration{ i_Duration }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Pitch const & CanonicNote::getPitch () const
   {
      return m_Pitch;
   }

   NoteDuration const & CanonicNote::getDuration () const
   {
      return m_Duration;
   }

   uint64_t CanonicNote::getDurationTU ( NoteDuration i_DurationUnit ) const
   {
      return convertDurationToTU ( m_Duration, i_DurationUnit );
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, CanonicNote const & i_Note )
   {
      io_OS << i_Note.getPitch () << " " << i_Note.getDuration ();
      return io_OS;
   }
}
