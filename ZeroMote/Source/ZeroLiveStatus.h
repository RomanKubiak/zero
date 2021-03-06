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
#include "ZeroCommandManager.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class ZeroLiveStatus  : public Component,
                        public Timer,
                        public ZeroCommandManager::Listener,
                        public TableListBoxModel
{
public:
    //==============================================================================
    ZeroLiveStatus (ZeroCommandManager *_zeroCommandManager);
    ~ZeroLiveStatus();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
	void liveDataUpdated(const MemoryBlock &data);
	int getNumRows() override;
	void paintCell (Graphics &g, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
	void paintRowBackground (Graphics &g, int rowNumber, int width, int height, bool rowIsSelected) override;
	bool debugUpdate(DynamicObject *o);
	bool runtimeUpdate(DynamicObject *o);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void visibilityChanged() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	ZeroCommandManager *zeroCommandManager;
	StringPairArray params;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TableListBox> list;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ZeroLiveStatus)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
