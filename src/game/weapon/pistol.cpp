/**
 * @file pistol.cpp
 *
 * @brief Child class of Weapon (implementation).
 *
*/

#include "pistol.h"

/*
* 
* @brief contructor
*/
pistol_c::pistol_c()
	: weapon_c(weapon_type_t::WEAPON_TYPE_pistol, 10.f, 0.1f, 0.1f, 10)
	, fire_cooldown(0.5f)
{
}


/**
* @brief Spawn bullets and add them to the @a bullets vector to keep track of them
* 
* Restarts timer after every shot to prevent shooting every frame
* 
*/
void pistol_c::fire(const sf::Vector2f &pos)
{
	if (!ready_to_fire) {
		return;
	}

	float radius = 3.f;
	bullet_c bullet(sf::Color::Yellow, radius, { pos.x - radius, pos.y - radius * 2 });
	bullets.push_back(bullet);

	//prevent shooting every frame
	ready_to_fire = false;
	fire_clock.restart();

	//@note maybe add reload functionality
	//magazine_ammo -= 1;
	//if (magazine_ammo <= 0) {
	//	//reload();
	//}
}

/**
* @brief checks if bullets are outside of screen and resets ability to shoot after timeout
* 
*/
void pistol_c::update(const float delta_time)
{
	for (auto it = bullets.begin(); it != bullets.end(); ) {

		it->update(delta_time);

		if (it->is_outside_of_screen()) {

			it = bullets.erase(it);

		}
		else {
			++it;
		}
	}

	if (!ready_to_fire && fire_clock.getElapsedTime().asSeconds() >= fire_cooldown) {
		ready_to_fire = true;
	}
}

/**
* @brief draws all bullets on window
* 
*/
void pistol_c::draw(sf::RenderTarget &target)
{
	for (const bullet_c& bullet : bullets)
	{
		bullet.draw(target);
	}
}
