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

void gui::UIMenu::buttonsEvent()
{
    for(UIElement* uiElement : elements)
    {
        if(uiElement->getType() == gui::BUTTON)
        {
            uiElement->update();
        }
    }
}

void gui::UIMenu::resetComponents()
{
    sf::Vector2f previousPosition = box.getPosition() - elements.at(0)->getSize();
    sf::Vector2f firstLineElement = box.getPosition();
    for(UIElement* element : elements)
    {
        if(element->getPadding().x != 0)
        {
            previousPosition += sf::Vector2f(element->getPadding().x + element->getSize().x, 0);
        }
        else
        {
            previousPosition = sf::Vector2f(0, element->getPadding().y) + firstLineElement;
        }

        if(element->getPadding().y != 0)
        {
            previousPosition += sf::Vector2f(0, element->getPadding().y + element->getSize().y);
        }

        element->setPosition(previousPosition);

        if(firstLineElement.y != element->getPadding().y)
        {
            firstLineElement = element->getPadding() + box.getPosition();
        }
    }   
}

void gui::UIMenu::addElement(UIElement* element)
{
    elements.push_back(element);
    setPosition(box.getPosition()); //as the box represents the main frame, it can be used for getting the position...
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
