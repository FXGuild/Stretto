/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 11, 2017
 Project     : Utils
 Summary     : String enum utilities
 Description : NA
\**************************************************************************************************/

#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <SGG/Utils/StdAliases.h>

#define DECLARE_STRING_ENUM( Namespace, Name, ... )                                                \
   DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE ( Namespace, Name, uint32_t, __VA_ARGS__ )

#define DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE( Namespace, Name, Type, ... )                         \
                                                                                                   \
   namespace Namespace                                                                             \
   {                                                                                               \
      enum class Name : Type                                                                       \
      {                                                                                            \
         __VA_ARGS__                                                                               \
      };                                                                                           \
   }                                                                                               \
                                                                                                   \
   namespace SGG::Utils::Enum::Internal                                                            \
   {                                                                                               \
      template <>                                                                                  \
      String const g_EnumTypeName< Namespace::Name > ( L#Name );                                   \
                                                                                                   \
      template <>                                                                                  \
      Strings const g_EnumValues< Namespace::Name > ( parseEnumValues ( L#__VA_ARGS__ ) );         \
   }

namespace SGG::Utils::Enum
{
   namespace Internal
   {
      template < typename E >
      String const g_EnumTypeName;

      template < typename E >
      Strings const g_EnumValues;

      static Strings parseEnumValues ( wchar_t const * i_EnumDecl )
      {
         String             name;
         Strings            names;
         std::wstringstream ss{ i_EnumDecl };

         std::getline ( ss, name, L',' );
         names.emplace_back ( name );
         while ( std::getline ( ss, name, L',' ) )
         {
            names.emplace_back ( name.substr ( 1 ) );
         }

         return names;
      }
   }

   template < typename E >
   String::size_type numValues ()
   {
      return Internal::g_EnumValues< E >.size ();
   }

   template < typename E >
   String const & typeName ()
   {
      return Internal::g_EnumTypeName< E >;
   }

   template < typename E >
   String const & toString ( E i_Val )
   {
      return Internal::g_EnumValues< E >[ static_cast< uint32_t > ( i_Val ) ];
   }

   template < typename E >
   std::pair< bool, E > parse ( String const & i_Str )
   {
      for ( uint32_t i = 0; i < Internal::g_EnumValues< E >.size (); ++i )
      {
         if ( i_Str == Internal::g_EnumValues< E >[ i ] )
         {
            return std::make_pair ( true, static_cast< E > ( i ) );
         }
      }
      return std::make_pair ( false, static_cast< E > ( 0 ) );
   }

   template < typename E, typename Func >
   void forEachValue ( Func io_Func )
   {
      for ( uint32_t i = 0; i < Internal::g_EnumValues< E >.size (); ++i )
      {
         io_Func ( static_cast< E > ( i ) );
      }
   }

}

template < typename E, typename = std::void_t< decltype (SGG:Utils::Enum::toString(E)) > >
inline std::ostream & operator<< (std::ostream & io_OS, E const & i_Value)
{
   io_OS << SGG::Utils::Enum::toString(i_Value).c_str();
   return io_OS;
}