/*
  ==============================================================================

    CopyThread.cpp
    Created: 3 Nov 2013 8:11:54pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#include "CopyThread.h"

void CopyThread::start(StringArray playlistFiles, String outputPath) {
    if (!this->isThreadRunning()) {
        this->playlistFiles = playlistFiles;
        this->outputPath = outputPath;
        this->startThread();
    }
}

void CopyThread::run() {
    File outputDirectory(outputPath);
    for (auto i = 0; i <= playlistFiles.size(); i++) {
        File playlistFile(playlistFiles[i]);
        File outputPlaylistFile(outputDirectory.getFullPathName() + "/" + playlistFile.getFileName());
        if (outputPlaylistFile.exists())
            outputPlaylistFile.deleteFile();
        StringArray lines;
        CopyMessage *message;
        playlistFile.readLines(lines);
        for (auto j = 0; j <= lines.size(); j++) {
            if (this->threadShouldExit()) {
                return;
            }
            File playlistContent(lines[j]);
            if (playlistContent.existsAsFile()) {
                if (outputDirectory.isDirectory()) {
                    if (j % 2) {
                        message = new CopyMessage();
                        message->status = ProgressStatus::running_even;
                        message->message = "Copy " + playlistContent.getFileName();
                        listener->postMessage(message);
                    } else {
                        message = new CopyMessage();
                        message->status = ProgressStatus::running_uneven;
                        message->message = "Copy " + playlistContent.getFileName();
                        listener->postMessage(message);
                    }
                    
                    File outputFile(outputDirectory.getFullPathName() + "/" + playlistContent.getFileName());
                    playlistContent.copyFileTo(outputFile);
                    outputPlaylistFile.appendText(playlistContent.getFileName() + NewLine::getDefault());
                }
            }
        }
        message = new CopyMessage();
        message->status = ProgressStatus::ready;
        message->message = "Done";
        listener->postMessage(message);
    }
}