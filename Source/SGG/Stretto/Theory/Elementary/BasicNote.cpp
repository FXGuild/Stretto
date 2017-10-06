#include <iomanip>

#include <SGG/Stretto/Theory/Elementary/BasicNote.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   BasicNote::BasicNote ( Pitch const & i_Pitch, TimeUnit const i_Duration ) noexcept
   : m_Pitch{ i_Pitch }
   , m_Duration{ i_Duration }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Pitch const & BasicNote::getPitch () const
   {
      return m_Pitch;
   }

   uint32_t BasicNote::getDurationTU () const
   {
      return m_Duration;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, BasicNote const & i_Note )
   {
      io_OS << i_Note.getPitch () << " " << i_Note.getDurationTU ();
      return io_OS;
   }
}
