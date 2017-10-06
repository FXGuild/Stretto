#pragma once

#include <SGG/Stretto/Plugin/BuiltinPlugin/Dimension.h>
#include <SGG/Stretto/Schema/Fragment.h>

namespace SGG::Stretto::Plugin::Builtin
{
   template < Temporal Tmp, Phonal Phn, Textural Tex >
   using BuiltinFragment = Schema::Fragment< HierarchyID_t,
                                             static_cast< uint32_t >( Tmp ),
                                             static_cast< uint32_t >( Phn ),
                                             static_cast< uint32_t >( Tex ) >;
}
