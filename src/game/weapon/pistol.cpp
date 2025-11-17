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
	, bullet_buffer_size(100)
	, bullet_radius(3.f)
{
	bullets.reserve(bullet_buffer_size);
	for (size_t i = 0; i < bullet_buffer_size; ++i) {
		bullets.emplace_back(std::make_unique<bullet_c>(sf::Color::Yellow, bullet_radius, sf::Vector2f{ 0,0 }, sf::Vector2f{ 0.f, -0.3f }));
	}
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

	for (auto& bullet : bullets) {
		if (bullet->is_active) {
			continue;
		}
		bullet->body.setPosition({ pos.x - bullet_radius, pos.y - bullet_radius * 2 });
		//bullet->velocity = { 0.f, -0.3f };
		bullet->is_active = true;
		break;
	}

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
	for (auto& bullet : bullets) {
		bullet->update(delta_time);
		if (bullet->is_outside_of_screen()) {
			bullet->is_active = false;
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
	for (auto it = bullets.begin(); it != bullets.end(); ++it) {
		(*it)->draw(target);
	}
}
