/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : class StructuralHierarchyLink
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/PluginAPI/IMDS.h>
#include <FXG/Stretto/StdAliases.h>

namespace FXG::Stretto::PluginAPI
{
   template <typename I, typename O>
   using ExtractChildMDSFunc = std::function<UPtrs<O>(I const &)>;

   using ExtractChildMDSFuncInterface = std::function<UPtrs<IMDS>(IMDS const *)>;

   class StructuralHierarchyLink
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      StructuralHierarchyLink(std::string const &          a_OutChildMDSTypeName,
                              std::type_index              a_InParentMDSType,
                              std::type_index              a_OutChildMDSType,
                              ExtractChildMDSFuncInterface a_ExtractFunc) noexcept;
      StructuralHierarchyLink(StructuralHierarchyLink const &) = default;
      StructuralHierarchyLink(StructuralHierarchyLink &&)      = default;
      ~StructuralHierarchyLink() noexcept                      = default;

      StructuralHierarchyLink & operator=(StructuralHierarchyLink const &) = default;
      StructuralHierarchyLink & operator=(StructuralHierarchyLink &&) = default;

   private:
      std::string                  m_OutChildMDSTypeName;
      std::type_index              m_InParentMDSType;
      std::type_index              m_OutChildMDSType;
      ExtractChildMDSFuncInterface m_ExtractFunc;
   };
}
