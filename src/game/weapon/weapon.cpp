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
 * @param mag_cap
*/
weapon_c::weapon_c(const weapon_type_t &type, const float dmg, const float armor_pen, const float shield_pen, const int mag_cap)
	: type(type)
	, dmg(dmg)
	, armor_pen(armor_pen)
	, shield_pen(shield_pen)
	, mag_ammo(mag_cap)
	, mag_cap(mag_cap)
	, ready_to_fire(true)
{
};

/**
* @brief Reload - set magazine ammo to magazine capacity
*
*/
void weapon_c::reload_magazine() {

	mag_ammo = mag_cap;
}