/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 27, 2017
 Namespace : FXG::Stretto
 Content   : Std type aliases
\**************************************************************************************************/

#pragma once

#include <functional>
#include <memory>
#include <set>
#include <string>
#include <typeindex>
#include <unordered_map>
#include <vector>

namespace FXG::Stretto
{
   template <typename T>
   using UPtrs = std::vector<std::unique_ptr<T>>;

   template <typename T>
   using StringMap = std::unordered_map<std::string, T>;

   template <typename T>
   using TypeMap = std::unordered_map<std::type_index, T>;

   template <typename T>
   using CustomComparatorSet = std::set<T, std::function<bool(T const &, T const &)>>;
}
