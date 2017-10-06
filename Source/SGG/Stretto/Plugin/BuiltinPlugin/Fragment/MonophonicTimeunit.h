/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : October 1, 2017
 Project     : BuiltinPlugin
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Plugin/BuiltinPlugin/Fragment/Fragment.h>
#include <SGG/Stretto/Schema/Fragment.h>

namespace SGG::Stretto::Plugin::Builtin
{
   class MonophonicTimeunit final
      : BuiltinFragment< Temporal::Timeunit, Phonal::Pitch, Textural::Monophonic >
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MonophonicTimeunit ( bool i_IsRest ) noexcept;
      MonophonicTimeunit ( MonophonicTimeunit const & ) noexcept = default;
      MonophonicTimeunit ( MonophonicTimeunit && ) noexcept      = default;
      ~MonophonicTimeunit () noexcept                            = default;

      MonophonicTimeunit & operator= ( MonophonicTimeunit const & ) noexcept = default;
      MonophonicTimeunit & operator= ( MonophonicTimeunit && ) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      bool isRest () const;

   private:
      bool m_IsRest;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::wostream & operator<< ( std::wostream & io_OS, MonophonicTimeunit const & i_Timeunit );
}
