#pragma once

#include "../ship/ship.h"
#include "../input/input_manager.h"
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

private:
	void handle_inputs(float delta_time);
	void move_player(float delta_time);
	void move_ship_motion_blur();
};