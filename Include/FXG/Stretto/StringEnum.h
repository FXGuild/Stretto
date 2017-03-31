/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : Global scope and FXG::Stretto:Enum
 Content   : String enum utilities
\**************************************************************************************************/

#pragma once

#include <iostream>
#include <string>
#include <vector>

#define DECLARE_STRING_ENUM(Namespace, Name, ...) \
   DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Namespace, Name, uint32_t, __VA_ARGS__)

#define DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Namespace, Name, Type, ...)             \
                                                                                     \
   namespace Namespace                                                               \
   {                                                                                 \
      enum class Name : Type                                                         \
      {                                                                              \
         __VA_ARGS__                                                                 \
      };                                                                             \
   }                                                                                 \
                                                                                     \
   namespace FXG::Stretto::Enum::Internal                                            \
   {                                                                                 \
      template <>                                                                    \
      std::string const g_EnumTypeName<Namespace::Name>{ #Name };                    \
                                                                                     \
      template <>                                                                    \
      std::vector<std::string> const g_EnumValues<Namespace::Name>{ parseEnumValues( \
         #__VA_ARGS__) };                                                            \
   }

namespace FXG::Stretto::Theory
{
   template <typename E, typename = std::void_t<decltype(toString(E))>>
   inline std::ostream & operator<<(std::ostream & a_OS, E const & a_Value)
   {
      a_OS << FXG::Stretto::Enum::toString(a_Value).c_str();
      return a_OS;
   }
}

namespace FXG::Stretto::Enum
{
   namespace Internal
   {
      template <typename E>
      std::string const g_EnumTypeName;

      template <typename E>
      std::vector<std::string> const g_EnumValues;

      std::vector<std::string> parseEnumValues(char const * a_EnumDecl)
      {
         std::vector<std::string> values;

         char const * s{ a_EnumDecl };
         char const * prev{ s };
         while (*s != '\0')
         {
            if (*s == ',')
            {
               values.emplace_back(prev, *s);
               prev = s + 1;
            }
            ++s;
         }
         values.emplace_back(prev);
         return values;
      }
   }

   template <typename E>
   std::string::size_type numValues()
   {
      return Internal::g_EnumValues<E>.size();
   }

   template <typename E>
   std::string const & typeName()
   {
      return Internal::g_EnumTypeName<E>;
   }

   template <typename E>
   std::string const & toString(E val)
   {
      return Internal::g_EnumValues<E>[static_cast<uint32_t>(val)];
   }

   template <typename E>
   std::pair<bool, E> parse(std::string const & a_Str)
   {
      for (uint32_t i = 0; i < Internal::g_EnumValues<E>.size(); ++i)
      {
         std::string value{ Internal::g_EnumValues<E>[i] };
         if (a_Str == value)
         {
            return std::make_pair(true, static_cast<E>(i));
         }
      }
      return std::make_pair(false, static_cast<E>(0));
   }

   template <typename E, typename Func>
   void forEachValue(Func a_Func)
   {
      for (uint32_t i = 0; i < Internal::g_EnumValues<E>.size(); ++i)
      {
         a_Func(static_cast<E>(i));
      }
   }
}
