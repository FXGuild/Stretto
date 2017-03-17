/**************************************************************************************************\
MIT License
Copyright (c) 2017 FXGuild
See file "LICENSE.txt" at project root for complete license
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Creation  : March 13, 2017
Namespace : FXG::Stretto
Content   : class Result
\**************************************************************************************************/

#pragma once

#include <string>

namespace FXG::Stretto
{
   class Result final
   {
   public:
      /************************************************************************/
      /* Factory methods                                                      */
      /************************************************************************/

      static Result ok() noexcept;
      static Result fail(std::string const & a_ErrorMsg) noexcept;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Result(Result const &) noexcept;
      Result(Result &&) noexcept = default;
      ~Result() noexcept         = default;

      Result & operator=(Result const &) noexcept;
      Result & operator=(Result &&) noexcept = default;


      /************************************************************************/
      /* Conversion operators                                                 */
      /************************************************************************/

      operator bool() const noexcept;
      bool operator!() const noexcept;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      std::string const & getErrorMessage() const noexcept;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      bool success() const noexcept;
      bool failure() const noexcept;

   private:
      Result(std::string const & a_ErrorMsg) noexcept;

      std::string m_ErrorMsg;
   };
}
