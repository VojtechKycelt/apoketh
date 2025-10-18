#pragma once
#include <SFML/Graphics.hpp>


enum weapon_type_t
{ 
	WEAPON_TYPE_pistol, 
	WEAPON_TYPE_lmg,
	WEAPON_TYPE_laser,
	WEAPON_TYPE_rocket_launcher 
};

/**
 * @file weapon.h
 *
 * @brief Abstract class for creating weapons
 *
 * Defines shared variables and virtual functions that every weapon should use
 *
*/
class weapon_c {
	public:
			weapon_type_t			type;
			float					dmg;
			float					armor_pen;
			float					shield_pen;
			int						magazine_ammo;
			int						magazine_capacity;
			bool					ready_to_fire;

	weapon_c(weapon_type_t type, const float dmg, const float armor_pen, const float shield_pen, const int magazine_capacity) 
		: type(type)
		, dmg(dmg)
		, armor_pen(armor_pen)
		, shield_pen(shield_pen)
		, magazine_ammo(magazine_capacity)
		, magazine_capacity(magazine_capacity)
		, ready_to_fire(true)
	{
	};

	virtual ~weapon_c()				= default; // always add virtual destructor to base classes!
	virtual void					fire(const sf::Vector2f &pos) = 0;
	virtual void					update(const float delta_time) = 0;
	virtual void					draw(sf::RenderTarget &target) = 0;
	virtual void					reload_magazine();
};



