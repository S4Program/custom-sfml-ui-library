#include "mouseHandle.h"

bool gui::MouseHandle::isHovered()
{
    return hitbox->getGlobalBounds().contains(getMousePos());
}

std::pair<bool, bool> gui::MouseHandle::isPressed()
{
    return {sf::Mouse::isButtonPressed(sf::Mouse::Left), sf::Mouse::isButtonPressed(sf::Mouse::Right)};
}

std::pair<bool, bool> gui::MouseHandle::isClicked()
{
    //printf("[mouseHandle.cpp] IsHovered: %i\n                  Mouse position: [%f, %f]\n", isHovered(), getMousePos().x, getMousePos().y);

    return {isHovered() && isPressed().first, isHovered() && isPressed().second};
}

gui::MouseHandle::MouseHandle(sf::RenderWindow* window, sf::RectangleShape* hitbox)
:
window(window),
hitbox(hitbox)
{
    
}