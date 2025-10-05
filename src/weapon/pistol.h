#pragma once

#include "weapon.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

class Pistol : public Weapon {

public:
	Pistol() : Weapon(E_WeaponType::PISTOL, 10.f, 0.1f, 0.1f, 10) {}

	void fire(sf::Vector2f pos) override {
		if (!ready_to_fire) {
			return;
		}

		//shoot
		Bullet bullet(sf::Color::Magenta, 30.f, pos, sf::Vector2f(2.f, 2.f));
	}


};