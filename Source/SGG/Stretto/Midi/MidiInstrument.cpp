#include <SGG/Stretto/Midi/MidiInstrument.h>

namespace SGG::Stretto::Midi
{
   MidiInstrumentFamily getInstrumentFamily ( MidiInstrument const i_Instr )
   {
      return MidiInstrumentFamily ( static_cast< uint32_t >( i_Instr ) % 8 );
   }
}
