#pragma once
#include "SFML/Graphics.hpp"

namespace gui
{

class UIElement : public sf::Drawable
{   
public:
    sf::Vector2f getSize() { return size; };
    sf::Vector2f getPadding() { return padding; };

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const = 0;

    virtual void setSize(sf::Vector2f size) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;

    UIElement(sf::Vector2f padding, sf::Vector2f size);
protected:
    sf::Vector2f padding;
    sf::Vector2f size;
};

}