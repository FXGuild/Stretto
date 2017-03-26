/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : StructuralHierarchy class and nested classes
\**************************************************************************************************/

#include <FXG/Stretto/PluginAPI/StructuralHierarchy.h>

namespace FXG::Stretto::PluginAPI
{
   template <typename E>
   StructuralHierarchy::Dimension::Dimension(std::string const & a_Name, Type a_Type)
   : m_Name{ a_Name }
   , m_Type{ a_Type }
   , m_Levels{}
   , m_Links{}
   {
      forEachEnumValue<E>(
         [](E a_Val) { m_Levels.emplace_back(toString(a_Val), static_cast<uint32_t>(a_Val)); });
   }
}
