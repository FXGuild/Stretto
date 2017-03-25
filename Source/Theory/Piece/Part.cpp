/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class Part
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Theory/Piece/Part.h>

namespace FXG::Stretto::Theory::Piece
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::Part(Theory::NoteDuration a_DurationUnit) noexcept
   : m_AggregatedNodes{}
   , m_CanonicNodes{}
   , m_DurationUnit{ a_DurationUnit }
   {
   }


   /************************************************************************/
   /* Access views                                                         */
   /************************************************************************/

   Part::AggregatedView Part::aggregatedView() const
   {
      return { m_AggregatedNodes };
   }

   Part::CanonicView Part::canonicView() const
   {
      return { m_CanonicNodes };
   }


   /************************************************************************/
   /* AggregatedView                                                       */
   /************************************************************************/

   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::AggregatedView::AggregatedView(std::vector<AggregatedNode> const & a_Nodes) noexcept
   : m_Nodes{ a_Nodes }
   {
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Part::AggregatedView const & a_View)
   {
      for (auto const & node : a_View)
      {
         a_OS << node << std::endl;
      }
      return a_OS;
   }


   /************************************************************************/
   /* CanonicView                                                       */
   /************************************************************************/

   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::CanonicView::CanonicView(std::vector<CanonicNode> const & a_Nodes) noexcept
   : m_Nodes{ a_Nodes }
   {
   }


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Part::CanonicView const & a_View)
   {
      for (auto const & node : a_View)
      {
         a_OS << node << std::endl;
      }
      return a_OS;
   }
}
