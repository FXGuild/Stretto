#include <SGG/Stretto/Midi/MidiTrack.h>

namespace SGG::Stretto::Midi
{
   /************************************************************************/
   /* Add                                                                  */
   /************************************************************************/

   void MidiTrack::addNoteEvent ( NoteEvent const & i_NoteEvent )
   {
      // TODO s'assurer de ne pas avoir deux fois la m�me note superpos�e
      m_Notes.emplace ( i_NoteEvent );
   }

   void MidiTrack::addInstrumentChange ( InstrumentChange const & i_InstrChange )
   {
      // TODO s'assurer qu'il y a bien une exception quand il y a deux changement en m�me temps
      m_InstrChanges.emplace ( i_InstrChange );
   }
}
