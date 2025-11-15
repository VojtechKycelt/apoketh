/**
 * @file game.h
 * 
 * @brief game manager (interface).
 *
 * Declares the main game controller class responsible for:
 * - Initializing gameplay systems
 * - Updating game state based on time and player input
 * - Rendering all visible game entities
 *
 * The game manager owns the player ship instance and coordinates
 * gameplay actions such as movement and shooting. It interacts with
 * the input manager and SFML render window.
 */

#pragma once
#include "../input/input_manager.h"
#include <memory>
#include "ship/ship.h"
#include "enemy/enemy.h"
#include "enemy/enemy_square.h"
#include "weapon/pistol.h"
#include "../util/globals.h"
/**
 * @brief Main controller for game state, input, and rendering.
 *
 * Manages:
 * - Player ship control (movement, shooting)
 * - Frame updates with delta time
 * - Rendering to the associated SFML window (maybe change to draw to render target param)
 *
 * Created and owned by main.cpp.
 */
class game_c {
	
		std::unique_ptr<ship_c>					player_ship;
		input_manager_c&						input_manager;
		sf::RenderWindow&						window;
		sf::Clock								clock_motion_blur;
		sf::Time								start_time;
		std::vector<std::unique_ptr<enemy_c>>	enemies;

	public:
		
		game_c(input_manager_c& input_manager, sf::RenderWindow& window);

		void						init();
		void						update(const float delta_time);
		void						draw(sf::RenderTarget &target);

	private:
		
		void						handle_inputs(const float delta_time);
		void						ship_shoot(const float delta_time);
		void						ship_move(const float delta_time);
		void						check_collisions();
};