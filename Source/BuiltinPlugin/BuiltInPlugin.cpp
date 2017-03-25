/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::BuiltinPlugin
 Content   : class BuiltinPlugin
\**************************************************************************************************/

#include <stdio.h>

#include <FXG/Stretto/BuiltinPlugin/Internal/BuiltinPlugin.h>

namespace FXG::Stretto::BuiltinPlugin
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   BuiltinPlugin::BuiltinPlugin() noexcept
   : IPlugin{ "Stretto Builtin Plugin" }
   {
   }


   /************************************************************************/
   /* Initialize                                                           */
   /************************************************************************/

   void BuiltinPlugin::createAnalysisModules()
   {
      createAnalysisModule<Part, BarCount>("Bar Counter", &countBars);
   }

   void BuiltinPlugin::createStructuralHierarchyLinks()
   {
      createStructuralHierarchyLink<Piece, Part>("Part", &extractPartsFromPiece);
   }
}
