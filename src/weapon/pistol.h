#pragma once

#include "weapon.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

class Pistol : public Weapon {

	std::vector<Bullet> bullets;

public:
	Pistol() : Weapon(E_WeaponType::PISTOL, 10.f, 0.1f, 0.1f, 10) {}

	void fire(sf::Vector2f pos) override {
		if (!ready_to_fire) {
			return;
		}

		//shoot
		Bullet bullet(sf::Color::Magenta, 30.f, pos, sf::Vector2f(2.f, 2.f));
		bullets.push_back(bullet);
	}

	virtual void update(float delta_time) override {
		for each(Bullet bullet in bullets)
		{
			bullet.update(delta_time);
			
		}
	};

	virtual void draw(sf::RenderTarget& target) override {
		for each(Bullet bullet in bullets)
		{
			bullet.draw(target);
		}
	}

};