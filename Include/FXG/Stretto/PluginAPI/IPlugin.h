/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : Abstract class IPlugin
\**************************************************************************************************/

#pragma once

#include <iterator>

#include <FXG/Stretto/PluginAPI/AnalysisModule.h>
#include <FXG/Stretto/PluginAPI/StructuralHierarchyLink.h>
#include <FXG/Stretto/StdAliases.h>

namespace FXG::Stretto::PluginAPI
{
   class IPlugin
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      explicit IPlugin(std::string const & a_Name) noexcept;
      IPlugin(IPlugin const &)     = default;
      IPlugin(IPlugin &&) noexcept = default;
      virtual ~IPlugin() noexcept  = default;

      IPlugin & operator=(IPlugin const &) = default;
      IPlugin & operator=(IPlugin &&) noexcept = default;


      /************************************************************************/
      /* Initialize                                                           */
      /************************************************************************/

      void initialize();

   protected:
      virtual void createAnalysisModules()          = 0;
      virtual void createStructuralHierarchyLinks() = 0;

      template <typename I, typename O>
      void createAnalysisModule(std::string const & a_ModuleName, AnalyseFunc<I, O> a_AnalyseFunc)
      {
         m_AnalysisModules.emplace_back(std::make_unique<AnalysisModule>(
            a_ModuleName, typeid(I), typeid(O), [a_AnalyseFunc](IMDS const * a_MDS) {
               return a_AnalyseFunc(*static_cast<I const *>(a_MDS));
            }));
      }

      template <typename I, typename O>
      void createStructuralHierarchyLink(std::string const & a_ChildTypeName,
                                         ExtractChildMDSFunc<I, O> a_ExtractFunc)
      {
         m_Links.emplace_back(std::make_unique<StructuralHierarchyLink>(
            a_ChildTypeName, typeid(I), typeid(O), [a_ExtractFunc](IMDS const * a_MDS) {
               UPtrs<O>    children{ a_ExtractFunc(*static_cast<I const *>(a_MDS)) };
               UPtrs<IMDS> out;
               std::move(begin(children), end(children), std::back_inserter(out));
               return out;
            }));
      }

   public:
      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      std::string const &                    getName() const;
      UPtrs<AnalysisModule> const &          getAnalysisModules() const;
      UPtrs<StructuralHierarchyLink> const & getStructuralHierarchyLinks() const;

   private:
      std::string                    m_Name;
      UPtrs<AnalysisModule>          m_AnalysisModules;
      UPtrs<StructuralHierarchyLink> m_Links;
   };
}
