/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "ZeroMain.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "ZeroVideoOverlay.h"
#include "ZeroCommandManager.h"
//[/MiscUserDefs]

//==============================================================================
ZeroMain::ZeroMain (ZeroVideoOverlay *_overlay, ZeroCommandManager *_zeroCommandManager)
    : overlay(_overlay), zeroCommandManager(_zeroCommandManager)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (vlc = new VLCWrapper());


    //[UserPreSize]
	vlc->attachCallback(overlay);
	vlc->setVisible(false);
    //[/UserPreSize]

    setSize (600, 480);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

ZeroMain::~ZeroMain()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    vlc = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
	Logger::setCurrentLogger(nullptr);
    //[/Destructor]
}

//==============================================================================
void ZeroMain::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ZeroMain::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    vlc->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
	overlay->setSize(vlc->getWidth(), vlc->getHeight());
    //[/UserResized]
}

void ZeroMain::moved()
{
    //[UserCode_moved] -- Add your code here...
    //[/UserCode_moved]
}

bool ZeroMain::keyPressed (const KeyPress& key)
{
    //[UserCode_keyPressed] -- Add your code here...
	_DBG("ZeroMain::keyPressed\n");
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyPressed]
}

bool ZeroMain::keyStateChanged (bool isKeyDown)
{
    //[UserCode_keyStateChanged] -- Add your code here...
	_DBG("ZeroMain::keyStateChanged\n");
    return false;  // Return true if your handler uses this key event, or false to allow it to be passed-on.
    //[/UserCode_keyStateChanged]
}

void ZeroMain::modifierKeysChanged (const ModifierKeys& modifiers)
{
    //[UserCode_modifierKeysChanged] -- Add your code here...
    //[/UserCode_modifierKeysChanged]
}

void ZeroMain::focusGained (FocusChangeType cause)
{
    //[UserCode_focusGained] -- Add your code here...
    //[/UserCode_focusGained]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ZeroMain::handleAsyncUpdate()
{
}

void ZeroMain::connectedToRobot()
{
	if (zeroCommandManager->isConnected())
	{
		RemoteRobotItem robot = zeroCommandManager->getCurrentRobot();
		_DBG("Video url: " + robot.videoUrl.toString(true));
		vlc->stop();
		vlc->loadMedia(robot.videoUrl.toString(true));
		vlc->play();
		vlc->setVisible(true);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ZeroMain" componentName=""
                 parentClasses="public Component, public AsyncUpdater, public ZeroCommandManager::Listener"
                 constructorParams="ZeroVideoOverlay *_overlay, ZeroCommandManager *_zeroCommandManager"
                 variableInitialisers="overlay(_overlay), zeroCommandManager(_zeroCommandManager)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="480">
  <METHODS>
    <METHOD name="moved()"/>
    <METHOD name="keyStateChanged (bool isKeyDown)"/>
    <METHOD name="keyPressed (const KeyPress&amp; key)"/>
    <METHOD name="modifierKeysChanged (const ModifierKeys&amp; modifiers)"/>
    <METHOD name="focusGained (FocusChangeType cause)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff323e44"/>
  <GENERICCOMPONENT name="" id="8a738eb729bd9b3d" memberName="vlc" virtualName=""
                    explicitFocusOrder="0" pos="0 0 100% 100%" class="VLCWrapper"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
