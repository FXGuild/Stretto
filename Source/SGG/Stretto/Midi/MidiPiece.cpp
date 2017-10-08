#include <SGG/Stretto/Midi/MidiPiece.h>

namespace SGG::Stretto::Midi
{
   /************************************************************************/
   /* Add                                                                  */
   /************************************************************************/

   void MidiPiece::addTrack ( MidiTrack && io_Track )
   {
      m_Tracks.emplace_back ( std::move ( io_Track ) );
   }

   Result MidiPiece::addTempoChange ( TempoBPM i_BPM, TimeUnit i_Time )
   {
      ERROR_ON_FALSE ( m_TempoChanges.emplace ( i_BPM, i_Time ).second,
                       L"Cannot have two tempo changes at the same timeunit" );

      return Result::ok ();
   }

   Result MidiPiece::addTimeSignatureChange ( Theory::TimeSignature i_Sign, TimeUnit i_Time )
   {
      ERROR_ON_FALSE ( m_TimeSignatureChanges.emplace ( i_Sign, i_Time ).second,
                       L"Cannot have two time signature changes at the same timeunit" );

      return Result::ok ();
   }


   /************************************************************************/
   /* Misc                                                                 */
   /************************************************************************/

   void MidiPiece::clear ()
   {
      m_Tracks.clear ();
      m_TempoChanges.clear ();
      m_TimeSignatureChanges.clear ();
   }
}
