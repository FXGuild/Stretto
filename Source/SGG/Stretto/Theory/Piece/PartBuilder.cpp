#include <SGG/Stretto/Theory/Piece/PartBuilder.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   PartBuilder::PartBuilder ( Theory::NoteDuration i_DurationUnit ) noexcept
   : m_Part{ i_DurationUnit }
   {
   }


   /************************************************************************/
   /* Builder methods                                                      */
   /************************************************************************/

   void PartBuilder::addNote ( Theory::AggregatedNote const & i_Note )
   {
      m_Part.m_AggregatedNodes.emplace_back ( i_Note );
      // TODO: canonic view
   }

   void PartBuilder::addRest ( uint32_t i_Duration )
   {
      m_Part.m_AggregatedNodes.emplace_back ( i_Duration );
      // TODO: canonic view
   }

   Part PartBuilder::build ()
   {
      Part output{ std::move ( m_Part ) };
      m_Part = { output.m_DurationUnit };
      return output;
   }
}
