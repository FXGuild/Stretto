/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : class AnalysisModule
\**************************************************************************************************/

#pragma once

#include <functional>
#include <memory>
#include <string>
#include <typeindex>

#include <FXG/Stretto/PluginAPI/IAnalysisProfile.h>
#include <FXG/Stretto/PluginAPI/IMDS.h>

namespace FXG::Stretto::PluginAPI
{
   template <typename I, typename O>
   using AnalyseFunc = std::function<std::unique_ptr<O>(I const &)>;

   using AnalyseFuncInterface = std::function<std::unique_ptr<IAnalysisProfile>(IMDS const *)>;

   class AnalysisModule
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AnalysisModule(std::string const &  a_ModuleName,
                     std::type_index      a_InMDSType,
                     std::type_index      a_OutProfileType,
                     AnalyseFuncInterface a_AnalyseFunc) noexcept;
      AnalysisModule(AnalysisModule const &) = default;
      AnalysisModule(AnalysisModule &&)      = default;
      ~AnalysisModule() noexcept             = default;

      AnalysisModule & operator=(AnalysisModule const &) = default;
      AnalysisModule & operator=(AnalysisModule &&) = default;

   private:
      std::string          m_ModuleName;
      std::type_index      m_InMDSType;
      std::type_index      m_OutProfileType;
      AnalyseFuncInterface m_AnalyseFunc;
   };
}
