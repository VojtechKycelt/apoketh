#include "bullet.h"

/**
* @brief update called every frame to adjust position based on velocity and delta time
*
* @return bool
*/
void bullet_c::update(const float delta_time)
{
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
	target.draw(body);
}

/**
* @brief checks if bullet is outside of screen
* 
* @return bool
*/
bool bullet_c::is_outside_of_screen()
{
	return body.getPosition().y < 0 - body.getRadius() * 2;
}
