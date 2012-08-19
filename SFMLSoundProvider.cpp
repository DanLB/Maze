#include "stdafx.h"
#include "SFMLSoundProvider.h"
// for when I decide to implement program options #include "Game.h"

SFMLSoundProvider::SFMLSoundProvider() :
mCurrentSongName("")
{}

void SFMLSoundProvider::PlaySound(std::string filename)
{
	//Find first available channel where a sound is not playing
    int availChannel = -1;
    for (int i = 0; i < MAX_SOUND_CHANNELS; ++i)
    {
        if (mCurrentSounds[i].GetStatus() != sf::Sound::Playing)
        {
            availChannel = i;
            break;
        }
    }

    //If all sound channels are in use, do nothing for now
    if (availChannel != -1)
    {
		//Load sound from cache and play it
        try
        {
            mCurrentSounds[availChannel] = mSoundFileCache.GetSound(filename);
            mCurrentSounds[availChannel].Play();
        }
        catch(SoundNotFoundExeception&)
        {
            //ERROR, file wasn't found, should handle error here
            //Currently, this will simply mean nothing happens if an error occurs
        }
    }
}

void SFMLSoundProvider::PlaySong(std::string filename, bool looping)
{
	//Load Song from Cache
    sf::Music * currentSong;
    try
    {
        currentSong = mSoundFileCache.GetSong(filename);
    }
    catch (SoundNotFoundExeception&)
    {
        //This one is dire, means we couldn't find or load the selected song
        //So, let's exit
        return;
    }
    //See if prior song is playing still, if so, stop it
    if (mCurrentSongName != "")
    {
        try
        {
            sf::Music* priorSong = mSoundFileCache.GetSong(mCurrentSongName);
            if (priorSong->GetStatus() != sf::Sound::Stopped)
            {
                priorSong->Stop();
            }
        }
        catch (SoundNotFoundExeception&)
        {
            //Do nothing, this exception isn't dire. It simply means the previous sound we were
            //trying to stop wasn't located
        }
    }
	//Set and Play Song.
    mCurrentSongName = filename;
    currentSong->SetLoop(looping);
    currentSong->Play();
}

void SFMLSoundProvider::StopAllSounds()
{
    for (int i = 0; i < MAX_SOUND_CHANNELS; ++i)
    {
        mCurrentSounds[i].Stop();
    }

    if (mCurrentSongName != "")
    {
        sf::Music* currentSong = mSoundFileCache.GetSong(mCurrentSongName);
        if (currentSong->GetStatus() == sf::Sound::Playing)
        {
            currentSong->Stop();
        }
    }
}

//Checks if any sound is playing
bool SFMLSoundProvider::IsSoundPlaying()
{
    for (int i = 0; i < MAX_SOUND_CHANNELS; ++i)
    {
        if (mCurrentSounds[i].GetStatus() == sf::Sound::Playing)
        return true;
    }
    return false;
}

bool SFMLSoundProvider::IsSongPlaying()
{
    if (mCurrentSongName != "")
    {
        return mSoundFileCache.GetSong(mCurrentSongName)->GetStatus() == sf::Music::Playing;
    }
    return false;
}
