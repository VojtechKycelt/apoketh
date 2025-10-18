#pragma once
#include "../input/input_manager.h"
#include <memory>
#include "ship/ship.h"


/**
 * @file game.h
 *
 * @brief Represents manager of the game
 *
 * This class is a game manager that is called from main.cpp.
 * Handles inputs via @input and calls functions based of that.
 * Takes care of all the update and draw functions within all owned children.
 * Game owns player, weapons, enemies, etc.
*/
class game_c {
	
		std::unique_ptr<ship_c>		player_ship;
		sf::Vector2f				window_size;
		input_manager_c&			input_manager;
		sf::RenderWindow&			window;
		sf::Clock					clock_motion_blur;
		sf::Time					start_time;

	public:
		
		game_c(const sf::Vector2f& window_size, input_manager_c& input_manager, sf::RenderWindow& window) 
			: window_size(window_size)
			, input_manager(input_manager)
			, window(window)
		{
		}

		void						init();
		void						update(const float delta_time);
		void						draw(sf::RenderTarget &target);

	private:
		
		void						handle_inputs(const float delta_time);
		void						ship_shoot(const float delta_time);
		void						ship_move(const float delta_time);
};