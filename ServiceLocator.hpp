#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#include "stdafx.h"
#include "IAudioProvider.h"

//Provides access to a AudioProvider
//could be used to provide access to all services. SFML, OpenGL, Audio, Networking, etc. Whatever is needed
class ServiceLocator
{
public:
	//Returns pointer to registered AudioProvider. Used to access Provider functions
    static IAudioProvider* GetAudio() {return mAudioProvider;} const

	//Registers service. Ensures there is only one service for each thing.
    static void RegisterServiceLocator(IAudioProvider *provider)
    {
        mAudioProvider = provider;
    }

private:
	//Pointer to Service
    static IAudioProvider* mAudioProvider;
};

#endif