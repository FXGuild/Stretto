/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : class StructuralHierarchyLink
 \**************************************************************************************************/

#include <FXG/Stretto/PluginAPI/StructuralHierarchyLink.h>

namespace FXG::Stretto::PluginAPI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   StructuralHierarchyLink::StructuralHierarchyLink(
      std::string const &          a_OutChildMDSTypeName,
      std::type_index              a_InParentMDSType,
      std::type_index              a_OutChildMDSType,
      ExtractChildMDSFuncInterface a_ExtractFunc) noexcept
   : m_OutChildMDSTypeName{ a_OutChildMDSTypeName }
   , m_InParentMDSType{ a_InParentMDSType }
   , m_OutChildMDSType{ a_OutChildMDSType }
   , m_ExtractFunc{ a_ExtractFunc }
   {
   }
}
