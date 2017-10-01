/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : March 12, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Theory/Elementary/Pitch.h>
#include <SGG/Stretto/Theory/Elementary/Quality.h>
#include <SGG/Utils/StringEnum.h>

namespace SGG::Stretto::Theory
{
   class Interval final
   {
   public:
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/

      enum class Number : uint8_t;
      enum class Direction : uint8_t;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      Interval ( Direction i_Direction, Quality i_Quality, Number i_Number ) noexcept;
      Interval ( Quality i_Quality, Number i_Number ) noexcept;
      Interval ( Number i_Number ) noexcept;
      Interval ( Interval const & ) noexcept = default;
      Interval ( Interval && ) noexcept      = default;
      ~Interval () noexcept                  = default;

      Interval & operator= ( Interval const & ) noexcept = default;
      Interval & operator= ( Interval && ) noexcept = default;


      /************************************************************************/
      /* Comparison operators                                                 */
      /************************************************************************/

      bool operator== ( Interval const & i_RHS ) const;
      bool operator!= ( Interval const & i_RHS ) const;
      bool operator< ( Interval const & i_RHS ) const;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Direction getDirection () const;
      Quality   getQuality () const;
      Number    getNumber () const;

   private:
      Direction m_Direction;
      Quality   m_Quality;
      Number    m_Number;
   };

   /************************************************************************/
   /* Utilities                                                            */
   /************************************************************************/

   Interval::Number normalize ( Interval::Number a_Number );
   Quality::Type    associatedQualityType ( Interval::Number a_Number );
}

/************************************************************************/
/* Nested types                                                         */
/************************************************************************/

/************************************************************************/
/* Interval::Number                                                     */
/************************************************************************/

DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE ( SGG::Stretto::Theory,
                                       Interval::Number,
                                       uint8_t,
                                       UNISON,
                                       SECOND,
                                       THIRD,
                                       FOURTH,
                                       FIFTH,
                                       SIXTH,
                                       SEVENTH,
                                       OCTAVE,
                                       NINTH,
                                       TENTH,
                                       ELEVENTH,
                                       TWELVTH,
                                       THIRTEENTH,
                                       FOURTEENTH,
                                       DOUBLE_OCTAVE )


/************************************************************************/
/* Interval::Direction                                                  */
/************************************************************************/

DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE (
   SGG::Stretto::Theory, Interval::Direction, uint8_t, DESCENDING, ASCENDING )
