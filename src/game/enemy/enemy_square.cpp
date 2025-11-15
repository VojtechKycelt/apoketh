//
// Created by Vojtěch Kycelt on 29.10.2025.
//

#include "enemy_square.h"
#include "../../util/logger/logger.h"
enemy_square_c::enemy_square_c(sf::Vector2f position)
    : enemy_c(ENEMY_TYPE_square, sf::Vector2f{0.f,0.f}, position, 100, 0, 0, 50, 0, 0, true)
    , fire_cooldown(0.5f) 
    , body(sf::Vector2f(30,30))
{
    body.setPosition(position);
}

void enemy_square_c::init() 
{
    enemy_c::init();
    velocity.x = 0.1f;
}

void enemy_square_c::update(const float delta_time) 
{
    enemy_c::update(delta_time);
    move(delta_time);
    
    for (auto it = bullets.begin(); it != bullets.end(); ) {

        (*it)->update(delta_time);

        if ((*it)->is_outside_of_screen()) {
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }

    if (fire_clock.getElapsedTime().asSeconds() > fire_cooldown) {
        fire({ position.x + body.getSize().x / 2 , position.y + body.getSize().y});
        fire_clock.restart();
    }
}

void enemy_square_c::draw(sf::RenderTarget &target) 
{
    enemy_c::draw(target);
    
    for (auto it = bullets.begin(); it != bullets.end(); ++it) {
        (*it)->draw(target);
    }

    target.draw(body);

    if (!ready_to_fire && fire_clock.getElapsedTime().asSeconds() >= fire_cooldown) {
        ready_to_fire = true;
    }
}

void enemy_square_c::move(const float delta_time)
{
    if (position.x < 0 ) {
        position.x = WINDOW_SIZE.x;
    } else if (position.x > WINDOW_SIZE.x) {
        position.x = 0.1f;
    }
    position += velocity * delta_time;
    body.setPosition(position);


}

void enemy_square_c::fire(const sf::Vector2f &pos) 
{
    float radius = 2.f;
    bullets.push_back(std::make_unique<bullet_c>(sf::Color::Red, radius, sf::Vector2f{ pos.x, pos.y}, sf::Vector2f{ 0.f, 0.1f }));

}
