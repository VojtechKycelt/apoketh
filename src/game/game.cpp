#include "game.h"

void Game::init()
{
    start_time = clock_motion_blur.restart();

	float ship_size = 40.f;
	float ship_speed = 0.3f;
	player_ship = std::make_unique<Ship>(ship_size, ship_speed, sf::Vector2f{ (window_size.x / 2) - ship_size / 2, window_size.y - ship_size });
    player_ship->init();

}

void Game::update(float delta_time)
{
    handle_inputs(delta_time);

    player_ship->update(delta_time);

}

void Game::draw(sf::RenderTarget& target) {
    player_ship->draw(target);
}

void Game::handle_inputs(float delta_time) {

    ship_move(delta_time);

    ship_shoot(delta_time);
}

void Game::ship_move(float delta_time)
{
    //if motion blur enabled
    ship_move_motion_blur();

    if (inputManager.key_pressed_left) {

        player_ship->move_left(delta_time);

    }

    if (inputManager.key_pressed_right) {

        player_ship->move_right(delta_time, window_size.x);

    }
    player_ship->getBody().setFillColor(sf::Color::Green);
    window.draw(player_ship->getBody());
}

void Game::ship_move_motion_blur() {
    if (player_ship->getOldShipPositions().size() < player_ship->getSpeed() * player_ship->getMotionBlurTime() / 10) {
        player_ship->getOldShipPositions().push_back(player_ship->getPosition().x);
    }

    if (player_ship->getOldShipPositions().size() > 2) {
        for (int i = 0; i < player_ship->getOldShipPositions().size() - 2; i++) {
            float g_range = 50;
            float g = fmin(i * (g_range / player_ship->getOldShipPositions().size()), g_range);
            player_ship->getBody().setFillColor(sf::Color(0, g, 0));

            if (player_ship->getOldShipPositions()[i] < player_ship->getOldShipPositions()[i + 1]) {
                for (int j = player_ship->getOldShipPositions()[i]; j < player_ship->getOldShipPositions()[i + 1]; ++j) {
                    player_ship->getBody().setPosition({ static_cast<float>(j),player_ship->getPosition().y });
                    window.draw(player_ship->getBody());
                }
            }
            else {
                for (int j = player_ship->getOldShipPositions()[i]; j > player_ship->getOldShipPositions()[i + 1]; --j) {
                    player_ship->getBody().setPosition({ static_cast<float>(j),player_ship->getPosition().y });
                    window.draw(player_ship->getBody());
                }
            }
        }
    }
    else {
        for each(float old_pos in player_ship->getOldShipPositions())
        {
            player_ship->getBody().setPosition({ old_pos,player_ship->getPosition().y });
            window.draw(player_ship->getBody());
        }
    }

    if (clock_motion_blur.getElapsedTime().asMilliseconds() - start_time.asMilliseconds() > player_ship->getMotionBlurTime() || (!player_ship->getOldShipPositions().empty() && player_ship->getOldShipPositions().back() != player_ship->getPosition().x)) {
        player_ship->getOldShipPositions().pop_front();
    }
}


void Game::ship_shoot(float delta_time) {
    if (inputManager.key_pressed_space) {
        player_ship->shoot();
        window.draw(player_ship->getBody());
    }
}
