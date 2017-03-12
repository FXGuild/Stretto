/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 11, 2017
 Namespace : FXG::Stretto::Utils
 Content   : String enum utilities
\**************************************************************************************************/

#include <sstream>
#include <vector>

#include <FXG/Stretto/Utils/StringEnum.h>

namespace FXG::Stretto::Utils
{
   std::vector<std::string> splitEnumValues(char const * a_Values)
   {
      std::string              name;
      std::vector<std::string> names;
      std::stringstream        ss(a_Values);

      std::getline(ss, name, ',');
      names.emplace_back(name);
      while (std::getline(ss, name, ','))
      {
         names.emplace_back(name.substr(1));
      }

      return names;
   }
}
