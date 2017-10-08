/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <vector>

#include <SGG/Stretto/Theory/Piece/AggregatedNode.h>
#include <SGG/Stretto/Theory/Piece/CanonicNode.h>
#include <SGG/Utils/ClassDeclarationUtils.h>

namespace SGG::Stretto::Theory
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

      Part ( Theory::NoteDuration i_DurationUnit ) noexcept;

   public:
      Part ( Part const & ) = default;
      Part ( Part && )      = default;
      ~Part () noexcept     = default;

      Part & operator= ( Part const & ) = default;
      Part & operator= ( Part && ) = default;


      /************************************************************************/
      /* Access views                                                         */
      /************************************************************************/

      AggregatedView aggregatedView () const;
      CanonicView    canonicView () const;

   private:
      std::vector< AggregatedNode > m_AggregatedNodes;
      std::vector< CanonicNode >    m_CanonicNodes;
      Theory::NoteDuration          m_DurationUnit;
   };

   class Part::AggregatedView
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedView ( std::vector< AggregatedNode > const & i_Nodes ) noexcept;
      AggregatedView ( AggregatedView const & ) noexcept = default;
      AggregatedView ( AggregatedView && ) noexcept      = default;
      ~AggregatedView () noexcept                        = default;

      AggregatedView & operator= ( AggregatedView const & ) noexcept = default;
      AggregatedView & operator= ( AggregatedView && ) noexcept = default;

   private:
      std::vector< AggregatedNode > const & m_Nodes;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON_CONTAINER ( m_Nodes );
   };

   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator<< ( std::wostream & io_OS, Part::AggregatedView const & i_View );


   class Part::CanonicView
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      CanonicView ( std::vector< CanonicNode > const & i_Nodes ) noexcept;
      CanonicView ( CanonicView const & ) noexcept = default;
      CanonicView ( CanonicView && ) noexcept      = default;
      ~CanonicView () noexcept                     = default;

      CanonicView & operator= ( CanonicView const & ) noexcept = default;
      CanonicView & operator= ( CanonicView && ) noexcept = default;

   private:
      std::vector< CanonicNode > const & m_Nodes;

   public:
      /************************************************************************/
      /* Iteration                                                            */
      /************************************************************************/

      DEFINE_ITERABLE_BASED_ON_CONTAINER ( m_Nodes );
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator<< ( std::wostream & io_OS, Part::CanonicView const & i_View );
}
