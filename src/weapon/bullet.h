#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

/**
* @file bullet.h
*
* @brief Represents bullet currently used by @t WEAPON_TYPE_pistol
*
*/
class bullet_c {

		sf::Vector2f			velocity;
		sf::CircleShape			body;

	public:
	
		bullet_c(sf::Color color, const float radius, const sf::Vector2f &pos, const sf::Vector2f &velocity = sf::Vector2f(0.f, -0.3f)) 
			: body(sf::CircleShape(radius))
			, velocity(velocity)
	
		{
			body.setFillColor(color);
			body.setPosition(pos);
		}

		void					update(const float delta_time);
		void					draw(sf::RenderTarget &target) const;
		bool					is_outside_of_screen();
};