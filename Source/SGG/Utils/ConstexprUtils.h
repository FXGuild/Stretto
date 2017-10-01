/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 26, 2017
 Project     : Utils
 Summary     : Constexpr-related template metaprograming utilities
 Description : NA
\**************************************************************************************************/

#pragma once

#include <stdint.h>
#include <type_traits>

namespace SGG::Utils
{
   /************************************************************************/
   /* for_each_compile_time_index                                          */
   /************************************************************************/

   namespace
   {
      template < typename Func, size_t I, size_t N >
      struct for_each_compile_time_index_impl
      {
         static constexpr void iterate ( Func io_Func )
         {
            io_Func.template operator()< I > ();
            for_each_compile_time_index_impl< Func, I + 1, N >::iterate ( io_Func );
         }
      };

      template < typename Func, size_t N >
      struct for_each_compile_time_index_impl< Func, N, N >
      {
         static constexpr void iterate ( Func /* io_Func */ ) {}
      };
   }

   template < size_t N, typename Func >
   constexpr void for_each_compile_time_index ( Func io_Func )
   {
      for_each_compile_time_index_impl< Func, 0, N >::iterate ( io_Func );
   }


   /************************************************************************/
   /* for_each_type                                                        */
   /************************************************************************/

   namespace
   {
      template < typename Func, typename T >
      constexpr void for_each_type_impl ( Func io_Func )
      {
         io_Func.template operator()< T > ();
      }

      template < typename Func,
                 typename T,
                 typename... Ts,
                 typename = std::enable_if_t< sizeof...( Ts ) != 0 > >
      constexpr void for_each_type_impl ( Func io_Func )
      {
         for_each_type_impl< Func, T > ( io_Func );
         for_each_type_impl< Func, Ts... > ( io_Func );
      }
   }

   template < typename T, typename... Ts, typename Func >
   constexpr void for_each_type ( Func io_Func )
   {
      for_each_type_impl< Func, T, Ts... > ( io_Func );
   }


   /************************************************************************/
   /* is_defined                                                           */
   /************************************************************************/

   // https://stackoverflow.com/questions/39816779/check-if-type-is-defined
   template < typename, typename = void >
   struct is_defined : std::false_type
   {
   };

   template < typename T >
   struct is_defined<
      T,
      std::enable_if_t< std::is_object_v< T > && !std::is_pointer_v< T > && ( sizeof ( T ) > 0 ) > >
   : std::true_type
   {
   };


   /************************************************************************/
   /* String utils                                                         */
   /************************************************************************/

   constexpr bool areStringsEqual ( char const * i_A, char const * i_B )
   {
      return ( *i_A && *i_B ) ? ( *i_A == *i_B && areStringsEqual ( i_A + 1, i_B + 1 ) )
                              : ( !*i_A && !*i_B );
   }

   constexpr uint32_t stringLength ( char const * i_Str )
   {
      char const * s{ i_Str };
      while ( *s != '\0' )
      {
         ++s;
      }
      return static_cast< uint32_t > ( s - i_Str );
   }
}
