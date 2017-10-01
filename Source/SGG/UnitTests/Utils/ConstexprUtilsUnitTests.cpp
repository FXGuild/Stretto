/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for ConstexprUtils.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Utils/ConstexprUtils.h>

namespace SGG::UnitTests
{
   struct AssertIsLowerThan10
   {
      template < uint32_t I >
      void operator() ()
      {
         static_assert ( I < 10 );
      }
   };

   TEST ( SGG_Utils_ConstexprUtils, for_each_compile_time_index )
   {
      Utils::for_each_compile_time_index< 5 > ( AssertIsLowerThan10 () );
   }

   struct AssertTypeIsIntegral
   {
      template < typename T >
      void operator() ()
      {
         static_assert ( std::is_integral_v< T > );
      }
   };

   TEST ( SGG_Utils_ConstexprUtils, for_each_type )
   {
      Utils::for_each_type< int, char, uint32_t > ( AssertTypeIsIntegral () );
   }

   struct defined
   {
   };

   struct forward_declared;

   TEST ( SGG_Utils_ConstexprUtils, is_defined )
   {
      static_assert ( Utils::is_defined< defined > () );
      static_assert ( !Utils::is_defined< forward_declared > () );
   }

   TEST ( SGG_Utils_ConstexprUtils, StringUtils )
   {
      static_assert ( Utils::stringLength ( "food" ) == 4 );

      static_assert ( !Utils::areStringsEqual ( "great", "Great" ) );

      static_assert ( Utils::areStringsEqual ( "small", "small" ) );
   }
}
