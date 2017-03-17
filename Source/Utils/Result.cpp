/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 13, 2017
 Namespace : FXG::Stretto
 Content   : class Result
\**************************************************************************************************/

#include <FXG/Stretto/Result.h>

namespace FXG::Stretto
{
   /************************************************************************/
   /* Factory methods                                                      */
   /************************************************************************/

   Result Result::ok() noexcept
   {
      return Result{ "" };
   }

   Result Result::fail(std::string const & a_ErrorMsg) noexcept
   {
      return Result{ a_ErrorMsg.empty() ? "Unknown error" : a_ErrorMsg };
   }


   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Result::Result(std::string const & a_ErrorMsg) noexcept
   : m_ErrorMsg{ a_ErrorMsg }
   {
   }

   Result::Result(Result const & a_RHS) noexcept
   : m_ErrorMsg{ a_RHS.m_ErrorMsg }
   {
   }

   Result & Result::operator=(Result const & a_RHS) noexcept
   {
      m_ErrorMsg = a_RHS.m_ErrorMsg;
   }


   /************************************************************************/
   /* Conversion operators                                                 */
   /************************************************************************/

   Result::operator bool() const noexcept
   {
      return success();
   }

   bool Result::operator!() const noexcept
   {
      return failure();
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   std::string const & Result::getErrorMessage() const noexcept
   {
      return m_ErrorMsg;
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool Result::success() const noexcept
   {
      return getErrorMessage().empty();
   }

   bool Result::failure() const noexcept
   {
      return !success();
   }
}
