#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <memory>

#include "../weapon/weapon.h"

/**
 * @file ship.h
 *
 * @brief Represents ship controlled by player
 *
 * Defines ship visuals, physics and components owned by ship.
 * 
*/
class ship_c {

    float							size;
	float							speed;
	sf::Vector2f					position;
	sf::CircleShape					body;
	std::deque<float>				old_ship_positions;
	float							motion_blur_time;
	std::unique_ptr<weapon_c>		weapon_current;

	public:

		ship_c(float _size, float _speed, const sf::Vector2f _position) 
			: size(_size)
			, speed(_speed)
			, position(_position)
			, body(_size / 2, 3)
			, old_ship_positions({})
			, motion_blur_time(500.f)
		{
				body.setFillColor(sf::Color::Green);
				body.setPosition(_position);
		};

		void						init();
		void						update(const float delta_time);
		void						shoot();
		void						move_left(const float delta_time);
		void						move_right(const float delta_time, const float window_size_x);
		void						motion_blur(sf::RenderTarget &target, const sf::Clock &clock_motion_blur, const sf::Time &start_time);
		void						draw(sf::RenderTarget &target);
};