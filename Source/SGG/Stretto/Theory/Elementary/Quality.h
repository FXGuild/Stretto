/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : February 25, 2017
 Project     : Theory
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Utils/StringEnum.h>

namespace SGG::Stretto::Theory
{
   /************************************************************************/
   /* Related types                                                        */
   /************************************************************************/

   enum class ImperfectQuality : uint8_t
   {
      MINOR = 0,
      MAJOR = 1
   };

   enum class PerfAugDimQuality : uint8_t
   {
      DIMINISHED = 2,
      PERFECT    = 3,
      AUGMENTED  = 4
   };

   class Quality final
   {
   public:
      /************************************************************************/
      /* Nested types                                                         */
      /************************************************************************/

      enum class Type : uint8_t;


      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      // Voluntarily non-explicit
      Quality ( ImperfectQuality i_ImperfectQuality ) noexcept;
      // Voluntarily non-explicit
      Quality ( PerfAugDimQuality i_PerfAugDimQuality ) noexcept;
      Quality ( Quality const & ) noexcept = default;
      Quality ( Quality && ) noexcept      = default;
      ~Quality () noexcept                 = default;

      Quality & operator= ( Quality const & ) noexcept = default;
      Quality & operator= ( Quality && ) noexcept = default;


      /************************************************************************/
      /* Comparison operators                                                 */
      /************************************************************************/

      bool operator== ( Quality const & i_RHS ) const;
      bool operator!= ( Quality const & i_RHS ) const;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      ImperfectQuality  getImperfectQuality () const;
      PerfAugDimQuality getPerfAugDimQuality () const;


      /************************************************************************/
      /* Status                                                               */
      /************************************************************************/

      Type getQualityType () const;

   private:
      uint8_t m_Quality;
   };
}

/************************************************************************/
/* Nested types                                                         */
/************************************************************************/

DECLARE_STRING_ENUM_OF_EXPLICIT_TYPE (
   SGG::Stretto::Theory, Quality::Type, uint8_t, IMPERFECT, PERF_AUG_DIM )
