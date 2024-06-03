#include "SFML/Window/Window.hpp"
#include "SFML/Window/VideoMode.hpp"
#include "SFML/Window/Event.hpp"
#include "SFML/System/String.hpp"

int main()
{
    sf::Window window (sf::VideoMode( sf::Vector2u(800, 600) ), sf::String("My window"));

    while (window.isOpen())
    {
        while (sf::Event event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event.is<sf::Event::Closed>())
                window.close();
        }
    }


    return 0;
}