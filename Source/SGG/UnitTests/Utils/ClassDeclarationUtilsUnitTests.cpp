/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 26, 2017
 Summary     : Unit tests for ClassDeclarationUtils.h
 Description : NA
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <SGG/Utils/ClassDeclarationUtils.h>

namespace SGG::UnitTests
{
   class MyIterableClass final
   {
   public:
      MyIterableClass ()
      : m_Age{ 5 }
      , m_Scores{ 4.3, 2.5, 7.7 }
      {
      }

      DEFINE_ITERABLE_BASED_ON_CONTAINER ( m_Scores );

   private:
      uint32_t              m_Age;
      std::vector< double > m_Scores;
   };

   TEST ( SGG_Utils_ClassDeclaration, General )
   {
      MyIterableClass myItCls;

      auto it = myItCls.begin ();

      EXPECT_EQ ( *it, 4.3 );
      ++it;
      EXPECT_EQ ( *it, 2.5 );

      EXPECT_EQ ( std::distance ( myItCls.cbegin (), myItCls.cend () ), 3 );
   }
}
