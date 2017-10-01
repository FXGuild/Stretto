/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 27, 2017
 Project     : Utils
 Summary     : Algorithm templates similar to std algorithms
 Description : NA
\**************************************************************************************************/

#pragma once

namespace SGG::Utils
{
   template < typename FwdIter, typename Func >
   Func for_each_overlapping_adjacent_pair ( FwdIter io_ItBegin, FwdIter io_ItEnd, Func io_Func )
   {
      if ( io_ItBegin == io_ItEnd )
      {
         return io_Func;
      }

      FwdIter itNext{ io_ItBegin };
      ++itNext;

      while ( itNext != io_ItEnd )
      {
         io_Func ( *( io_ItBegin++ ), *( itNext++ ) );
      }

      return io_Func;
   }
}
