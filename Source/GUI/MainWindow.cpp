/**************************************************************************************************\
 MIT License
 Copyright (c) 2017 FXGuild
 See file "LICENSE.txt" at project root for complete license
 - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 Creation  : February 26, 2017
 Namespace : FXG::Stretto::GUI
 Content   : class MainWindow
\**************************************************************************************************/

#include <FXG/Stretto/GUI/Internal/MainComponent.h>
#include <FXG/Stretto/GUI/Internal/MainWindow.h>

namespace FXG::Stretto::GUI
{
   /************************************************************************/
   /* Constructors / Destructor / Assignment Operators                     */
   /************************************************************************/

   MainWindow::MainWindow()
   : juce::DocumentWindow{ "Stretto", juce::Colours::darkgrey, juce::DocumentWindow::allButtons,
                           true }
   {
      setUsingNativeTitleBar(true);
      setContentOwned(new MainComponent(), true);
      centreWithSize(getWidth(), getHeight());
      setVisible(true);
   }


   /************************************************************************/
   /* GUI callbacks                                                        */
   /************************************************************************/

   void MainWindow::closeButtonPressed()
   {
      juce::JUCEApplication::quit();
   }
}
