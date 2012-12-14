//Incomplete

#include "stdafx.h"
#include "IGui.h"
#include "ServiceLocator.h"

IGui::IGui(sf::Image* img, sf::Vector2f loc): location(loc)
{
    image = img;

    sprite.SetImage(*image);
    sprite.SetCenter(image->GetWidth() / 2.0f, image->GetHeight() / 2.0f);
    sprite.SetPosition(location);
    boundingBox = sf::Rect<int>(location.x - image->GetWidth() / 2.0f, location.y - image->GetHeight() / 2.0f, location.x + image->GetWidth() / 2.0f, location.y + image->GetHeight() / 2.0f);

    id = s_id;
    s_id++;
}

IGui::~IGui()
{}

//TODO figure out if this works - Make this make more sense
void IGui::ChangeImage(sf::Image* newImage)
{
    image = newImage;

    sprite.SetImage(*(this->image));
    sprite.SetCenter(this->image->GetWidth() / 2.0f, this->image->GetHeight() / 2.0f);

    //redundant with below
    sf::Vector2f location = sprite.GetPosition();
    location.x -= image->GetWidth() / 2.0f;
    location.y -= image->GetHeight() / 2.0f;

    boundingBox = sf::Rect<int>(static_cast<int>(location.x),
        static_cast<int>(location.y),
        static_cast<int>(location.x + image->GetWidth()),
        static_cast<int>(location.y + image->GetHeight()));

    //redudant with above
    location.x += image->GetWidth() / 2.0f;
    location.y += image->GetHeight() / 2.0f;
}

void IGui::Draw(sf::RenderWindow& window)
{
    window.Draw(sprite);
}

bool IGui::IsClicked(sf::Vector2f mouse)
{
    if (boundingBox.Contains(static_cast<int>(location.x), static_cast<int>(location.y)))
        return true;
    else
        return false;
}

int IGui::GetId()
{
    return id;
}

int IGui::s_id = 0;