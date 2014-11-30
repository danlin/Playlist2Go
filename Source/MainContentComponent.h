/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_92E596E9AF51CD06__
#define __JUCE_HEADER_92E596E9AF51CD06__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "CopyThread.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainContentComponent  : public Component,
                              public FileDragAndDropTarget,
                              public MessageListener
{
public:
    //==============================================================================
    MainContentComponent ();
    ~MainContentComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    bool isInterestedInFileDrag (const StringArray& files);
    void filesDropped (const StringArray& files, int x, int y);
    void handleMessage (const Message& message);
    ScopedPointer<CopyThread> copyTread;
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

    // Binary resources:
    static const char* drop_file_png;
    static const int drop_file_pngSize;
    static const char* ready_png;
    static const int ready_pngSize;
    static const char* running_png;
    static const int running_pngSize;
    static const char* running2_png;
    static const int running2_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Image cachedImage_running_png;
    Image cachedImage_running2_png;
    Image cachedImage_ready_png;
    ProgressStatus status;
    String message;
    //[/UserVariables]

    //==============================================================================
    Image cachedImage_drop_file_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};

//[EndFile] You can add extra defines here...

//[/EndFile]

#endif   // __JUCE_HEADER_92E596E9AF51CD06__
