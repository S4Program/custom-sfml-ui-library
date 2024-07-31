#pragma once
#include "../uiElement/uiElement.h"

namespace gui
{
class Label : public gui::UIElement
{
public:
    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f position);

    Label(sf::Vector2f padding, float characterSize, sf::Color textColor, sf::Color backColor, sf::Font* font, std::string message);
protected:
    sf::Text text;
    sf::RectangleShape backBox;
};
}