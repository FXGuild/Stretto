#include <assert.h>
#include <sstream>

#include <SGG/Stretto/Theory/Track/AggregatedNode.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   AggregatedNode::AggregatedNode ( Theory::AggregatedNote const & i_Note ) noexcept
   : m_Note{ i_Note }
   , m_IsRest{ false }
   {
   }

   AggregatedNode::AggregatedNode ( uint32_t i_RestDuration ) noexcept
   : m_Note{ Theory::AggregatedNote{ Theory::Pitch::A_440HZ, i_RestDuration } }
   , m_IsRest{ true }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Theory::AggregatedNote const & AggregatedNode::getNote () const
   {
      assert ( !isRest () );
      return m_Note;
   }

   uint32_t AggregatedNode::getDurationTU () const
   {
      return m_Note.getDurationTU ();
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool AggregatedNode::isRest () const
   {
      return m_IsRest;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, AggregatedNode const & i_Node )
   {
      if ( i_Node.isRest () )
      {
         io_OS << "-R- " << i_Node.getDurationTU ();
      }
      else
      {
         io_OS << i_Node.getNote ();
      }
      return io_OS;
   }
}
