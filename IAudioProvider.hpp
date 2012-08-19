#ifndef IAUDIOPROVIDER_H
#define IAUDIOPROVIDER_H

#include "stdafx.h"
#include <string>

//Abstract class for Audio Provider. Could derive a class from this for each sound engine you may want to use
class IAudioProvider
{
public:
    virtual void PlaySound(std::string filename) = 0;
    virtual void PlaySong(std::string filename, bool looping) = 0;
    virtual void StopAllSounds() = 0;

    virtual bool IsSoundPlaying() = 0;
    virtual bool IsSongPlaying() = 0;
};

#endif