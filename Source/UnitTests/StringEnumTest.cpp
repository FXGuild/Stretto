/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::Utils
 Content   : Unit tests for string enum utilities
\**************************************************************************************************/

#include <gtest/gtest.h>

#include <FXG/Stretto/MetaprogramingUtils.h>
#include <FXG/Stretto/StringEnum.h>

DECLARE_STRING_ENUM(People, Fred, Bob, Louise)
DECLARE_STRING_ENUM(Fruit, Apple, Orange, Banana, Watermelon)
DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Number, uint16_t, One)

namespace FXG::Stretto::Enum
{
   TEST(Utils_StringEnum, General)
   {
      // Check the number of values in an enum
      EXPECT_EQ(numValues<People>(), 3);

      // Check the string value of an enum type
      EXPECT_EQ(typeName<Number>(), std::string("Number"));

      // Check the string value of an enum constant
      // static_assert(areEqual(toString(Fruit::Banana), "Banana"));

      // Check the string value of an enum constant
      // static_assert(parse<People>("Louise").second == People::Louise);
      EXPECT_TRUE(!parse<Number>("Two").first);

      // Iterate through values of an enum type to check some property
      // TODO templated lambdas: replace with []<typename E, E val>() { .. } when possible
      //forEachValue<Fruit>([](auto a_Val) { static_assert(stringLength(toString(a_Val)) < 11); });

      // Iterate through an array of types to check some property
      forEachType<People, Fruit, Number>([](auto * a_Val) 
      { 
         EXPECT_TRUE(numValues<decltype(a_Val)>() < 5); 
      });

      // Print stuff
      forEachType<People, Fruit, Number>([](auto * a_TypePtr) {
         printf("%-16s (%d values)\n", typeName<decltype(a_TypePtr)>().c_str(),
            static_cast<int>(numValues<decltype(a_TypePtr)>()));
         /*
         forEachValue<std::decay_t<decltype(a_TypePtr)>>([](auto a_Val) {
            printf("\t%-12s (%d characters)\n", toString(val).c_str(), stringLength(toString(val).c_str()));
         });
         */
         printf("\n");
      });
   }

   // TODO constexpr var template: uncomment me
   /*
   TEST(Utils_ConstexprStringEnum, General)
   {
      // Check the number of values in an enum
      static_assert(numValues<People>() == 3);

      // Check the string value of an enum type
      static_assert(areEqual(typeName<Number>(), "Number"));

      // Check the string value of an enum constant
      // static_assert(areEqual(toString(Fruit::Banana), "Banana"));

      // Check the string value of an enum constant
      // static_assert(parse<People>("Louise").second == People::Louise);
      static_assert(!parse<Number>("Two").first);

      // Iterate through values of an enum type to check some property
      // TODO templated lambdas: replace with []<typename E, E val>() { .. } when possible
      //forEachValue<Fruit>([](auto a_Val) { static_assert(stringLength(toString(a_Val)) < 11); });

      // Iterate through an array of types to check some property
      forEachType<People, Fruit, Number>(
         [](auto * a_Val) { static_assert(numValues<decltype(a_Val)>() < 5); });
       
      // Print stuff
      forEachType<People, Fruit, Number>([](auto * a_TypePtr) {
         printf("%-16s (%d values)\n", typeName<decltype(a_TypePtr)>(),
                numValues<decltype(a_TypePtr)>());
         forEachValue<decltype(a_TypePtr)>([](auto a_Val) {
            printf("\t%-12s (%d characters)\n", toString(val), stringLength(toString(val)));
         });
         printf("\n");
      });
   }
   */
}
