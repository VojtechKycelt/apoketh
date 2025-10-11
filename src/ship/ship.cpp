#include "ship.h"
#include "../weapon/pistol.h"
void Ship::init() 
{
    weapon_current = std::make_unique<Pistol>();
}

void Ship::update(float delta_time) {
    assert(weapon_current);
    weapon_current->update(delta_time);
}

void Ship::draw(sf::RenderTarget& target)
{
    target.draw(body);
    weapon_current->draw(target);
}


void Ship::shoot()
{
    assert(weapon_current);
    weapon_current->fire({position.x + size / 2,position.y});
}

void Ship::move_left(float delta_time)
{
    position = { fmax(position.x - (speed * delta_time), 0.f), position.y };
    body.setPosition(position);
}

void Ship::move_right(float delta_time, float window_size_x)
{
    position = { fmin(position.x + (speed * delta_time),window_size_x - size),position.y };
    body.setPosition(position);
    
}
