/**
 * @file ship.h
 *
 * @brief ship (interface).
 *
 * Declares main ship that is controlled by player
 * 
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <memory>
#include "../../util/util.h"
#include "../weapon/weapon.h"

/**
 * @brief represents ship controlled by player (interface).
 *
 * Defines ship visuals, physics and components owned by ship.
 * Later could be used to spawn AI-controlled helper ships that fight alongside player.
 * 
 */
class ship_c {
public:
    float							size;
	float							speed;
	sf::Vector2f					position;
	sf::CircleShape					body;
	std::deque<float>				old_ship_positions;
	float							motion_blur_time;
	std::unique_ptr<weapon_c>		weapon_current;

	public:

		ship_c(float size, float speed, const sf::Vector2f position);

		void						init();
		void						update(const float delta_time);
		void						shoot();
		void						move_left(const float delta_time);
		void						move_right(const float delta_time, const float window_size_x);
		void						motion_blur(sf::RenderTarget &target, const sf::Clock &clock_motion_blur, const sf::Time &start_time);
		void						draw(sf::RenderTarget &target);
};