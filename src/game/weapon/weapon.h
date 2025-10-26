/**
 * @file weapon.h
 *
 * @brief abstract weapon definitions (interface).
 *
 * Declares base class for weapons and enum for weapon types
 *
*/

#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief Enum for weapon types.
 *
 */
enum weapon_type_t
{ 
	WEAPON_TYPE_pistol, 
	WEAPON_TYPE_lmg,
	WEAPON_TYPE_laser,
	WEAPON_TYPE_rocket_launcher 
};

/**
 * @brief Abstract class for creating weapons.
 *
 * Abstract class containing shared variables and virtual functions that child weapons should use
 * 
 */
class weapon_c {

	public:
			weapon_type_t			type;
			float					dmg;
			float					armor_pen;
			float					shield_pen;
			int						mag_ammo;
			int						mag_cap;
			bool					ready_to_fire;

			weapon_c(const weapon_type_t &type, const float dmg, const float armor_pen, const float shield_pen, const int mag_cap);

	virtual ~weapon_c()				= default; // always add virtual destructor to base classes!
	virtual void					fire(const sf::Vector2f &pos) = 0;
	virtual void					update(const float delta_time) = 0;
	virtual void					draw(sf::RenderTarget &target) = 0;
	virtual void					reload_magazine();
};



