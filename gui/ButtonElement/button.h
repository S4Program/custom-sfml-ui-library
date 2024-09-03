#pragma once
#include "../MouseHandle/mouseHandle.h"
#include "../UIElement/uiElement.h"
#include "../LabelElement/labelElement.h"

namespace gui
{
class Button : public UIElement
{
public:
    sf::Vector2f getSize() { return box.getSize(); };
    virtual int getType() { return gui::BUTTON; };
    std::pair<bool, bool> checkMouseClick() { return isPressed(); };

    std::pair<bool, bool> isPressed();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    virtual void update();

    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f position);

    Button(sf::Vector2f padding, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor, sf::Color textColor, sf::RenderWindow* window, sf::Font* font, std::string label, float characterSize);
    Button(sf::Vector2f padding, sf::Vector2f size, sf::Color idleColor, sf::Color hoverColor, sf::RenderWindow* window);
protected:
    sf::RectangleShape box;

    MouseHandle mouseHandle;
    sf::Color hoverColor;
    sf::Color idleColor;

    gui::Label buttonLabel;
};
}