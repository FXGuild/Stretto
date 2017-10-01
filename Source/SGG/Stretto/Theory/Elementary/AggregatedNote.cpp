#include <iomanip>

#include <SGG/Stretto/Theory/Elementary/AggregatedNote.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   AggregatedNote::AggregatedNote ( Pitch const & i_Pitch, uint32_t i_DurationTU ) noexcept
   : m_Pitch{ i_Pitch }
   , m_DurationTU{ i_DurationTU }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Pitch const & AggregatedNote::getPitch () const
   {
      return m_Pitch;
   }

   uint32_t AggregatedNote::getDurationTU () const
   {
      return m_DurationTU;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, AggregatedNote const & i_Note )
   {
      io_OS << i_Note.getPitch () << " " << i_Note.getDurationTU ();
      return io_OS;
   }
}
