#pragma once

#include <SGG/Stretto/Plugin/TestPlugin/Hierarchy/Dimension.h>
#include <SGG/Stretto/Schema/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Plugin::TestPlugin
{
   template < Temporal Tmp, Phonal Phn, Textural Tex >
   using TestFragment = Schema::Fragment< HierarchyID_t,
                                          static_cast< uint32_t >( Tmp ),
                                          static_cast< uint32_t >( Phn ),
                                          static_cast< uint32_t >( Tex ) >;

   struct Piece final : public TestFragment< Temporal::Piece,
                                             Phonal  ::Piece,
                                             Textural::Polyphonic >
   {
      explicit Piece( Theory::Piece const & i_Piece )
         : m_Piece { i_Piece }
      {}

      Theory::Piece const & m_Piece;
   };

   class Bar final : public TestFragment< Temporal::Bar,
                                          Phonal  ::Part,
                                          Textural::Polyphonic >
   {

   };

   class MonophonicNoteNode final : public TestFragment< Temporal::Timeunit,
                                                         Phonal  ::Pitch,
                                                         Textural::Polyphonic >
   {

   };
}
