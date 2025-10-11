#pragma once

#include "weapon.h"
#include "bullet.h"
#include <SFML/Graphics.hpp>

class Pistol : public Weapon {

	std::vector<Bullet> bullets;
	sf::Clock fire_clock;
	float fire_cooldown = 0.5f;

public:
	Pistol() : Weapon(E_WeaponType::PISTOL, 10.f, 0.1f, 0.1f, 10) {}

	void fire(sf::Vector2f pos) override {
		if (!ready_to_fire) {
			return;
		}

		float radius = 3.f;
		Bullet bullet(sf::Color::Yellow, radius,{ pos.x - radius, pos.y - radius * 2 });
		bullets.push_back(bullet);
		
		//prevent shooting every frame
		ready_to_fire = false;
		fire_clock.restart(); 

		//magazine_ammo -= 1;
		//if (magazine_ammo <= 0) {
		//	//reload();
		//}
	}


	virtual void update(float delta_time) override {
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
	};

	virtual void draw(sf::RenderTarget& target) override {
		for (const Bullet& bullet : bullets)
		{
			bullet.draw(target);
		}
	}

};