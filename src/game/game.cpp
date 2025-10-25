/**
 * @file game.cpp
 *
 * @brief game manager (implementation).
 *
 */

#include "game.h"


/**
 * @brief Constructs the game manager.
 * 
 * @param window_size Size of render window used for layout calculations.
 * @param input_manager Reference to input handling system.
 * @param window Target render window for drawing.
 */
game_c::game_c(const sf::Vector2f& window_size, input_manager_c& input_manager, sf::RenderWindow& window)
    : window_size(window_size)
    , input_manager(input_manager)
    , window(window)
{
}


/**
 * @brief initialize important variables
 *
 */
void game_c::init()
{
    start_time = clock_motion_blur.restart();

	float ship_size = 40.f;
	float ship_speed = 0.3f;
	player_ship = std::make_unique<ship_c>(ship_size, ship_speed, sf::Vector2f{ (window_size.x / 2) - ship_size / 2, window_size.y - ship_size });
    player_ship->init();

}

/*
 * @brief called every frame, calls update of owned objects
 * 
 * @param delta_time.
 */
void game_c::update(const float delta_time)
{
    handle_inputs(delta_time);

    player_ship->update(delta_time);
}

/*
 * @brief draw items on window
 * 
 * @param target - specify target where to draw the item (window for instance) 
 */
void game_c::draw(sf::RenderTarget &target)
{
    player_ship->motion_blur(target, clock_motion_blur, start_time);
    player_ship->draw(target);
}


/*
 * @brief maps inputs to functions
 *
 * @param delta_time.
 */
void game_c::handle_inputs(const float delta_time)
{
    ship_move(delta_time);
    ship_shoot(delta_time);
}

/*
 * @brief call ship move functions according to inputs
 *
 * @param delta_time.
 */
void game_c::ship_move(const float delta_time)
{
    if (input_manager.key_pressed_left) {
            player_ship->move_left(delta_time);
    }

    if (input_manager.key_pressed_right) {
            player_ship->move_right(delta_time, window_size.x);
    }
}

/*
 * @brief call ship shoot function
 *
 * @param delta_time.
 */
void game_c::ship_shoot(const float delta_time) {
    if (input_manager.key_pressed_space) {
            player_ship->shoot();
    }
}
