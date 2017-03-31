/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 26, 2017
 Namespace : FXG::Stretto
 Content   : Template metaprograming utilities
\**************************************************************************************************/

#pragma once

#include <type_traits>

namespace FXG::Stretto
{
   namespace Internal
   {
      template <typename Func, typename T>
      constexpr void forEachTypeImpl(Func a_Func)
      {
         // TODO templated lambdas: replace with
         // a_Func.template operator()<T>();
         a_Func.template operator()<T>(nullptr);
         ////
      }

      template <typename Func,
                typename T,
                typename... Ts,
                typename = std::enable_if_t<sizeof...(Ts) != 0>>
      constexpr void forEachTypeImpl(Func a_Func)
      {
         forEachTypeImpl<Func, T>(a_Func);
         forEachTypeImpl<Func, Ts...>(a_Func);
      }
   }

   template <typename T, typename... Ts, typename Func>
   constexpr void forEachType(Func a_Func)
   {
      Internal::forEachTypeImpl<Func, T, Ts...>(a_Func);
   }

   constexpr bool areEqual(char const * a_A, char const * a_B)
   {
      return (*a_A && *a_B) ? (*a_A == *a_B && areEqual(a_A + 1, a_B + 1)) : (!*a_A && !*a_B);
   }

   constexpr uint32_t stringLength(char const * a_Str)
   {
      char const * s{ a_Str };
      while (*s != '\0')
      {
         ++s;
      }
      return static_cast<uint32_t>(s - a_Str);
   }
}
