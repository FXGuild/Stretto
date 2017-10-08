#pragma once

#include <SGG/Stretto/Plugin/BuiltinPlugin/Hierarchy.h>
#include <SGG/Stretto/Schema/SchemaAPI.h>

namespace SGG::Stretto::Schema
{
   using namespace Plugin::BuiltinPlugin;

#define DECLARE_DUMMY_EXTRACTOR( dim, rankA, rankB )                                               \
                                                                                                   \
   template <>                                                                                     \
   struct Extractor< HierarchyID, dim, dim::rankA, dim::rankB >                                    \
   {                                                                                               \
      bool extract ()                                                                              \
      {                                                                                            \
         wprintf ( L"[%-15s] %-20s -> %s\n", L#dim, L#rankA, L#rankB );                            \
         return true;                                                                              \
      }                                                                                            \
   }

   DECLARE_DUMMY_EXTRACTOR ( Instrumentation, FullEnsemble, MidiInstrumentFamily );
   DECLARE_DUMMY_EXTRACTOR ( Instrumentation, MidiInstrumentFamily, MidiInstrument );
   DECLARE_DUMMY_EXTRACTOR ( Instrumentation, MidiInstrument, Part );
   DECLARE_DUMMY_EXTRACTOR ( Frequency, FullSpectrum, VoiceType );
   DECLARE_DUMMY_EXTRACTOR ( Frequency, VoiceType, Octave );
   DECLARE_DUMMY_EXTRACTOR ( Frequency, Octave, Pitch );
   DECLARE_DUMMY_EXTRACTOR ( Time, Piece, Chord );
   DECLARE_DUMMY_EXTRACTOR ( Time, Piece, Tempo );
   DECLARE_DUMMY_EXTRACTOR ( Time, Piece, TimeSignature );
   DECLARE_DUMMY_EXTRACTOR ( Time, Piece, MidiInstrument );
   DECLARE_DUMMY_EXTRACTOR ( Time, Chord, InBarChord );
   DECLARE_DUMMY_EXTRACTOR ( Time, Tempo, Bar );
   DECLARE_DUMMY_EXTRACTOR ( Time, TimeSignature, Bar );
   DECLARE_DUMMY_EXTRACTOR ( Time, MidiInstrument, Bar );
   DECLARE_DUMMY_EXTRACTOR ( Time, Bar, InBarChord );
   DECLARE_DUMMY_EXTRACTOR ( Time, InBarChord, NotationChord );
   DECLARE_DUMMY_EXTRACTOR ( Time, NotationChord, TimeUnit );
}
