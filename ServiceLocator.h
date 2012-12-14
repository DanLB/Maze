#ifndef SERVICELOCATOR_H
#define SERVICELOCATOR_H

#include "stdafx.h"
#include "IAudioProvider.h"
#include "ImageCache.h"

//Provides access to a AudioProvider
//could be used to provide access to all services. SFML, OpenGL, Audio, Networking, etc. Whatever is needed
class ServiceLocator
{
public:
	//Returns pointer to registered AudioProvider. Used to access Provider functions
	static IAudioProvider* GetAudio() {return mAudioProvider;} const

		static ImageCache* GetImgCache() {return mImageCache;} const

	//Registers service. Ensures there is only one service for each thing.
	static void RegisterServiceLocator(IAudioProvider *provider)
	{
		mAudioProvider = provider;
	}

	static void RegisterServiceLocator(ImageCache* cache)
	{
		mImageCache = cache;
	}

private:
	//Pointer to Service
	static IAudioProvider* mAudioProvider;
	static ImageCache* mImageCache;
};

#endif