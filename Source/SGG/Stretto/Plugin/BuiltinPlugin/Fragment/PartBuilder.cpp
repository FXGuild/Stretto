//#include <SGG/Stretto/Theory/Track/PartBuilder.h>
//
//namespace SGG::Stretto::Theory
//{
//   /************************************************************************/
//   /* Constructors / Destructor / Assignment Operators                     */
//   /************************************************************************/
//
//   PartBuilder::PartBuilder ( Theory::NoteDuration i_DurationUnit ) noexcept
//   : m_Part{ i_DurationUnit }
//   {
//   }
//
//
//   /************************************************************************/
//   /* Builder methods                                                      */
//   /************************************************************************/
//
//   void PartBuilder::addNote ( Theory::AggregatedNote const & i_Note )
//   {
//      m_Part.m_AggregatedNodes.emplace_back ( i_Note );
//      // TODO_SGG: canonic view
//   }
//
//   void PartBuilder::addRest ( uint32_t i_Duration )
//   {
//      m_Part.m_AggregatedNodes.emplace_back ( i_Duration );
//      // TODO_SGG: canonic view
//   }
//
//   Part PartBuilder::build ()
//   {
//      Part output{ std::move ( m_Part ) };
//      m_Part = { output.m_DurationUnit };
//      return output;
//   }
//}
