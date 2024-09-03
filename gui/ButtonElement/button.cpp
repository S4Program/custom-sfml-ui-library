#include "button.h"

std::pair<bool, bool> gui::Button::isPressed()
{
    if(mouseHandle.isHovered()) 
    {
        box.setFillColor(hoverColor);
    }
    else
    {
        box.setFillColor(idleColor);
    }
    return mouseHandle.isClicked();
}

void gui::Button::setPosition(sf::Vector2f position)
{
    box.setPosition(position);
    buttonLabel.setPosition(position + buttonLabel.getPadding());
}

void gui::Button::setSize(sf::Vector2f size)
{
    box.setSize(size);
    buttonLabel.setSize(size);
}

void gui::Button::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(box);
    window.draw(buttonLabel);
}

void gui::Button::update()
{
    isPressed();
}

gui::Button::Button(sf::Vector2f padding, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor, sf::Color textColor, sf::RenderWindow* window, sf::Font* font, std::string label, float characterSize)
:
UIElement(padding, size),
mouseHandle(window, &box),
hoverColor(hoverColor),
idleColor(idleColor),
buttonLabel(sf::Vector2f((size.x - gui::Label(sf::Vector2f(0,0), characterSize, textColor, font, label).getSize().x) * 0.5f, (size.y - gui::Label(sf::Vector2f(0,0), characterSize, textColor, font, label).getSize().y) * 0.5f), characterSize, textColor, font, label)
{
    box.setSize(size);
    box.setPosition(padding);
    box.setFillColor(idleColor);
}

gui::Button::Button(sf::Vector2f padding, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor, sf::RenderWindow* window)
:
UIElement(padding, size),
mouseHandle(window, &box),
hoverColor(hoverColor),
idleColor(idleColor),
buttonLabel()
{
    box.setSize(size);
    box.setPosition(padding);
    box.setFillColor(idleColor);
}