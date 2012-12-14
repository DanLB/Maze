//Incomplete

#ifndef IMAGECACHE_H
#define IMAGECACHE_H

//Didn't include max amt of images or any other memory management. don't anticipate ever using that much space.

#include "SFML/Graphics.hpp"
#include <stdexcept>
#include "CompareColor.h"

//Use ServiceLocator::GetImgCache()->GetImage("filename");
//Or BlahBlah->GetColor(width, height, sf::Color)

class ImageCache
{
public:
    ImageCache();
    ~ImageCache();

    //Return Image, load if necessary
    sf::Image* GetImage(std::string) const;
    sf::Image* GetColor(int, int, sf::Color) const;

private:
    static std::map<std::string, sf::Image*> mImages;
    static std::map<sf::Color, sf::Image*, CompareColor> mColors;
    
    //Deallocate in std::for_each loop
    template <typename T>
    struct Deallocator
    {
        void operator() (const std::pair<std::string, T> &p)
        {
            delete p.second;
        }
    };
};

class ImageNotFoundException : public std::runtime_error
{
public:
    ImageNotFoundException(std::string const& msg):
      std::runtime_error(msg)
      {}
};

#endif