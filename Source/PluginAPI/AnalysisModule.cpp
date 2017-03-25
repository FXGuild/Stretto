/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 25, 2017
 Namespace : FXG::Stretto::PluginAPI
 Content   : class AnalysisModule
\**************************************************************************************************/

#include <FXG/Stretto/PluginAPI/AnalysisModule.h>

namespace FXG::Stretto::PluginAPI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   AnalysisModule::AnalysisModule(std::string const &  a_ModuleName,
                                  std::type_index      a_InMDSType,
                                  std::type_index      a_OutProfileType,
                                  AnalyseFuncInterface a_AnalyseFunc) noexcept
   : m_ModuleName{ a_ModuleName }
   , m_InMDSType{ a_InMDSType }
   , m_OutProfileType{ a_OutProfileType }
   , m_AnalyseFunc{ a_AnalyseFunc }
   {
   }
}
