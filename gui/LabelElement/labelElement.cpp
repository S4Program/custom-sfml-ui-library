#include "labelElement.h"

void gui::Label::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(backBox);
    window.draw(text);
} 

void gui::Label::setPosition(sf::Vector2f position)
{
    text.setPosition(position);
    backBox.setPosition(text.getGlobalBounds().getPosition());
}

void gui::Label::setSize(sf::Vector2f size)
{
    text.setCharacterSize(text.getCharacterSize() / backBox.getSize().x * size.x);
    backBox.setSize(size);
}

gui::Label::Label(sf::Vector2f padding, float characterSize, sf::Color textColor, sf::Color backColor, sf::Font* font, std::string message)
:
UIElement(padding, sf::Vector2f(characterSize * message.size(), characterSize))
{
//--- Text Setup
    text.setFont(*font);
    text.setString(message);
    text.setCharacterSize(characterSize);
    text.setFillColor(textColor);
    text.setPosition(padding);

//--- Background Box Setup
    // backBox.setSize(sf::Vector2f(characterSize * message.size(), characterSize));
    // backBox.setFillColor(backColor);

    backBox = sf::RectangleShape(text.getGlobalBounds().getSize());
    backBox.setPosition(text.getGlobalBounds().getPosition());
    backBox.setFillColor(backColor);
}