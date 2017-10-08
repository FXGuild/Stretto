//#include <assert.h>
//
//#include <SGG/Stretto/Plugin/BuiltinPlugin/Fragment/MonophonicTimeunit.h>
//
//namespace SGG::Stretto::Plugin::Builtin
//{
//   /************************************************************************/
//   /* Constructors / Destructor / Assignment Operators                     */
//   /************************************************************************/
//
//   MonophonicTimeunit::MonophonicTimeunit ( bool i_IsRest ) noexcept
//   : m_IsRest{ i_IsRest }
//   {
//   }
//
//
//   /************************************************************************/
//   /* Getters                                                              */
//   /************************************************************************/
//
//   bool MonophonicTimeunit::isRest () const
//   {
//      return m_IsRest;
//   }
//
//
//   /************************************************************************/
//   /* Serialization                                                        */
//   /************************************************************************/
//
//   std::wostream & operator<< ( std::wostream & io_OS, MonophonicTimeunit const & i_Timeunit )
//   {
//      if ( i_Timeunit.isRest () )
//      {
//         io_OS << L"Rest";
//      }
//      else
//      {
//         io_OS << "Note";
//      }
//      return io_OS;
//   }
//}
