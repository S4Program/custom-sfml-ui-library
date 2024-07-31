#include "uiMenu.h"

void gui::UIMenu::toggle(bool arg)
{
    isVisible = arg;
}

void gui::UIMenu::outlineMouseEvent()
{
    if(isMenuSelected)
    {
        setPosition(outlineBox.getPosition() + outlineMouseHandle.getMousePos() - previousMousePos);
    }

    if(outlineMouseHandle.isClicked().first || outlineMouseHandle.isPressed().first && isMenuSelected)
    {
        previousMousePos = outlineMouseHandle.getMousePos();
        isMenuSelected = true;
    }
    else 
    {
        isMenuSelected = false;
    }
}

void gui::UIMenu::addElement(UIElement* element)
{
    elements.push_back(element);
}

void gui::UIMenu::removeElement(int index)
{
    assert(index >= 0 && index < elements.size());
    elements.erase(elements.begin() + index);
}

gui::UIMenu::UIMenu(sf::Vector2f size, sf::Vector2f position, sf::Color boxColor, sf::Color outlineColor, float outlineThickness, sf::RenderWindow* window)
:
startFOV(window->getView().getSize()),
size(size),
position(position),
outlineThickness(outlineThickness),
outlineMouseHandle(window, &outlineBox)
{
    box.setSize(size);
    box.setPosition(sf::Vector2f(position.x, position.y + outlineThickness) );
    box.setFillColor(boxColor);

    outlineBox.setPosition(position);
    outlineBox.setFillColor(outlineColor);
    outlineBox.setSize(sf::Vector2f(size.x, outlineThickness));
}
