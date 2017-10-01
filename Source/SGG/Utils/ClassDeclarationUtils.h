/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Project     : Utils
 Summary     : Class methods declaration helper macros
 Description : NA
\**************************************************************************************************/

#pragma once

// clang-format off
#define DEFINE_ITERABLE_BASED_ON_CONTAINER( container )                                            \
   auto begin  ()       { return container.begin (); }                                             \
   auto end    ()       { return container.end   (); }                                             \
   auto begin  () const { return container.cbegin(); }                                             \
   auto end    () const { return container.cend  (); }                                             \
   auto cbegin () const { return container.cbegin(); }                                             \
   auto cend   () const { return container.cend  (); }
// clang-format on
