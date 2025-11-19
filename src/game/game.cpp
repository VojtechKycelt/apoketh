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
game_c::game_c(input_manager_c& input_manager, sf::RenderWindow& window)
    : input_manager(input_manager)
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
	player_ship = std::make_unique<ship_c>(ship_size, ship_speed, sf::Vector2f{ (WINDOW_SIZE.x / 2) - ship_size / 2, WINDOW_SIZE.y - ship_size });
    player_ship->init();
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2), 200}));
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2) + 400, -200 }));
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2) , -800 }));
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2) , -1200 }));
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2) + 1000 , -500 }));

    for (auto& enemy : enemies) {
        enemy->init();
    }
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

    //TODO function handle_enemies and use there erase, update and collision ?
    for (auto it = enemies.begin(); it != enemies.end();) {
        if ((*it)->can_be_destroyed()) {
            it = enemies.erase(it);
        } else {
            (*it)->update(delta_time);
            ++it;
        }
    }
    check_collisions();
}


/*
 * @brief draw items on window
 * 
 * @param target - specify target where to draw the item (window for instance) 
 */
void game_c::draw(sf::RenderTarget &target)
{
    //player_ship->motion_blur(target, clock_motion_blur, start_time);
    player_ship->draw(target);

    // if there are more enemies some bullets are in front of them, because:
    // for each enemy it draws enemy then its bullets and then next enemy and his bullets and so on
    // TODO FIX.
    for (auto& enemy : enemies) {
        enemy->draw(target);
    }
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
            player_ship->move_right(delta_time, WINDOW_SIZE.x);
    }
}

void game_c::check_collisions()
{
    // Precompute player ship polygon once per frame
    std::vector<sf::Vector2f> player_ship_poly(player_ship->body.getPointCount());
    for (size_t i = 0; i < player_ship->body.getPointCount(); ++i) {
        player_ship_poly[i] = player_ship->body.getPoint(i) + player_ship->body.getPosition();
    }

    // Check collisions for each enemy
    for (auto& enemy : enemies) {
        if (enemy_square_c* e = dynamic_cast<enemy_square_c*>(enemy.get())) {
           
            std::vector<sf::Vector2f> enemy_body_poly(e->body.getPointCount());
            for (size_t i = 0; i < e->body.getPointCount(); ++i) {
                enemy_body_poly[i] = e->body.getPoint(i) + e->body.getPosition();
            }

            // --- Enemy bullets vs player ---
            for (auto& bullet : e->bullets) {
                if (! bullet->is_active) {
                    continue;
                }
                if (bullet->is_outside_of_screen()) {
                    bullet->is_active = false;
                }
                float r = bullet->body.getRadius();
                sf::Vector2f pos = bullet->body.getPosition();

                std::vector<sf::Vector2f> bullet_poly = {
                    pos + sf::Vector2f{-r, -r},
                    pos + sf::Vector2f{ r, -r},
                    pos + sf::Vector2f{ r,  r},
                    pos + sf::Vector2f{-r,  r}
                };

                if (collision_sat_convex(bullet_poly, player_ship_poly)) {
                    warning("PLAYER HIT BY ENEMY BULLET");
                    bullet->is_active = false;
                    // player_ship->get_damage();
                    continue;
                }
            }

            // --- Player bullets vs this enemy ---
            if (! e->is_alive) continue;
            if (pistol_c* pistol = dynamic_cast<pistol_c*>(player_ship->weapon_current.get())) {
                for (auto& bullet : pistol->bullets) {
                    if (!bullet->is_active) {
                        continue;
                    }
                    if (bullet->is_outside_of_screen()) {
                        bullet->is_active = false;
                    }
                    float r = bullet->body.getRadius();
                    sf::Vector2f pos = bullet->body.getPosition();

                    std::vector<sf::Vector2f> bullet_poly = {
                        pos + sf::Vector2f{-r, -r},
                        pos + sf::Vector2f{ r, -r},
                        pos + sf::Vector2f{ r,  r},
                        pos + sf::Vector2f{-r,  r}
                    };

                    if (collision_sat_convex(bullet_poly, enemy_body_poly)) {
                        warning("PLAYER HIT BY ENEMY BULLET");
                        bullet->is_active = false;
                        e->get_damage(pistol->dmg * 5);
                        continue;
                    }
                    
                }
            }
        }
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
