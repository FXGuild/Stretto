/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Piece::Monophonic
 Content   : class Part
\**************************************************************************************************/

#pragma once

#include <functional>
#include <vector>

#include <FXG/Stretto/Piece/Monophonic/AggregatedNode.h>
#include <FXG/Stretto/Piece/Monophonic/CanonicNode.h>

namespace FXG::Stretto::Piece::Monophonic
{
   class Part final
   {
      friend class PartBuilder;

      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Part(Theory::NoteDuration a_DurationUnit) noexcept;

   public:
      Part(Part const &) = default;
      Part(Part &&)      = default;
      ~Part() noexcept   = default;

      Part & operator=(Part const &) = default;
      Part & operator=(Part &&) = default;


      /************************************************************************/
      /* For-each Algorithms                                                  */
      /************************************************************************/

      void forEachCanonicNode(std::function<void(CanonicNode const &)> a_Func) const;
      void forEachAggregatedNode(std::function<void(AggregatedNode const &)> a_Func) const;

   private:
      std::vector<CanonicNode> m_Nodes;
      Theory::NoteDuration     m_DurationUnit;
   };
}
