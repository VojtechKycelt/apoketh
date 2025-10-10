#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

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
		velocity(velocity = sf::Vector2f(200.f,200.f))
	
	{
		body.setFillColor(color);
		body.setPosition(pos);
	}

	void update(float delta_time) {
		sf::Vector2f position = body.getPosition();
		position += velocity * delta_time;

		body.setPosition(position);
		std::cout << "vyhul: " << body.getPosition().y << std::endl;

	}

	void draw(sf::RenderTarget& target) const {
		target.draw(body);
	}
};