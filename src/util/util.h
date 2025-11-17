#pragma once
#include "logger/logger.h"
#include <SFML/Graphics.hpp>
#include <memory>
bool collision_aabb(const sf::RectangleShape& r1, const sf::RectangleShape& r2);
bool collision_sat_convex(const std::vector<sf::Vector2f>& p1, const std::vector<sf::Vector2f>& p2);
void compute_normals(std::vector<sf::Vector2f>& normals, const std::vector<sf::Vector2f>& poly);
void project_polygon(std::vector<float>& projected_points, const std::vector<sf::Vector2f>& poly, const sf::Vector2f& normal);


