#pragma once
#include "SFML/Graphics.hpp"
#include "elementList.h"

namespace gui
{

class UIElement : public sf::Drawable
{   
public:
    virtual sf::Vector2f getSize() { return size; };
    virtual sf::Vector2f getPadding() { return padding; };
    virtual int getType() = 0;

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const = 0;
    virtual void update() {};

    virtual void setSize(sf::Vector2f size) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;

    UIElement(sf::Vector2f padding, sf::Vector2f size = sf::Vector2f(0,0));
protected:
    sf::Vector2f padding;
    sf::Vector2f size;
};

}