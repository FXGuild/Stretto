/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 25, 2017
 Namespace : FXG::Stretto::Theory
 Content   : class AggregatedNote
\**************************************************************************************************/

#pragma once

#include <FXG/Stretto/Theory/NoteDuration.h>
#include <FXG/Stretto/Theory/Pitch.h>

namespace FXG::Stretto::Theory
{
   class AggregatedNote final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      AggregatedNote(Pitch const & a_Pitch, uint32_t m_DurationTU) noexcept;
      AggregatedNote(AggregatedNote const &) noexcept = default;
      AggregatedNote(AggregatedNote &&) noexcept      = default;
      ~AggregatedNote() noexcept                      = default;

      AggregatedNote & operator=(AggregatedNote const &) noexcept = default;
      AggregatedNote & operator=(AggregatedNote &&) noexcept = default;


      /************************************************************************/
      /* Getters                                                              */
      /************************************************************************/

      Pitch const & getPitch() const;
      uint32_t      getDurationTU() const;

   private:
      Pitch    m_Pitch;
      uint32_t m_DurationTU;
   };


   /************************************************************************/
   /* Serialization                                                        */
   /************************************************************************/

   std::ostream & operator<<(std::ostream & a_OS, AggregatedNote const & a_Note);
}
