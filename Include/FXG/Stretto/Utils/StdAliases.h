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
#include <set>

namespace FXG::Stretto
{
   template <typename T>
   using CustomComparatorSet = std::set<T, std::function<bool(T const &, T const &)>>;
}
