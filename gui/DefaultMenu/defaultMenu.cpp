#include "defaultMenu.h"

void gui::DefaultMenu::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if(!isVisible) return;

    window.draw(outlineBox);
    window.draw(closeButton);
    window.draw(box);

    for(const UIElement* element : elements)
    {
        window.draw(*element);
    }
}

void gui::DefaultMenu::update(sf::View camera)
{
    if(!isVisible) return;

//--- Updating Menu perspective relative to View
    // sf::Vector2f mousePos = outlineMouseHandle.getMousePos();
    // setSize( sf::Vector2f(size.x / startFOV.x * camera.getSize().x, size.y / startFOV.y * camera.getSize().y) );
    // setPosition( sf::Vector2f(position.x / startFOV.x * camera.getSize().x + camera.getCenter().x, position.y / startFOV.y * camera.getSize().y + camera.getCenter().y) );

//--- Menu's events
    UIMenu::outlineMouseEvent();

    if(closeButton.isPressed().first) // If the menu was closed by a button
    {
        isVisible = false;
        printf("[defaultMenu.cpp] Closed menu by a button\n");
    }

}

void gui::DefaultMenu::setSize(sf::Vector2f size)
{
    for(UIElement* element : elements)
    {
        element->setSize(sf::Vector2f(box.getSize().x / size.x * element->getSize().x, box.getSize().y / size.y * element->getSize().y));
    }

    outlineBox.setSize(sf::Vector2f(size.x, outlineBox.getSize().y / box.getSize().y * size.y));
    closeButton.setSize(sf::Vector2f(outlineBox.getSize().y, outlineBox.getSize().y));
    box.setSize(size);
}

void gui::DefaultMenu::setPosition(sf::Vector2f position)
{
    box.setPosition(sf::Vector2f(position.x, position.y + outlineThickness) );
    outlineBox.setPosition(position);
    closeButton.setPosition(sf::Vector2f(position.x + size.x - outlineThickness, position.y));

    sf::Vector2f previousPosition = box.getPosition();
    for(UIElement* element : elements)
    {
        element->setPosition(previousPosition + element->getPadding());
        previousPosition += sf::Vector2f(0, previousPosition.y + element->getPadding().y);
    }
}

gui::DefaultMenu::DefaultMenu(sf::Vector2f size, sf::Vector2f position, sf::Color boxColor, sf::Color outlineColor, float outlineThickness, sf::RenderWindow* window) 
: 
UIMenu(size, position, boxColor, outlineColor, outlineThickness, window),
closeButton(sf::Vector2f(position.x + size.x - outlineThickness, size.y), sf::Vector2f(outlineThickness, outlineThickness), sf::Color(255,10,10), window) 
{
    
}