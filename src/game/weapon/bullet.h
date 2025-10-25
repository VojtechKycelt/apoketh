/**
 * @file bullet.h
 *
 * @brief Bullet spawned when firing pistol (interface).
 * 
 */
#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief Bullet class spawned by weapon when firing pistol.
 *
 */
class bullet_c {

		sf::Vector2f			velocity;
		sf::CircleShape			body;

	public:
	
		bullet_c(sf::Color color, const float radius, const sf::Vector2f& pos, const sf::Vector2f& velocity = sf::Vector2f(0.f, -0.3f));

		void					update(const float delta_time);
		void					draw(sf::RenderTarget &target) const;
		bool					is_outside_of_screen();
};