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
#include "../../util/util.h"
 /**
  * @brief
  *
  * Child class of enemy_c.
  *
  */
class enemy_square_c : public enemy_c {

public:
	sf::Clock								fire_clock;
	float									fire_cooldown;
	sf::RectangleShape						body;
	std::vector<std::unique_ptr<bullet_c>>	bullets;
	size_t									bullet_buffer_size;

public:

	enemy_square_c(const sf::Vector2f& position);
	~enemy_square_c();

	virtual void								init()	override;
	virtual void								update(const float delta_time)	override;
	virtual void								draw(sf::RenderTarget& target)	override;
	bool										can_be_destroyed() override;


	void										move(const float delta_time) override;

	void										fire()	override;
	void										fire(const std::vector<sf::Vector2f>& directions)	override;
	void										fire(const sf::Vector2f& pos)	override;

	virtual void								get_damage(float damage) override;
	bool										has_active_bullets();

};