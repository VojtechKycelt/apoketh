/**
 * @file enemy.cpp
 *
 * @brief abstract enemy definitions (implementation).
 *
 */

#include "enemy.h"

/**
 * @brief Constructor.
 *
 */
enemy_c::enemy_c(
	const enemy_type_t& type, 
	const sf::Vector2f& velocity, 
	const sf::Vector2f& position, 
	const float hp, 
	const float armor_points, 
	const float shield_points, 
	const float dmg, 
	const float armor_pen, 
	const float shield_pen, 
	const bool ready_to_fire
) 
	: type(type)
	, velocity(velocity)
	, position(position)
	, hp(hp)
	, armor_points(armor_points)
	, shield_points(shield_points)
	, dmg(dmg)
	, armor_pen(armor_pen)
	, shield_pen(shield_pen)
	, ready_to_fire(ready_to_fire)
{
}

/**
 * @brief Destructor.
 *
 */
enemy_c::~enemy_c()
{

}

/**
 * @brief Init.
 *
 */
void enemy_c::init()
{

}

/**
 * @brief Update called every frame.
 *
 */
void enemy_c::update(const float delta_time)
{

}

/**
 * @brief draw to render target.
 *
 */
void enemy_c::draw(sf::RenderTarget& target)
{

}

