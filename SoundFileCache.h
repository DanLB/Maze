#pragma once

#include "SFML/Audio.hpp"
#include <stdexcept>

//Class to implement and manange soundfilecache
class SoundFileCache
{
public:
    SoundFileCache(void);
    ~SoundFileCache(void);

	//Return Sound, loading if necessary
    sf::Sound GetSound(std::string) const;

	//return Song, loading if necessary
    sf::Music* GetSong(std::string) const;

private:
	//map for holding audio files and their name's
    static std::map<std::string, sf::SoundBuffer*> mSounds;
    static std::map<std::string, sf::Music*> mMusic;

	//way to Deallocate resources in std::for_each loop
    template <typename T>
    struct Deallocator
    {
        void operator() (const std::pair<std::string, T> &p)
        {
            delete p.second;
        }
    };
};

//Exceptions to be caught by SoundProvider
class SoundNotFoundExeception : public std::runtime_error
{
public:
    SoundNotFoundExeception(std::string const& msg):
    std::runtime_error(msg)
    {}
};
