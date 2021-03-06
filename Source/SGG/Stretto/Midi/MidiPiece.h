/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 StainedGlassGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation    : October 1, 2017
 Project     : Midi
 Summary     : NA
 Description : NA
\**************************************************************************************************/

#pragma once

#include <SGG/Stretto/Midi/Event.h>
#include <SGG/Stretto/Midi/MidiTrack.h>
#include <SGG/Stretto/Theory/Elementary/TimeSignature.h>
#include <SGG/Utils/Result.h>
#include <SGG/Utils/StdAliases.h>

namespace SGG::Stretto::Midi
{
   using TempoBPM            = uint32_t;
   using TempoChange         = Event< TempoBPM >;
   using TimeSignatureChange = Event< Theory::TimeSignature >;

   class MidiPiece final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MidiPiece ()                    = default;
      MidiPiece ( MidiPiece const & ) = default;
      MidiPiece ( MidiPiece && )      = default;
      ~MidiPiece () noexcept          = default;

      MidiPiece & operator= ( MidiPiece const & ) = default;
      MidiPiece & operator= ( MidiPiece && ) noexcept = default;


      /************************************************************************/
      /* Add                                                                  */
      /************************************************************************/

      void addTrack ( MidiTrack && io_Track );
      Result addTempoChange ( TempoBPM i_BPM, TimeUnit i_Time );
      Result addTimeSignatureChange ( Theory::TimeSignature i_Sign, TimeUnit i_Time );


      /************************************************************************/
      /* Misc                                                                 */
      /************************************************************************/

      void clear ();

   private:
      Vec< MidiTrack >           m_Tracks;
      Set< TempoChange >         m_TempoChanges;
      Set< TimeSignatureChange > m_TimeSignatureChanges;
   };
}
