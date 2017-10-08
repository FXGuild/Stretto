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
#include <SGG/Stretto/Midi/MidiInstrument.h>
#include <SGG/Stretto/Theory/Elementary/BasicNote.h>
#include <SGG/Utils/Result.h>

namespace SGG::Stretto::Midi
{
   using NoteEvent        = Event< Theory::BasicNote >;
   using InstrumentChange = Event< MidiInstrument >;

   class MidiTrack final
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MidiTrack ()                    = default;
      MidiTrack ( MidiTrack const & ) = default;
      MidiTrack ( MidiTrack && )      = default;
      ~MidiTrack () noexcept          = default;

      MidiTrack & operator= ( MidiTrack const & ) = default;
      MidiTrack & operator= ( MidiTrack && ) noexcept = default;


      /************************************************************************/
      /* Add                                                                  */
      /************************************************************************/

      Result addNoteEvent ( Theory::BasicNote const & i_Note, TimeUnit i_Time );
      Result addInstrumentChange ( MidiInstrument i_Instr, TimeUnit i_Time );

   private:
      /************************************************************************/
      /* Fields                                                               */
      /************************************************************************/

      MSet< NoteEvent >       m_Notes;
      Set< InstrumentChange > m_InstrChanges;
   };
}
