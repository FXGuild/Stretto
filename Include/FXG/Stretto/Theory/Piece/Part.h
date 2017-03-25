/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::Theory::Piece
 Content   : class Part
\**************************************************************************************************/

#pragma once

#include <vector>

#include <FXG/Stretto/Theory/Piece/AggregatedNode.h>
#include <FXG/Stretto/Theory/Piece/CanonicNode.h>
#include <FXG/Stretto/ClassDeclHelpers.h>

namespace FXG::Stretto::Theory::Piece
{
   class Part final
   {
      friend class PartBuilder;

   public:
      class AggregatedView;
      class CanonicView;

   private:
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
      /* Access views                                                         */
      /************************************************************************/

      AggregatedView aggregatedView() const;
      CanonicView    canonicView() const;

   private:
      std::vector<AggregatedNode> m_AggregatedNodes;
      std::vector<CanonicNode>    m_CanonicNodes;
      Theory::NoteDuration        m_DurationUnit;
   };

   class Part::AggregatedView
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedView(std::vector<AggregatedNode> const & a_Nodes) noexcept;
      AggregatedView(AggregatedView const &) noexcept = default;
      AggregatedView(AggregatedView &&) noexcept      = default;
      ~AggregatedView() noexcept                      = default;

      AggregatedView & operator=(AggregatedView const &) noexcept = default;
      AggregatedView & operator=(AggregatedView &&) noexcept = default;

   private:
      std::vector<AggregatedNode> const & m_Nodes;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON(m_Nodes);
   };

   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Part::AggregatedView const & a_View);


   class Part::CanonicView
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicView(std::vector<CanonicNode> const & a_Nodes) noexcept;
      CanonicView(CanonicView const &) noexcept = default;
      CanonicView(CanonicView &&) noexcept      = default;
      ~CanonicView() noexcept                   = default;

      CanonicView & operator=(CanonicView const &) noexcept = default;
      CanonicView & operator=(CanonicView &&) noexcept = default;

   private:
      std::vector<CanonicNode> const & m_Nodes;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON(m_Nodes);
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, Part::CanonicView const & a_View);
}
