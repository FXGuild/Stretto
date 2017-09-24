/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : June 10, 2017
Namespace : FXG::Stretto::Utils
Content   : Unit tests for ConstexprHelpers.h
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/Utils/ConstexprHelpers.h>

namespace FXG::Stretto::Utils
{
   struct Dummy
   {
      template < uint32_t N >
      constexpr void operator()() const
      {
         static_assert(N < 4, "");
      }
   };

   TEST(for_each_static_index, General)
   {
      // We can't pass a lambda because this syntax is incorrect:
      // []< size_t I >() { static_assert(I < 4); }
      for_each_static_index< 3 >(Dummy());
   }
}
