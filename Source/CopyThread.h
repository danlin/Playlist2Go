/*
  ==============================================================================

    CopyThread.h
    Created: 3 Nov 2013 8:11:54pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#ifndef COPYTHREAD_H_INCLUDED
#define COPYTHREAD_H_INCLUDED

#include "JuceHeader.h"

enum ProgressStatus {
    drag,
    running_even,
    running_uneven,
    ready
};

class CopyMessage : public Message {
public:
    ProgressStatus status;
    String message;
};

class CopyThread : public Thread {
public:
    CopyThread(MessageListener *listener)
    :Thread("Playlist2Go CopyThread")
    {
        this->listener = listener;
    }
    void run();
    void start(StringArray playlistFiles, String outputPath);
private:
    StringArray playlistFiles;
    String outputPath;
    MessageListener *listener;
};



#endif  // COPYTHREAD_H_INCLUDED
