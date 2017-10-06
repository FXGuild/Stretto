#include <SGG/Stretto/Midi/MidiPiece.h>

namespace SGG::Stretto::Midi
{
   /************************************************************************/
   /* Tracks                                                               */
   /************************************************************************/

   void MidiPiece::addTrack ( MidiTrack && io_Track )
   {
      m_Tracks.emplace_back ( std::move ( io_Track ) );
   }


   /************************************************************************/
   /* Misc                                                                 */
   /************************************************************************/

   void MidiPiece::clear ()
   {
      m_Tracks.clear ();
   }
}
