#include <SFML/Graphics.hpp>

/**
* @file util.cpp
*
* @brief Utility file containing useful functions as collision detection, etc.
*/

/**
* @brief check 2D collision of 2 rectangles
* 
* @params defined as 2D points
*/
bool collision_rect_2D(
	const sf::Vector2f &a
	, const sf::Vector2f &b
	, const sf::Vector2f &c
	, const sf::Vector2f &d
	, const sf::Vector2f &x
	, const sf::Vector2f &y
	, const sf::Vector2f &z
	, const sf::Vector2f &w
)
{

	//throw NOT_IMPLEMENTED_ERROR;

	return false;
}

/**
* @brief check 2D collision of 2 rectangles
*
* @params defined as sf::RectangleShape
*/
bool collision_rect_2D(const sf::RectangleShape &x, const sf::RectangleShape &y) 
{

	//throw NOT_IMPLEMENTED_ERROR;


	sf::Vector2f xa = x.getPoint(0);
	sf::Vector2f xb = x.getPoint(1);
	sf::Vector2f xc = x.getPoint(2);
	sf::Vector2f xd = x.getPoint(3);
	sf::Vector2f ya = y.getPoint(0);
	sf::Vector2f yb = y.getPoint(1);
	sf::Vector2f yc = y.getPoint(2);
	sf::Vector2f yd = y.getPoint(3);

	if (xa.x < ya.x) {
		//TODO
	}

	return false;
}