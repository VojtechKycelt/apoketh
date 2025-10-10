#pragma once
#include <SFML/Graphics.hpp>
enum E_WeaponType { PISTOL, LMG, LASER, ROCKET_LAUNCHER };

//abstract class for weapons
class Weapon {
public:
	E_WeaponType type;
	float dmg;
	float armor_pen;
	float shield_pen;
	int magazine_ammo;
	int magazine_capacity;
	bool ready_to_fire;

	Weapon(
		E_WeaponType type,
		float dmg,
		float armor_pen,
		float shield_pen,
		int magazine_capacity) :
		type(type),
		dmg(dmg),
		armor_pen(armor_pen),
		shield_pen(shield_pen),
		magazine_ammo(magazine_capacity),
		magazine_capacity(magazine_capacity),
		ready_to_fire(true)
	{};

	virtual ~Weapon() = default; // always add virtual destructor to base classes!
	virtual void fire(sf::Vector2f pos) = 0;
	virtual void update(float delta_time) = 0;
	virtual void draw(sf::RenderTarget& target) = 0;
	virtual void reload();
};



