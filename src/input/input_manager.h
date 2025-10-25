/**
* @file input_manager.h
*
* @brief Represents manager of inputs, sets bools of pressed keys to be used used in other classes
*/

#pragma once
#include <SFML/Graphics.hpp>

class input_manager_c {
    
    public:
        bool            key_pressed_left = false;
        bool            key_pressed_right = false;
        bool            key_pressed_up = false;
        bool            key_pressed_down = false;
        bool            key_pressed_space = false;

        void check_pressed_keys();
};