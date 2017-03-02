/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class Part
\**************************************************************************************************/

#include <assert.h>

#include <FXG/Stretto/Piece/Monophonic/Part.h>

namespace FXG::Stretto::Piece::Monophonic
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Part::Part(Theory::NoteDuration a_DurationUnit) noexcept
   : m_Nodes{}
   , m_DurationUnit{ a_DurationUnit }
   {
   }


   /************************************************************************/
   /* For-each Algorithms                                                  */
   /************************************************************************/

   void Part::forEachCanonicNode(std::function<void(CanonicNode const &)> a_Func) const
   {
      for (auto const & node : m_Nodes)
      {
         a_Func(node);
      }
   }

   void Part::forEachAggregatedNode(std::function<void(AggregatedNode const &)> a_Func) const
   {
      for (auto it = m_Nodes.cbegin(); it != m_Nodes.cend();)
      {
         uint32_t duration = 0;
         if (it->isRest())
         {
            do
            {
               duration += Theory::convertDurationToTU(it->getDuration(), m_DurationUnit);
               ++it;
            } while (it != m_Nodes.cend() && it->isRest());

            a_Func(AggregatedNode{ duration });
         }
         else
         {
            auto const & pitch = it->getNote().getPitch();
            do
            {
               duration += Theory::convertDurationToTU(it->getDuration(), m_DurationUnit);
               ++it;
            } while (it != m_Nodes.cend() && !it->isRest() && it->getNote().getPitch() == pitch);

            a_Func(AggregatedNode{ { pitch, duration } });
         }
      }
   }
}
