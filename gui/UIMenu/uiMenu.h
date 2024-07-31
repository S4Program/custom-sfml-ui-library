#pragma once
#include "SFML/Graphics.hpp"
#include "../UIElement/uiElement.h"
#include "../MouseHandle/mouseHandle.h"

#include <vector>
#include <cassert>

namespace gui
{   

class UIMenu : public sf::Drawable
{
public:
    virtual void toggle(bool arg);
    virtual void outlineMouseEvent();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates state) const = 0;

    virtual void addElement(UIElement* element);
    virtual void removeElement(int index);

    virtual void setSize(sf::Vector2f size) = 0;
    virtual void setPosition(sf::Vector2f position) = 0;

    UIMenu(sf::Vector2f size, sf::Vector2f position, sf::Color boxColor, sf::Color outlineColor, float outlineThickness, sf::RenderWindow* window);
protected:
typedef std::vector<gui::UIElement*> UIElements;
    UIElements elements;
    
//--- Box variables
    sf::RectangleShape box;
    sf::Vector2f size;
    sf::Vector2f position;

//--- Outline variables
    sf::RectangleShape outlineBox;
    MouseHandle outlineMouseHandle;
    float outlineThickness;

//--- States
    bool isVisible = true;
    bool isMenuSelected = false;

//--- Additional dependencies
    sf::Vector2f previousMousePos;
    sf::Vector2f startFOV;
};

}
