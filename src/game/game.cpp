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
    enemies.push_back(std::make_unique<enemy_square_c>(sf::Vector2f{ (WINDOW_SIZE.x / 2), WINDOW_SIZE.y / 2}));

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

    for (auto& enemy : enemies) {
        enemy->update(delta_time);
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
    player_ship->motion_blur(target, clock_motion_blur, start_time);
    player_ship->draw(target);

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
    std::vector<sf::Vector2f> player_ship_poly;
    for (size_t i = 0; i < player_ship->body.getPointCount(); ++i) {
        player_ship_poly.push_back(player_ship->body.getPoint(i) + player_ship->body.getPosition());
    }

    std::vector<sf::Vector2f> enemy_body_poly;


    //check if player_ship collides with eny of the enemy shots/bullets
    for (auto &enemy : enemies) {
        if (enemy_square_c* e = dynamic_cast<enemy_square_c*>(enemy.get())) {
            for (auto it = e->bullets.begin(); it != e->bullets.end();) {
                std::vector<sf::Vector2f> bullet_poly(
                    { 
                        (*it)->body.getPosition()
                        , {(*it)->body.getPosition().x + (*it)->body.getRadius(),(*it)->body.getPosition().y} 
                        , {(*it)->body.getPosition().x,(*it)->body.getPosition().y + (*it)->body.getRadius()}
                        , {(*it)->body.getPosition().x - (*it)->body.getRadius(),(*it)->body.getPosition().y}
                    });
               
                //TODO add collision_sat_convex overload with checking circle to polygon
                if (collision_sat_convex(bullet_poly, player_ship_poly)) {
                    warning("PLAYER HIT BY ENEMY BULLET");
                    it = e->bullets.erase(it);
                    //player_ship->get_damage();
                }
                else {
                    ++it;
                }
            }

            for (size_t i = 0; i < e->body.getPointCount(); ++i) {
                enemy_body_poly.push_back(e->body.getPoint(i) + e->body.getPosition());
            }
        }
        //else if (enemy_square_c* e = dynamic_cast<enemy_triangle_c*>(enemy.get())) {
        //    //TODO DIFFERENT CHECKS ETC
        //}

        
        //check if player bullets collide with this enemy
        //if yes - mark the enemy as dead but do not erase yet (its bullets are still flying)
        //when the last bullet is erased -> erase enemy
        
        if (pistol_c* pistol = dynamic_cast<pistol_c*>(player_ship->weapon_current.get())) {
            for (auto it = pistol->bullets.begin(); it != pistol->bullets.end();) {
                std::vector<sf::Vector2f> bullet_poly(
                        {
                            (*it)->body.getPosition()
                            , {(*it)->body.getPosition().x + (*it)->body.getRadius(),(*it)->body.getPosition().y}
                            , {(*it)->body.getPosition().x,(*it)->body.getPosition().y + (*it)->body.getRadius()}
                            , {(*it)->body.getPosition().x - (*it)->body.getRadius(),(*it)->body.getPosition().y}
                        });
                
                if (collision_sat_convex(bullet_poly, enemy_body_poly)) {
                    warning("ENEMY HIT BY PLAYER BULLET");
                    it = pistol->bullets.erase(it);
                    //e->get_damage();
                }
                else {
                    ++it;
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
