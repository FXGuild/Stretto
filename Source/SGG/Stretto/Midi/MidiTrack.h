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

      void addNoteEvent ( NoteEvent const & i_NoteEvent );
      void addInstrumentChange ( InstrumentChange const & i_InstrChange );

   private:
      /************************************************************************/
      /* Fields                                                               */
      /************************************************************************/

      MSet< NoteEvent >       m_Notes;
      Set< InstrumentChange > m_InstrChanges;
   };
}
