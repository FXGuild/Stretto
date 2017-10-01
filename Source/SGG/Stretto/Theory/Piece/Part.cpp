#include <assert.h>

#include <SGG/Stretto/Theory/Piece/Part.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::Part ( Theory::NoteDuration i_DurationUnit ) noexcept
   : m_AggregatedNodes{}
   , m_CanonicNodes{}
   , m_DurationUnit{ i_DurationUnit }
   {
   }


   /************************************************************************/
   /* Access views                                                         */
   /************************************************************************/

   Part::AggregatedView Part::aggregatedView () const
   {
      return { m_AggregatedNodes };
   }

   Part::CanonicView Part::canonicView () const
   {
      return { m_CanonicNodes };
   }


   /************************************************************************/
   /* AggregatedView                                                       */
   /************************************************************************/

   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::AggregatedView::AggregatedView ( std::vector< AggregatedNode > const & i_Nodes ) noexcept
   : m_Nodes{ i_Nodes }
   {
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, Part::AggregatedView const & i_View )
   {
      for ( auto const & node : i_View )
      {
         io_OS << node << std::endl;
      }
      return io_OS;
   }


   /************************************************************************/
   /* CanonicView                                                       */
   /************************************************************************/

   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::CanonicView::CanonicView ( std::vector< CanonicNode > const & i_Nodes ) noexcept
   : m_Nodes{ i_Nodes }
   {
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<< ( std::ostream & io_OS, Part::CanonicView const & i_View )
   {
      for ( auto const & node : i_View )
      {
         io_OS << node << std::endl;
      }
      return io_OS;
   }
}
