#pragma once

#include <SGG/Stretto/Plugin/BuiltinPlugin/Fragment.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>
#include <SGG/Utils/StdAliases.h>

namespace SGG::Stretto::Schema
{
   using namespace Plugin::BuiltinPlugin;

   template <>
   struct Converter< HierarchyID_t >
   {
      UPtr< Track > convert( Theory::Track const & i_Track )
      {
         return std::make_unique< Track >( i_Track );
      }
   };
}
