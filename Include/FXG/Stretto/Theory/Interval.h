/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : March 12, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class Interval
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Result.h>
#include <FXG/Stretto/Theory/Pitch.h>
#include <FXG/Stretto/Theory/Quality.h>
#include <FXG/Stretto/StringEnum.h>

namespace FXG::Stretto::Theory
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

      Interval(Direction a_Direction, Quality a_Quality, Number a_Number) noexcept;
      Interval(Quality a_Quality, Number m_Number) noexcept;
      Interval(Number m_Number) noexcept;
      Interval(Interval const &) noexcept = default;
      Interval(Interval &&) noexcept      = default;
      ~Interval() noexcept                = default;

      Interval & operator=(Interval const &) noexcept = default;
      Interval & operator=(Interval &&) noexcept = default;


      /************************************************************************/
      /* Comparison operators                                                 */
      /************************************************************************/

      bool operator==(Interval const & a_RHS) const;
      bool operator!=(Interval const & a_RHS) const;
      bool operator<(Interval const & a_RHS) const;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Direction getDirection() const;
      Quality   getQuality() const;
      Number    getNumber() const;

   private:
      Direction m_Direction;
      Quality   m_Quality;
      Number    m_Number;
   };


   /************************************************************************/
   /* Nested types                                                         */
   /************************************************************************/

   /************************************************************************/
   /* Interval::Number                                                     */
   /************************************************************************/

   DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Interval::Number,
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
                                        DOUBLE_OCTAVE)


   /************************************************************************/
   /* Interval::Direction                                                  */
   /************************************************************************/

   DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE(Interval::Direction, uint8_t, DESCENDING, ASCENDING)


   /************************************************************************/
   /* Utilities                                                            */
   /************************************************************************/

   Interval::Number normalize(Interval::Number a_Number);
   Quality::Type associatedQualityType(Interval::Number a_Number);
}
