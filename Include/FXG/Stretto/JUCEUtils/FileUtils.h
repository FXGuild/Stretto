/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 4, 2017
 Namespace : FXG::Stretto::Utils
 Content   : File browsing utilities
\**************************************************************************************************/

#pragma once

#include <string>

#include <Juce/Core.h>

namespace FXG::Stretto::Utils
{
   juce::File openFile(std::string const & a_Path);
}
