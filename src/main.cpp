#include <SFML/Graphics.hpp>
#include <deque>
#include "game/game.h"
#include "input/input_manager.h"
#include "util/globals.h"

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;
    auto window = sf::RenderWindow(sf::VideoMode(WINDOW_DIMENSIONS), "Apoketh", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(240);

    input_manager_c inputManager;
    game_c game(inputManager, window);
    game.init();

    sf::Clock clock;
    std::cout << "Working dir: " << std::filesystem::current_path() << std::endl;

    while (window.isOpen())
    {
        
        // Check all the window's events that were triggered since the last iteration of the loop
        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            inputManager.check_pressed_keys();
            
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);


        // Delta time
        sf::Time elapsed = clock.restart();
        float delta_time = elapsed.asMilliseconds();


        // Update objects
        game.update(delta_time);
        

        // Draw everything
        game.draw(window);


        // End the current frame
        window.display();
    }
}
