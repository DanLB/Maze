#include "stdafx.h"
#include "ImageCache.h"

ImageCache::ImageCache(void) {}

//Free memory
ImageCache::~ImageCache(void)
{
    std::for_each(mImages.begin(), mImages.end(), Deallocator<sf::Image*>());
    
    for (std::map<sf::Color, sf::Image*, CompareColor>::iterator itr = mColors.begin(); itr != mColors.end(); ++itr)
    {
        delete itr->second;
    }
}

//If sound exists already, return it; else load and then return it
sf::Image* ImageCache::GetImage(std::string imageName) const
{
    std::map<std::string, sf::Image*>::iterator itr = mImages.find(imageName);
    if (itr == mImages.end())
    {
        sf::Image *image = new sf::Image();
        if (!image->LoadFromFile(imageName))
        {
            delete image;
            throw ImageNotFoundException(imageName + " was not found in call to ImageCache::GetSound");
        }

        std::map<std::string, sf::Image*>::iterator res = mImages.insert(std::pair<std::string, sf::Image*>(imageName, image)).first;

        return image;
    }
    else
    {
        return itr->second;
    }

    throw ImageNotFoundException(imageName + " was not found in call to ImageCache::GetSound");
}

sf::Image* ImageCache::GetColor(int width, int height, sf::Color color) const
{
    std::map<sf::Color, sf::Image*, CompareColor>::iterator itr;

    for (itr = mColors.begin(); itr != mColors.end(); ++itr)
    {
        if (itr->first == color)
            if (itr->second->GetWidth() == width && itr->second->GetHeight() == height)
                return itr->second;
    }
    sf::Image *image = new sf::Image(width, height, color);

    std::map<sf::Color, sf::Image*, CompareColor>::iterator res = mColors.insert(std::pair<sf::Color, sf::Image*>(color, image)).first;

    return image;
}

//std::map for containing sounds and their name
std::map<std::string, sf::Image*> ImageCache::mImages;
std::map<sf::Color, sf::Image*, CompareColor> ImageCache::mColors;