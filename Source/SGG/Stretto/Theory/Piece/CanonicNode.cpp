#include <assert.h>

#include <SGG/Stretto/Theory/Piece/CanonicNode.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   CanonicNode::CanonicNode ( Theory::CanonicNote const & i_Note, bool i_IsTied ) noexcept
   : m_Note{ i_Note }
   , m_Type{ i_IsTied ? Type::TIED_NOTE : Type::STARTING_NOTE }
   {
   }

   CanonicNode::CanonicNode ( Theory::NoteDuration i_RestDuration ) noexcept
   : m_Note{ Theory::CanonicNote{ Theory::Pitch::A_440HZ, i_RestDuration } }
   , m_Type{ Type::REST }
   {
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   Theory::CanonicNote const & CanonicNode::getNote () const
   {
      assert ( !isRest () );
      return m_Note;
   }

   Theory::NoteDuration CanonicNode::getDuration () const
   {
      return m_Note.getDuration ();
   }

   CanonicNode::Type CanonicNode::getType () const
   {
      return m_Type;
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool CanonicNode::isRest () const
   {
      return m_Type == Type::REST;
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, CanonicNode const & i_Node )
   {
      if ( i_Node.getType () == CanonicNode::Type::REST )
      {
         io_OS << "Rest" << i_Node.getDuration ();
      }
      else if ( i_Node.getType () == CanonicNode::Type::STARTING_NOTE )
      {
         io_OS << '_' << i_Node.getNote ();
      }
      else
      {
         io_OS << i_Node.getNote ();
      }
      return io_OS;
   }
}
