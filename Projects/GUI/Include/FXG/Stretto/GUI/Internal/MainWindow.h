/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainWindow
\**************************************************************************************************/

#pragma once

#include <JuceHeader.h>

namespace FXG::Stretto::GUI
{
   class MainWindow final : public juce::DocumentWindow
   {
   public:
      /************************************************************************/
      /* Constructors / Destructor / Assignment Operators                     */
      /************************************************************************/

      MainWindow();
      ~MainWindow() = default;


      /************************************************************************/
      /* GUI callbacks                                                        */
      /************************************************************************/

      void closeButtonPressed() override;

   private:
      JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
   };
}
