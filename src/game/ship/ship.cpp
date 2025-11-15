/**
 * @file ship.cpp
 *
 * @brief ship (implementation).
 *
*/

#include "ship.h"
#include "../weapon/pistol.h"


/*
 * @brief Constructor
 * 
 * @param size - size of the ship.
 * @param speed - speed of the ship.
 * @param position - starting position of the ship.
 */
ship_c::ship_c(float size, float speed, const sf::Vector2f position)
    : size(size)
    , speed(speed)
    , position(position)
    , body(size / 2, 3)
    , old_ship_positions({})
    , motion_blur_time(500.f)
{
    body.setFillColor(sf::Color::Green);
    body.setPosition(position);
};

/*
* @brief initialize important objects
*
*/
void ship_c::init() 
{
    weapon_current = std::make_unique<pistol_c>();
}

/*
* @brief update called every frame
*
*/
void ship_c::update(const float delta_time)
{
    assert(weapon_current);
    weapon_current->update(delta_time);

}

/*
* @brief draw ship body on window and call draw of owned objects
*
*/
void ship_c::draw(sf::RenderTarget& target)
{
    body.setFillColor(sf::Color::Green);
    target.draw(body);
    weapon_current->draw(target);
}

/*
* @brief shoot with current weapon
*
*/
void ship_c::shoot()
{
    assert(weapon_current);
    weapon_current->fire({position.x + size / 2,position.y});
}

/*
* @brief check if ship is not out of screen and move left
*
*/
void ship_c::move_left(const float delta_time)
{
    position = { fmax(position.x - (speed * delta_time), 0.f), position.y };
    body.setPosition(position);
}

/*
* @brief check if ship is not out of screen and move right
*
*/
void ship_c::move_right(const float delta_time, const float window_size_x)
{
    position = { fmin(position.x + (speed * delta_time),window_size_x - size),position.y };
    body.setPosition(position);
    
}

/*
* @brief create motion blur effect behind moving ship
*
* Currently ship previous positions are cached and then drawed behind ship and color faded 
*
*/
void ship_c::motion_blur(sf::RenderTarget &target, const sf::Clock &clock_motion_blur, const sf::Time &start_time)
{
    if (old_ship_positions.size() < speed * motion_blur_time / 10) {
        old_ship_positions.push_back(position.x);
    }

    if (old_ship_positions.size() > 2) {
        for (int i = 0; i < old_ship_positions.size() - 2; i++) {
            float g_range = 50;
            float g = fmin(i * (g_range / old_ship_positions.size()), g_range);
            body.setFillColor(sf::Color(0, g, 0));

            if (old_ship_positions[i] < old_ship_positions[i + 1]) {
                for (int j = old_ship_positions[i]; j < old_ship_positions[i + 1]; ++j) {
                    body.setPosition({ static_cast<float>(j),position.y });
                    target.draw(body);
                }
            }
            else {
                for (int j = old_ship_positions[i]; j > old_ship_positions[i + 1]; --j) {
                    body.setPosition({ static_cast<float>(j),position.y });
                    target.draw(body);
                }
            }
        }
    }
    else {
        for (float& old_pos : old_ship_positions)
        {
            body.setPosition({ old_pos,position.y });
            target.draw(body);
        }
    }

    if (clock_motion_blur.getElapsedTime().asMilliseconds() - start_time.asMilliseconds() > motion_blur_time || (!old_ship_positions.empty() && old_ship_positions.back() != position.x)) {
        old_ship_positions.pop_front();
    }
}
