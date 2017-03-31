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
#include <vector>

#define DECLARE_STRING_ENUM(Name, ...) \
   DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Name, uint32_t, __VA_ARGS__)

#define DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Name, Type, ...)        \
                                                                     \
   enum class Name : Type                                            \
   {                                                                 \
      __VA_ARGS__                                                    \
   };                                                                \
                                                                     \
   namespace FXG::Stretto::Enum::Internal                            \
   {                                                                 \
      template <>                                                    \
      constexpr char const * g_EnumTypeName<Name>{ #Name };          \
                                                                     \
      template <>                                                    \
      constexpr char const * g_EnumDeclString<Name>{ #__VA_ARGS__ }; \
                                                                     \
      template <>                                                    \
      constexpr EnumValuesHolder<Name> g_EnumValues<Name>{};         \
   }

namespace FXG::Stretto::Enum
{
   namespace Internal
   {
      template <typename E>
      constexpr char const * g_EnumTypeName = nullptr;

      template <typename E>
      constexpr char const * g_EnumDeclString = nullptr;
   }

   template <typename E>
   constexpr uint32_t numValues()
   {
      char const * s = g_EnumDeclString<E>;
      uint32_t     numComma{ 0 };
      while (*s != '\0')
      {
         if (*(s++) == ',')
         {
            ++numComma;
         }
      }
      return numComma + 1;
   }

   namespace Internal
   {
      template <typename E>
      struct EnumValuesHolder
      {
         char     values[sizeof(g_EnumDeclString<E>) - numValues<E>() + 1];
         uint32_t valuesIdx[numValues<E>()];

         constexpr EnumValuesHolder()
         : values{}
         , valuesIdx{}
         {
            char const * in{ g_EnumDeclString<E> };
            char *       v{ values };
            uint32_t *   b{ valuesIdx };

            while (*in != '\0')
            {
               if (*in == ',')
               {
                  *(v++) = '\0';
                  *(++b) = v - values;
                  ++in;
               }
               else
               {
                  *(v++) = *in;
               }
               ++in;
            }
         }
      };

      template <typename E>
      constexpr EnumValuesHolder<E> g_EnumValues{};
   }

   template <typename E>
   constexpr char const * typeName()
   {
      return Internal::g_EnumTypeName<E>;
   }

   template <typename E>
   constexpr char const * toString(E val)
   {
      auto const & splitter{ Internal::g_EnumValues<E> };
      return splitter.values + splitter.valuesIdx[static_cast<uint32_t>(val)];
   }

   template <typename E>
   constexpr std::pair<bool, E> parse(char const * a_Str)
   {
      for (uint32_t i = 0; i < numValues<E>(); ++i)
      {
         E val{ static_cast<E>(i) };
         if (areEqual(toString(val), a_Str))
         {
            return { true, val };
         }
      }
      return { false, static_cast<E>(0) };
   }

   namespace Internal
   {
      template <typename Func, typename E, uint32_t N>
      struct ForEach
      {
         static constexpr void impl(Func a_Func)
         {
            // TODO templated lambdas: replace with
            //    E const val{ static_cast<E>(numValues<E>() - N) };
            //    a_Func.template operator()<E, val>();
            // when possible
            a_Func(static_cast<E>(numValues<E>() - N));
            ForEach<Func, E, N - 1>::impl(a_Func);
            ////
         }
      };

      template <typename Func, typename E>
      struct ForEach<Func, E, 0>
      {
         static constexpr void impl(Func a_Func)
         {
         }
      };
   }

   template <typename E, typename Func>
   constexpr void forEachValue(Func a_Func)
   {
      Internal::ForEach<Func, E, numValues<E>()>::impl(a_Func);
   }
}
