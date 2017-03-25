/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 27, 2017
 Namespace : FXG::Stretto
 Content   : Algorithm templates similar to std algorithms
\**************************************************************************************************/

#pragma once

namespace FXG::Stretto
{
   template <typename FwdIter, typename Func>
   Func for_each_overlapping_adjacent_pair(FwdIter a_ItBegin, FwdIter a_ItEnd, Func a_Func)
   {
      if (a_ItBegin == a_ItEnd)
      {
         return a_Func;
      }

      FwdIter itNext = a_ItBegin;
      ++itNext;

      while (itNext != a_ItEnd)
      {
         a_Func(*(a_ItBegin++), *(itNext++));
      }

      return a_Func;
   }
}
