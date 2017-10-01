/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : September 27, 2017
 Project     : Utils
 Summary     : Result
 Description : Voluntarily in the Utils namespace for ease of use
\**************************************************************************************************/

#pragma once

#include <SGG/Utils/StdAliases.h>

namespace SGG
{
#define ERROR_ON_FALSE( cond, errMsg )                                                             \
                                                                                                   \
   if ( !( cond ) )                                                                                \
   {                                                                                               \
      return Result::fail ( errMsg );                                                              \
   }                                                                                               \
   ( void ) 0


#define PROPAGATE_ERROR( resExpr, subErrMsg )                                                      \
                                                                                                   \
   const Result res{ ( resExpr ) };                                                                \
   if ( res.IsFailure () )                                                                         \
   {                                                                                               \
      return res;                                                                                  \
   }                                                                                               \
   ( void ) 0


#define PROPAGATE_ERROR( resExpr, subErrMsg )                                                      \
                                                                                                   \
   const Result res{ ( resExpr ) };                                                                \
   if ( res.IsFailure () )                                                                         \
   {                                                                                               \
      return Result::fail ( res.getErrorMessage () + L": " + ( subErrMsg ) );                      \
   }                                                                                               \
   ( void ) 0


   class Result final
   {
   public:
      /************************************************************************/
      /* Factory methods                                                      */
      /************************************************************************/

      static Result ok () noexcept;
      static Result fail ( String const & i_ErrorMsg ) noexcept;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Result ( Result const & ) noexcept;
      Result ( Result && ) noexcept = default;
      ~Result () noexcept           = default;

      Result & operator= ( Result const & ) noexcept;
      Result & operator= ( Result && ) noexcept = default;


      /************************************************************************/
      /* Conversion operators                                                 */
      /************************************************************************/

           operator bool () const noexcept;
      bool operator! () const noexcept;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      String const & getErrorMessage () const noexcept;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool IsSuccess () const noexcept;
      bool IsFailure () const noexcept;

   private:
      Result ( String const & i_ErrorMsg ) noexcept;

   private:
      String m_ErrorMsg;
   };
}
