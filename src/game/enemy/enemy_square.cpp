//
// Created by Vojtěch Kycelt on 29.10.2025.
//

#include "enemy_square.h"
#include "../../util/logger/logger.h"
enemy_square_c::enemy_square_c(const sf::Vector2f &position)
    : enemy_c(ENEMY_TYPE_square, sf::Vector2f{0.f,0.f}, position, 0.3f, 0.005f, 100, 0, 0, 50, 0, 0, true)
    , fire_cooldown(2.f) 
    , body(sf::Vector2f(50,50))
    , bullet_buffer_size(100)
{
    body.setPosition(position);
    bullets.reserve(bullet_buffer_size);
    for (size_t i = 0; i < bullet_buffer_size; ++i) {
        bullets.emplace_back(std::make_unique<bullet_c>(sf::Color::Yellow, 2.f, sf::Vector2f{ 0,0 }, sf::Vector2f{ 0.f, -0.3f }));
    }
}

void enemy_square_c::init() 
{
    enemy_c::init();
    
}

void enemy_square_c::update(const float delta_time) 
{
    enemy_c::update(delta_time);
    move(delta_time);
    
    for (auto& bullet : bullets) {
        bullet->update(delta_time);
    }

    if (fire_clock.getElapsedTime().asSeconds() > fire_cooldown) {
        fire({ position.x + body.getSize().x / 2 , position.y + body.getSize().y});
        fire_clock.restart();
    }
}

void enemy_square_c::draw(sf::RenderTarget &target) 
{
    enemy_c::draw(target);
    
    for (auto& bullet : bullets) {
        bullet->draw(target);
    }
    

    target.draw(body);

    if (!ready_to_fire && fire_clock.getElapsedTime().asSeconds() >= fire_cooldown) {
        ready_to_fire = true;
    }
}

void enemy_square_c::move(const float delta_time)
{
    enemy_c::move(delta_time);

    if (position.x < 0 ) {
        position.x = WINDOW_SIZE.x;
    } else if (position.x > WINDOW_SIZE.x) {
        position.x = 0.1f;
    }
    body.setPosition(position);
}

void enemy_square_c::fire()
{
    for (auto& bullet : bullets) {
        if (bullet->is_active) {
            continue;
        }
        bullet->body.setPosition({ position.x + body.getSize().x / 2 , position.y + body.getSize().y });
        bullet->velocity = { 0.f, 0.2f };
        bullet->body.setRadius(2.f);
        bullet->body.setFillColor(sf::Color::Red);
        bullet->is_active = true;
        break;
    }
}

void enemy_square_c::fire(const std::vector<sf::Vector2f>& directions)
{
    for (auto& dir : directions) {
        for (auto& bullet : bullets) {
            if (bullet->is_active) {
                continue;
            }
            bullet->body.setPosition({ position.x + body.getSize().x / 2 , position.y + body.getSize().y });
            bullet->velocity = dir;
            bullet->body.setRadius(3.f);
            bullet->body.setFillColor(sf::Color::Red);
            bullet->is_active = true;
            break;
        }
    }
}

void enemy_square_c::fire(const sf::Vector2f &pos) 
{
    for (auto& bullet : bullets) {
        if (bullet->is_active) {
            continue;
        }
        bullet->body.setPosition({ pos.x, pos.y});
        bullet->velocity = { 0.f, 0.2f };
        bullet->body.setRadius(2.f);
        bullet->body.setFillColor(sf::Color::Red);
        bullet->is_active = true;
        break;
    }

}
