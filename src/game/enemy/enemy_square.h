/**
 * @file pistol.h
 *
 * @brief Child class of Weapon (interface).
 *
 */

#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>

 /*
  * @brief
  *
  * Child class of enemy_c.
  *
  */
class enemy_square_c : public enemy_c {

	//std::vector<bullet_c>				bullets;
	sf::Clock							fire_clock;
	float								fire_cooldown;

public:

	enemy_square_c();

	virtual void								init()	override;
	virtual void								update(const float delta_time)	override;
	virtual void								draw(sf::RenderTarget& target)	override;

	//void										fire(const sf::Vector2f& pos)	override;
};