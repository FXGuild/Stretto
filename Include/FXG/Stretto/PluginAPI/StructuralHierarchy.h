/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : StructuralHierarchy class and nested classes
 \**************************************************************************************************/

#pragma once

#include <FXG/Stretto/StdAliases.h>
#include <FXG/Stretto/StringEnum.h>

namespace FXG::Stretto::PluginAPI
{
   class MusicalDataStructure;

   struct StructuralHierarchy final
   {
      struct Dimension;

      std::string            m_Name;
      std::vector<Dimension> m_Dimensions;
   };

   struct StructuralHierarchy::Dimension final
   {
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/
   public:
      enum class Type;
      struct Level;
      struct Link;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      template <typename E>
      Dimension(std::string const & a_Name, Type a_Type);
      ~Dimension() = default;

   private:
      std::string        m_Name;
      Type               m_Type;
      std::vector<Level> m_Levels;
      std::vector<Link>  m_Links;
   };

   DECLARE_STRING_ENUM(StructuralHierarchy::Dimension::Type, Composition, State)

   struct StructuralHierarchy::Dimension::Level final
   {
      std::string m_Name;
      uint32_t    m_ID;
   };

   using ExtractSubStructuresFunc =
      std::function<UPtrs<MusicalDataStructure>(MusicalDataStructure const *)>;

   struct StructuralHierarchy::Dimension::Link final
   {
      uint32_t                 m_FromID;
      uint32_t                 m_ToID;
      ExtractSubStructuresFunc m_DefaultExtractFunc;
   };
}
