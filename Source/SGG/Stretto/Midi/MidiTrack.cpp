#include <SGG/Stretto/Midi/MidiTrack.h>

namespace SGG::Stretto::Midi
{
   /************************************************************************/
   /* Add                                                                  */
   /************************************************************************/

   Result MidiTrack::addNoteEvent ( Theory::BasicNote const & i_Note, TimeUnit i_Time )
   {
      // TODO_SGG s'assurer de ne pas avoir deux fois la même note superposée
      m_Notes.emplace ( i_Note, i_Time );

      return Result::ok ();
   }

   Result MidiTrack::addInstrumentChange ( MidiInstrument i_Instr, TimeUnit i_Time )
   {
      ERROR_ON_FALSE ( m_InstrChanges.emplace ( i_Instr, i_Time ).second,
                       L"Cannot have two instrument changes at the same timeunit" );

      return Result::ok ();
   }
}
