#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include <memory>

#include "../weapon/weapon.h"

class Ship {

    float size;
	float speed;
	sf::Vector2f position;
	sf::CircleShape body;
	std::deque<float> old_ship_positions;
	float motion_blur_time;
	std::unique_ptr<Weapon> weapon_current;

public:

	Ship(
		float _size,
		float _speed,
		sf::Vector2f _position
	) : size(_size),
		speed(_speed),
		position(_position),
		body(_size / 2, 3),
		old_ship_positions({}),
		motion_blur_time(500.f)
	{
		body.setFillColor(sf::Color::Green);
		body.setPosition(_position);
	};

	float getSize() { return size; }
	void setSize(const float& _size) { size = _size; }

	float getSpeed() { return speed; }
	void setSpeed(const float& _speed) { speed = _speed; }

	sf::Vector2f getPosition() { return position; }
	void setPosition(const sf::Vector2f& _position) { position = _position; };

	sf::CircleShape& getBody() { return body; }
	std::deque<float>& getOldShipPositions() { return old_ship_positions; }
	
	float getMotionBlurTime() { return motion_blur_time; }

	void init();
	void shoot();
	void update(float delta_time);
	void draw(sf::RenderTarget& target);
	void move_left(float delta_time);
	void move_right(float delta_time, float window_size_x);
};