#pragma once
#include "../MouseHandle/mouseHandle.h"
#include "../UIElement/uiElement.h"
namespace gui
{
class Button : public UIElement
{
public:
    sf::Vector2f getSize() { return box.getSize(); };

    std::pair<bool, bool> isPressed();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const;

    virtual void setSize(sf::Vector2f size);
    virtual void setPosition(sf::Vector2f position);

    Button(sf::Vector2f padding, sf::Vector2f size, sf::Color color, sf::RenderWindow* window);
protected:
    sf::RectangleShape box;
    MouseHandle mouseHandle;
};
}