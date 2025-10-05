#include <SFML/Graphics.hpp>

bool collision_rect_2D(sf::Vector2f a, sf::Vector2f b, sf::Vector2f c, sf::Vector2f d, sf::Vector2f x, sf::Vector2f y, sf::Vector2f z, sf::Vector2f w) {

	//throw NOT_IMPLEMENTED_ERROR;

	return false;
}

bool collision_rect_2D(sf::RectangleShape x, sf::RectangleShape y) {

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