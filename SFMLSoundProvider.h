#pragma once

#include "IAudioProvider.h"
#include "SoundFileCache.h"

class SFMLSoundProvider : public IAudioProvider
{
public:
    SFMLSoundProvider();

    void PlaySound(std::string filename);
    void PlaySong(std::string filename, bool looping = false);
    void StopAllSounds();

    bool IsSoundPlaying();
    bool IsSongPlaying();

private:
	//Max number of sounds to be loaded at once
    static const int MAX_SOUND_CHANNELS = 5;

	//Cache to get sounds from
    SoundFileCache mSoundFileCache;

	//array of sounds
    sf::Sound mCurrentSounds[MAX_SOUND_CHANNELS];

	//Current Song, only want one
    std::string mCurrentSongName;
};
