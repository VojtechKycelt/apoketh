#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include "game/game.h"
#include "input/input_manager.h"

int main()
{
    static sf::Vector2 WINDOW_DIMENSIONS = { 960u, 540u };
    static sf::Vector2 WINDOW_SIZE = { static_cast<float>(WINDOW_DIMENSIONS.x), static_cast<float>(WINDOW_DIMENSIONS.y)};
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_DIMENSIONS), "Apoketh", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(240);

    input_manager_c inputManager;
    game_c game(WINDOW_SIZE, inputManager, window);
    game.init();

    sf::Clock clock;
   
    while (window.isOpen())
    {
        
        // check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            inputManager.check_pressed_keys();
            
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        //delta time
        sf::Time elapsed = clock.restart();
        float delta_time = elapsed.asMilliseconds();

        // draw everything here...
        game.update(delta_time);

        game.draw(window);

        // end the current frame
        window.display();

    }
}
