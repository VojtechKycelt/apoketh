#pragma once
#include <SFML/System/Vector2.hpp>

inline sf::Vector2 WINDOW_DIMENSIONS = { 960u, 540u };
inline sf::Vector2f WINDOW_SIZE = { static_cast<float>(WINDOW_DIMENSIONS.x), static_cast<float>(WINDOW_DIMENSIONS.y) };