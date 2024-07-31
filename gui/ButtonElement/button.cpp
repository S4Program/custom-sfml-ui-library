#include "button.h"

std::pair<bool, bool> gui::Button::isPressed()
{
    return mouseHandle.isClicked();
}

void gui::Button::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
}

void gui::Button::setSize(sf::Vector2f size)
{
    box.setSize(size);
}

void gui::Button::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(box);
}

gui::Button::Button(sf::Vector2f padding, sf::Vector2f size, sf::Color color, sf::RenderWindow* window)
:
UIElement(padding, size),
mouseHandle(window, &box)
{
    box.setSize(size);
    box.setPosition(padding);
    box.setFillColor(color);
}