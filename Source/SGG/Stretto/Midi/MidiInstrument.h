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

#include <SGG/Utils/StringEnum.h>

DECLARE_STRING_ENUM ( SGG::Stretto::Midi,
                      MidiInstrumentFamily,

                      Piano,
                      ChromaticPercussion,
                      Organ,
                      Guitar,
                      Bass,
                      Strings,
                      Ensemble,
                      Brass,
                      Reed,
                      Pipe,
                      SynthLead,
                      SynthPad,
                      SynthEffects,
                      Ethnic,
                      Percussive,
                      SoundEffects );

DECLARE_STRING_ENUM ( SGG::Stretto::Midi,
                      MidiInstrument,

                      AcousticGrandPiano,
                      BrightAcousticPiano,
                      ElectricGrandPiano,
                      HonkytonkPiano,
                      ElectricPiano1,
                      ElectricPiano2,
                      Harpsichord,
                      Clavinet,

                      Celesta,
                      Glockenspiel,
                      MusicBox,
                      Vibraphone,
                      Marimba,
                      Xylophone,
                      TubularBells,
                      Dulcimer,

                      DrawbarOrgan,
                      PercussiveOrgan,
                      RockOrgan,
                      ChurchOrgan,
                      ReedOrgan,
                      Accordion,
                      Harmonica,
                      TangoAccordion,

                      AcousticGuitarNylon,
                      AcousticGuitarSteel,
                      ElectricGuitarJazz,
                      ElectricGuitarClean,
                      ElectricGuitarMuted,
                      OverdrivenGuitar,
                      DistortionGuitar,
                      GuitarHarmonics,

                      AcousticBass,
                      ElectricBassFinger,
                      ElectricBassPick,
                      FretlessBass,
                      SlapBass1,
                      SlapBass2,
                      SynthBass1,
                      SynthBass2,

                      Violin,
                      Viola,
                      Cello,
                      Contrabass,
                      TremoloStrings,
                      PizzicatoStrings,
                      OrchestralHarp,
                      Timpani,

                      StringEnsemble1,
                      StringEnsemble2,
                      SynthStrings1,
                      SynthStrings2,
                      ChoirAahs,
                      VoiceOohs,
                      SynthVoice,
                      OrchestraHit,

                      Trumpet,
                      Trombone,
                      Tuba,
                      MutedTrumpet,
                      FrenchHorn,
                      BrassSection,
                      SynthBrass1,
                      SynthBrass2,

                      SopranoSax,
                      AltoSax,
                      TenorSax,
                      BaritoneSax,
                      Oboe,
                      EnglishHorn,
                      Bassoon,
                      Clarinet,

                      Piccolo,
                      Flute,
                      Recorder,
                      PanFlute,
                      BlownBottle,
                      Shakuhachi,
                      Whistle,
                      Ocarina,

                      LeadSquare,
                      LeadSawtooth,
                      LeadCalliope,
                      LeadChiff,
                      LeadCharang,
                      LeadVoice,
                      LeadFifths,
                      LeadBassLead,

                      PadNewage,
                      PadWarm,
                      PadPolysynth,
                      PadChoir,
                      PadBowed,
                      PadMetallic,
                      PadHalo,
                      PadDweep,

                      FXRain,
                      FXSoundtrack,
                      FXCrystal,
                      FXAtmosphere,
                      FXBrightness,
                      FXGoblins,
                      FXEchoes,
                      FXScifi,

                      Sitar,
                      Banjo,
                      Shamisen,
                      Koto,
                      Kalimba,
                      Bagpipe,
                      Fiddle,
                      Shanai,

                      TinkleBell,
                      Agogo,
                      SteelDrums,
                      Woodblock,
                      TaikoDrum,
                      MelodicTom,
                      SynthDrum,
                      ReverseCymbal,

                      GuitarFretNoise,
                      BreathNoise,
                      Seashore,
                      BirdTweet,
                      TelephoneRing,
                      Helicopter,
                      Applause,
                      Gunshot );

namespace SGG::Stretto::Midi
{
   MidiInstrumentFamily getInstrumentFamily ( MidiInstrument const i_Instr );
}
