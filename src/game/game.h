#pragma once

#include "../input/input_manager.h"
#include "../ship/ship.h"
#include <memory>

class Game {
	
	std::unique_ptr<Ship> player_ship;
	sf::Vector2f window_size;
	InputManager& inputManager;
	sf::RenderWindow& window;
	sf::Clock clock_motion_blur;
	sf::Time start_time;

public:
	Game(
		const sf::Vector2f& _window_size,
		InputManager& _inputManager,
		sf::RenderWindow& _window
	) :
		window_size(_window_size),
		inputManager(_inputManager),
		window(_window)
	{}
	void init();
	void update(float delta_time);
	void draw(sf::RenderTarget& target);

private:
	void handle_inputs(float delta_time);
	void ship_shoot(float delta_time);
	void ship_move(float delta_time);
	void ship_move_motion_blur();
};