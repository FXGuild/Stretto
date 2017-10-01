#include <SGG/Utils/Result.h>

namespace SGG
{
   /************************************************************************/
   /* Factory methods                                                      */
   /************************************************************************/

   Result Result::ok () noexcept
   {
      return { L"" };
   }

   Result Result::fail ( String const & i_ErrorMsg ) noexcept
   {
      return { i_ErrorMsg.empty () ? L"Unknown error" : i_ErrorMsg };
   }


   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   Result::Result ( String const & i_ErrorMsg ) noexcept
   : m_ErrorMsg{ i_ErrorMsg }
   {
   }

   Result::Result ( Result const & a_RHS ) noexcept
   : m_ErrorMsg{ a_RHS.m_ErrorMsg }
   {
   }

   Result & Result::operator= ( Result const & i_RHS ) noexcept
   {
      m_ErrorMsg = i_RHS.m_ErrorMsg;
      return *this;
   }


   /************************************************************************/
   /* Conversion operators                                                 */
   /************************************************************************/

   Result::operator bool () const noexcept
   {
      return IsSuccess ();
   }

   bool Result::operator! () const noexcept
   {
      return IsFailure ();
   }


   /************************************************************************/
   /* Getters                                                              */
   /************************************************************************/

   std::wstring const & Result::getErrorMessage () const noexcept
   {
      return m_ErrorMsg;
   }


   /************************************************************************/
   /* Status                                                               */
   /************************************************************************/

   bool Result::IsSuccess () const noexcept
   {
      return getErrorMessage ().empty ();
   }

   bool Result::IsFailure () const noexcept
   {
      return !IsSuccess ();
   }
}
