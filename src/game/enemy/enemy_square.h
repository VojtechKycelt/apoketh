/**
 * @file pistol.h
 *
 * @brief Child class of Weapon (interface).
 *
 */

#pragma once
#include "enemy.h"
#include <SFML/Graphics.hpp>
#include "../weapon/bullet.h"
#include "../../util/globals.h"
 /**
  * @brief
  *
  * Child class of enemy_c.
  *
  */
class enemy_square_c : public enemy_c {

	sf::Clock								fire_clock;
	float									fire_cooldown;
	sf::RectangleShape						body;
	std::vector<std::unique_ptr<bullet_c>>	bullets;

public:

	enemy_square_c(sf::Vector2f position);

	virtual void								init()	override;
	virtual void								update(const float delta_time)	override;
	virtual void								draw(sf::RenderTarget& target)	override;

	void										move(const float delta_time) override;
	void										fire(const sf::Vector2f& pos)	override;
};