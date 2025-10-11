#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet {

	sf::Vector2f velocity;
	sf::CircleShape body;

public:
	
	Bullet(
		sf::Color color, 
		float radius, 
		sf::Vector2f pos,
		const sf::Vector2f& velocity = sf::Vector2f(0.f, -0.3f)
	) : 
		body(sf::CircleShape(radius)),
		velocity(velocity)
	
	{
		body.setFillColor(color);
		body.setPosition(pos);
	}

	void update(float delta_time) {
		sf::Vector2f position = body.getPosition();

		position += velocity * delta_time;

		body.setPosition(position);
	}

	void draw(sf::RenderTarget& target) const {
		target.draw(body);
	}

	bool is_outside_of_screen() {
		return body.getPosition().y < 0 - body.getRadius() * 2;
	}
};