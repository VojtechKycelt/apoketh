/**
 * @file bullet.cpp
 *
 * @brief Bullet spawned when firing pistol (implementation).
 *
 */

#include "bullet.h"

/*
 * @brief contructor
 * 
 * @param color - color of circle shape.
 * @param radius - radius of circle shape.
 * @param pos - spawning position of bullet.
 * @param velocity - starting velocity of bullet when fired.
 */
bullet_c::bullet_c(sf::Color color, const float radius, const sf::Vector2f& pos, const sf::Vector2f& velocity)
	: body(sf::CircleShape(radius))
	, velocity(velocity)
	, is_active(false)

{
	body.setFillColor(color);
	body.setPosition(pos);
}

/**
 * @brief update called every frame to adjust position based on velocity and delta time
 *
 * @return bool
 */
void bullet_c::update(const float delta_time)
{
	if (! is_active) {
		return;
	}
	sf::Vector2f position = body.getPosition();

	position += velocity * delta_time;

	body.setPosition(position);
}

/**
 * @brief draw on window
 *
 */
void bullet_c::draw(sf::RenderTarget &target) const
{
	if (!is_active) {
		return;
	}
	target.draw(body);
}

/**
 * @brief checks if bullet is outside of screen
 * 
 * @return bool
 */
bool bullet_c::is_outside_of_screen()
{
	bool top = body.getPosition().y < 0 - body.getRadius() * 2;
	bool left = body.getPosition().x < 0 - body.getRadius() * 2;
	bool bottom = body.getPosition().y > WINDOW_SIZE.y + body.getRadius() * 2;
	bool right = body.getPosition().x > WINDOW_SIZE.x + body.getRadius() * 2;
	return top || left || bottom || right;
}
