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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "VLCWrapper.h"
class ZeroCommandManager;
//[/Headers]

#include "ZeroXYComponent.h"
#include "ZeroStatus.h"
#include "ZeroConsole.h"
#include "ZeroLiveStatus.h"
#include "ZeroMovingStatus.h"
#include "ZeroActionBar.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ZeroVideoOverlay  : public Component,
                          public VLCEventCallback,
                          public ChangeListener
{
public:
    //==============================================================================
    ZeroVideoOverlay (ZeroCommandManager *_zeroCommandManager);
    ~ZeroVideoOverlay();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void vlcTimeChanged(int64_t newTime);
	void vlcPaused();
	void vlcStarted();
	void vlcStopped();
	void changeListenerCallback(ChangeBroadcaster *b);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    bool keyPressed (const KeyPress& key) override;
    bool keyStateChanged (bool isKeyDown) override;
    void modifierKeysChanged (const ModifierKeys& modifiers) override;
    void focusGained (FocusChangeType cause) override;
    void focusLost (FocusChangeType cause) override;
    void focusOfChildComponentChanged (FocusChangeType cause) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ZeroCommandManager *zeroCommandManager;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ZeroXYComponent> cameraControl;
    ScopedPointer<ZeroStatus> status;
    ScopedPointer<ZeroConsole> zeroConsole;
    ScopedPointer<ZeroLiveStatus> liveStatus;
    ScopedPointer<ZeroMovingStatus> movingStatus;
    ScopedPointer<ZeroActionBar> actionBar;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZeroVideoOverlay)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
