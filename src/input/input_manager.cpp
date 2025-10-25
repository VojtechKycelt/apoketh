#include "input_manager.h"

/**
* @file input_manager.cpp
*
* @brief implements input_manager_c
*/

void input_manager_c::check_pressed_keys()
{
    key_pressed_left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left);
    key_pressed_right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right);
    key_pressed_up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    key_pressed_down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
    key_pressed_space = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}
