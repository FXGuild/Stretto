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
#include <FXG/Stretto/PluginAPI/StructuralHierarchy.h>
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
      virtual ~IPlugin() noexcept = default;


      /************************************************************************/
      /* Register components                                                  */
      /************************************************************************/

      void registerComponents(StringMap<StructuralHierarchy> & a_Hierarchies);

   protected:
      template <typename I, typename O>
      void registerAnalysisModule(std::string const & a_ModuleName, AnalyseFunc<I, O> a_AnalyseFunc)
      {
         m_AnalysisModules.emplace_back(a_ModuleName, typeid(I), typeid(O),
                                        [a_AnalyseFunc](IMDS const * a_MDS) {
                                           return a_AnalyseFunc(*static_cast<I const *>(a_MDS));
                                        });
      }

      virtual void registerAnalysisModules() = 0;
      virtual void createAndUpgradeStructualHierarchies(
         StringMap<StructuralHierarchy> & a_Hierarchies) = 0;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/
   public:
      std::string const &                 getName() const;
      std::vector<AnalysisModule> const & getAnalysisModules() const;

   private:
      std::string                 m_Name;
      std::vector<AnalysisModule> m_AnalysisModules;
   };
}
