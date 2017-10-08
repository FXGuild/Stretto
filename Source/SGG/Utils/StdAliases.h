/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 27, 2017
 Project     : Utils
 Summary     : Std type aliases
 Description : Voluntarily in the Utils namespace for ease of use
\**************************************************************************************************/

#pragma once

#include <functional>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace SGG
{
   using String = std::wstring;

   using Strings = std::vector< String >;

   template < typename T >
   using Vec = std::vector< T >;

   template < typename T >
   using Set = std::set< T >;

   template < typename T >
   using MSet = std::multiset< T >;

   template < typename T >
   using UPtr = std::unique_ptr< T >;

   template < typename T >
   using UPtrs = Vec< UPtr< T > >;

   template < typename T, typename U >
   using Pair = std::pair< T, U >;

   template < typename T, typename U >
   using Map = std::map< T, U >;

   template < typename T, typename U >
   using UMap = std::unordered_map< T, U >;

   template < typename T >
   using TypeMap = UMap< std::type_index, T >;
}
