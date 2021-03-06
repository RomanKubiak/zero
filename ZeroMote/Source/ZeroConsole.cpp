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

#include "ZeroConsole.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ZeroConsole::ZeroConsole ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (output = new TextEditor (String()));
    output->setMultiLine (true);
    output->setReturnKeyStartsNewLine (false);
    output->setReadOnly (true);
    output->setScrollbarsShown (true);
    output->setCaretVisible (false);
    output->setPopupMenuEnabled (false);
    output->setColour (TextEditor::textColourId, Colours::white);
    output->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    output->setText (TRANS("ZeroMote 1.0\n"));


    //[UserPreSize]
	output->setFont(Font(Font::getDefaultMonospacedFontName(), 10.0f, Font::plain));
	output->setText (TRANS("ZeroMote 1.0\n"));
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	Logger::setCurrentLogger(this);
    //[/Constructor]
}

ZeroConsole::~ZeroConsole()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	Logger::setCurrentLogger(nullptr);
    //[/Destructor_pre]

    output = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ZeroConsole::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x66000000));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void ZeroConsole::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    output->setBounds (0, 0, getWidth() - 0, getHeight() - 0);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ZeroConsole::logMessage(const String &message)
{
	MessageManagerLock mmlock;
	output->setCaretPosition(output->getText().length());
	output->insertTextAtCaret("\n");
	if (message.startsWith("ERR"))
		output->setColour(TextEditor::textColourId, Colour (0xffff696b));
	output->insertTextAtCaret(message.substring(3));
	output->setColour(TextEditor::textColourId, Colours::white);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ZeroConsole" componentName=""
                 parentClasses="public Component, public Logger" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="66000000"/>
  <TEXTEDITOR name="" id="a3b2308a344052bc" memberName="output" virtualName=""
              explicitFocusOrder="0" pos="0 0 0M 0M" textcol="ffffffff" bkgcol="0"
              initialText="ZeroMote 1.0&#10;" multiline="1" retKeyStartsLine="0"
              readonly="1" scrollbars="1" caret="0" popupmenu="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
