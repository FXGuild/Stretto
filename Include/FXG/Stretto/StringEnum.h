/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : Global scope and FXG::Stretto
 Content   : String enum utilities
\**************************************************************************************************/

#pragma once

#include <iostream>
#include <vector>

#define DECLARE_STRING_ENUM(Name, ...) DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Name, uint32_t, ...)

#define DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Name, Type, ...)                                      \
                                                                                                   \
   enum class Name : Type                                                                          \
   {                                                                                               \
      __VA_ARGS__                                                                                  \
   };                                                                                              \
                                                                                                   \
   inline std::string const & toString(Name a_Value)                                               \
   {                                                                                               \
      static auto const names{ FXG::Stretto::splitEnumValues(#__VA_ARGS__) };                      \
      return names[static_cast<Type>(a_Value)];                                                    \
   }                                                                                               \
                                                                                                   \
   inline std::ostream & operator<<(std::ostream & a_OS, Name a_Value)                             \
   {                                                                                               \
      a_OS << toString(a_Value).c_str();                                                           \
      return a_OS;                                                                                 \
   }

namespace FXG::Stretto
{
   std::vector<std::string> splitEnumValues(char const * a_Values);
}
