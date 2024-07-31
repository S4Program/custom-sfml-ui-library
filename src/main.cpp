#include <SFML/Graphics.hpp>
#include "../gui/DefaultMenu/defaultMenu.h"
#include "../gui/LabelElement/labelElement.h"

int main()
{
    auto window = sf::RenderWindow{ { 1000u, 1000u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    sf::Font font;
    font.loadFromFile("../../font.otf");

    gui::DefaultMenu menu(sf::Vector2f(500,300), sf::Vector2f(300,300), sf::Color(60,60,60), sf::Color(170, 100, 20), 20, &window);
    menu.addElement(new gui::Label(sf::Vector2f(30,30), 30, sf::Color(255,255,255), sf::Color(200,10,10), &font, "this is test"));
    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        menu.update(window.getView());

        window.clear();
        window.draw(menu);
        window.display();
    }
}
