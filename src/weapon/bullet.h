#pragma once

#include <SFML/Graphics.hpp>

class Bullet {

	sf::CircleShape body;
	sf::Vector2f velocity;

public:
	Bullet(
		sf::Color color, 
		float radius, 
		sf::Vector2f pos,
		sf::Vector2f velocity
	) : 
		body(sf::CircleShape(radius)),
		velocity(velocity = sf::Vector2f(2.f,2.f))
	
	{
		body.setFillColor(color);
		body.setPosition(pos);
	}

	void move(float delta_time) {
		body.setPosition(body.getPosition() + velocity * delta_time);
	}
};