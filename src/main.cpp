#include <SFML/Graphics.hpp>
#include "../gui/DefaultMenu/defaultMenu.h"
#include "../gui/LabelElement/labelElement.h"

/*
        TO-DO:
        
    - Make a Group class for a mix of absolute and relative positioning
    - Add more types of components
    - Try to use the pros of inheritance by 
    - Make buttons adapt to change in size
    - Make code more readable (optional)
*/


int main()
{
    auto window = sf::RenderWindow{ { 1000u, 1000u }, "CMake SFML Project" };
    window.setFramerateLimit(144);

    sf::Font font;
    font.loadFromFile("../../../font.otf");

    gui::DefaultMenu menu(sf::Vector2f(300,300), sf::Vector2f(300,300), sf::Color(60,60,60), sf::Color(170, 100, 20), 20, &window);
    menu.addElement(new gui::Label(sf::Vector2f(10,10), 20, sf::Color(255,255,255), &font, "your"));
    menu.addElement(new gui::Label(sf::Vector2f(10,0), 20, sf::Color(255,255,255), sf::Color(255,0,0), &font, "mom"));
    menu.addElement(new gui::Button(sf::Vector2f(0,10), sf::Vector2f(100,30), sf::Color(160,160,160), sf::Color(100,100,100), sf::Color(0,0,0), &window, &font, "lorem ipsum", 20.f));
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
