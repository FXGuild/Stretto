#pragma once

#include <SGG/Stretto/Plugin/TestPlugin/Hierarchy/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>
#include <SGG/Utils/StdAliases.h>

namespace SGG::Stretto::Schema
{
   using namespace Plugin::TestPlugin;

   template <>
   struct Converter< HierarchyID_t >
   {
      UPtr< Piece > convert( Theory::Piece const & i_Piece )
      {
         return std::make_unique< Piece >( i_Piece );
      }
   };
}
