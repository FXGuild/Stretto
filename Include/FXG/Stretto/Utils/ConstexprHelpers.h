/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : June 10, 2017
Namespace : FXG::Stretto::Utils
Content   : Constexpr helpers
\**************************************************************************************************/

#pragma once

namespace FXG::Stretto::Utils
{
   namespace Internal
   {
      template < typename Func, size_t I, size_t N >
      struct for_each_static_index_impl
      {
         static void iterate(Func a_Func)
         {
            a_Func.operator()<I>();
            for_each_static_index_impl< Func, I + 1, N >::iterate((Func)a_Func);
         }
      };

      template < typename Func, size_t N >
      struct for_each_static_index_impl< Func, N, N >
      {
         static void iterate(Func /* a_Func */)
         {

         }
      };
   }

   template < size_t N, typename Func >
   void for_each_static_index(Func a_Func)
   {
      Internal::for_each_static_index_impl< Func, 0, N >::iterate(a_Func);
   }
}
