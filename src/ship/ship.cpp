#include "ship.h"

void Ship::shoot()
{
    body.setFillColor(sf::Color::Red);
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
