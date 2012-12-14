#include "stdafx.h"
#include "Servicelocator.h"

//static variable
IAudioProvider* ServiceLocator::mAudioProvider = nullptr;
ImageCache* ServiceLocator::mImageCache = nullptr;