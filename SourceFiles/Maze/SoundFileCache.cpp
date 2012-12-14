#include "stdafx.h"
#include "SoundFileCache.h"

SoundFileCache::SoundFileCache(void) {}

//Free memory
SoundFileCache::~SoundFileCache(void)
{
    std::for_each(mSounds.begin(), mSounds.end(), Deallocator<sf::SoundBuffer*>());
    std::for_each(mMusic.begin(), mMusic.end(), Deallocator<sf::Music*>());
}

//If sound exists already, return it; else load and then return it
sf::Sound SoundFileCache::GetSound(std::string soundName) const
{
    std::map<std::string, sf::SoundBuffer*>::iterator itr = mSounds.find(soundName);
    if (itr == mSounds.end())
    {
        sf::SoundBuffer *soundBuffer = new sf::SoundBuffer();
        if (!soundBuffer->LoadFromFile(soundName))
        {
            delete soundBuffer;
            throw SoundNotFoundExeception(soundName + " was not found in call to SoundFileCache::GetSound");
        }

        std::map<std::string, sf::SoundBuffer*>::iterator res = mSounds.insert(std::pair<std::string, sf::SoundBuffer*>(soundName, soundBuffer)).first;

        sf::Sound sound;
        sound.SetBuffer(*soundBuffer);
        return sound;
    }
    else
    {
        sf::Sound sound;
        sound.SetBuffer(*itr->second);
        return sound;
    }

    throw SoundNotFoundExeception(soundName + " was not found in call to SoundFileCache::GetSound");
}

//Same as GetSound() only for songs
sf::Music* SoundFileCache::GetSong(std::string soundName) const
{
    std::map<std::string, sf::Music*>::iterator itr = mMusic.find(soundName);
    if (itr == mMusic.end())
    {
        sf::Music* song = new sf::Music();
        if (!song->OpenFromFile(soundName))
        {
            delete song;
            throw SoundNotFoundExeception(soundName + " was not found in call to SoundFileCache::GetSong");
        }
        else
        {
            std::map<std::string, sf::Music*>::iterator res = mMusic.insert(std::pair<std::string, sf::Music*>(soundName, song)).first;
            return res->second;
        }
    }
    else
    {
        return itr->second;
    }

    throw SoundNotFoundExeception(soundName + "was not found in call to SoundFileCache::GetSong");
}

//std::map for containing sounds and their name
std::map<std::string, sf::SoundBuffer*> SoundFileCache::mSounds;
std::map<std::string, sf::Music*> SoundFileCache::mMusic;
