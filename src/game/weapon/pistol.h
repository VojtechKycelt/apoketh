#pragma once

#include "weapon.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

/**
* @file pistol.h
*
* @brief Represents child class of Weapon
*
* Works as a real pistol, spawns bullets and set their velocity to up
* Holds vector of bullets and each time fire is called, add bullet to the list
* 
* @a fire_clock handles small delay between shots so the bullets are not spawned every frame while holding shoot key
*/
class pistol_c : public weapon_c {

				std::vector<bullet_c>				bullets;
				sf::Clock							fire_clock;
				float								fire_cooldown;

	public:

		pistol_c() 
			: weapon_c(weapon_type_t::WEAPON_TYPE_pistol, 10.f, 0.1f, 0.1f, 10)
			, fire_cooldown(0.5f)
		{
		}

				void								fire(const sf::Vector2f &pos)	override;
		virtual void								update(const float delta_time)	override; 
		virtual void								draw(sf::RenderTarget &target)	override;

};