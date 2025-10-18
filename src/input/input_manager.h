#pragma once
#include <SFML/Graphics.hpp>

/**
* @file input_manager.h
*
* @brief Represents manager of inputs, sets bools of pressed keys to be used used in other classes
*/
class input_manager_c {
    
    public:
        bool            key_pressed_left = false;
        bool            key_pressed_right = false;
        bool            key_pressed_up = false;
        bool            key_pressed_down = false;
        bool            key_pressed_space = false;

        void check_pressed_keys() 
        {
            key_pressed_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
            key_pressed_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
            key_pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
            key_pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
            key_pressed_space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
        }
};