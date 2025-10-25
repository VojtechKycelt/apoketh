/**
 * @file weapon.cpp
 *
 * @brief abstract class for creating weapons (implementation).
 *
*/

#include "weapon.h"

/**
 * @brief constructor
 * 
 * @param type
 * @param dmg
 * @param armor_pen
 * @param shield_pen
 * @param magazine_capacity
*/
weapon_c::weapon_c(weapon_type_t type, const float dmg, const float armor_pen, const float shield_pen, const int magazine_capacity)
	: type(type)
	, dmg(dmg)
	, armor_pen(armor_pen)
	, shield_pen(shield_pen)
	, magazine_ammo(magazine_capacity)
	, magazine_capacity(magazine_capacity)
	, ready_to_fire(true)
{
};

/**
* @brief Reload - set magazine ammo to magazine capacity
*
*/
void weapon_c::reload_magazine() {

	magazine_ammo = magazine_capacity;
}