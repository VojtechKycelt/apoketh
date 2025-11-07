//
// Created by Vojtěch Kycelt on 29.10.2025.
//

#include "enemy_square.h"

enemy_square_c::enemy_square_c(): enemy_c() {
}

void enemy_square_c::init() {
    enemy_c::init();

}

void enemy_square_c::update(const float delta_time) {
    enemy_c::update(delta_time);

}

void enemy_square_c::draw(sf::RenderTarget &target) {
    enemy_c::draw(target);

}

void enemy_square_c::fire(const sf::Vector2f &pos) {

}
