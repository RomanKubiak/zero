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
#include "Zero.h"
class ZeroCommandManager;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ZeroMovingStatus  : public Component,
                          public ChangeListener,
                          public Timer
{
public:
    //==============================================================================
    ZeroMovingStatus (ZeroCommandManager *_zeroCommandManager);
    ~ZeroMovingStatus();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void setStatus(bool _up, bool _down, bool _left, bool _right, uint8_t _speed=-1);
	void changeListenerCallback(ChangeBroadcaster *b);
	void timerCallback();
	bool keyPressed (const KeyPress& key);
	bool keyStateChanged (bool isKeyDown);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	bool up, down, left, right;
	uint8_t speed;
	ZeroCommandManager *zeroCommandManager;
	bool upChanged, downChanged, leftChanged, rightChanged;
    //[/UserVariables]

    //==============================================================================
    Path internalPath1;
    Path internalPath2;
    Path internalPath3;
    Path internalPath4;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZeroMovingStatus)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
