/**
* @file util.cpp
*
* @brief Utility file containing useful functions as collision detection, etc.
*/
#include "util.h"

/**
* @brief check axis aligned 2D collision of 2 rectangles
* does not work if the rectangles are rotated
* 
* Note: also we do not know if the getPoint(index) always gives the same point of rectangle
* 
* @params defined as sf::RectangleShape
*/
bool collision_aabb(const sf::RectangleShape &r1, const sf::RectangleShape &r2) 
{

	sf::Vector2f a1 = r1.getPoint(0) + r1.getPosition();
	sf::Vector2f b1 = r1.getPoint(1) + r1.getPosition();
	sf::Vector2f c1 = r1.getPoint(2) + r1.getPosition();
	sf::Vector2f d1 = r1.getPoint(3) + r1.getPosition();
	sf::Vector2f a2 = r2.getPoint(0) + r2.getPosition();
	sf::Vector2f b2 = r2.getPoint(1) + r2.getPosition();
	sf::Vector2f c2 = r2.getPoint(2) + r2.getPosition();
	sf::Vector2f d2 = r2.getPoint(3) + r2.getPosition();

	if (c1.x < a2.x) {
		return false;
	}
	else if (a1.x > c2.x) {
		return false;
	}
	else if (c1.y < a2.y) {
		return false;
	}
	else if (a1.y > c2.y) {
		return false;
	}

	return true;
}

/**
* @brief check sat 2D collision of 2 convex polygons
* 
* Separating Axis Theorem
* checks if 2 polygons overlap 
* 
* 1. For each edge of both polygons compute normals
* 2. For each normal project each point of both polygons on the axis with dot product
* 3. Find minimum and maximum value for each polygon projected points
* 4. If the intervals overlap - they collide, otherwise not
*
* @params defined as vectors of points
*/
bool collision_sat_convex(const std::vector<sf::Vector2f>& p1, const std::vector<sf::Vector2f>& p2) 
{
	// For each edge of polygon compute normal
	std::vector<sf::Vector2f> normals;
	compute_normals(normals, p1);
	compute_normals(normals, p2);
	
	//For each normal project each point on the axis with dot product
	for (auto& normal : normals) {
		std::vector<float> projected_points_values1;
		std::vector<float> projected_points_values2;
		project_polygon(projected_points_values1, p1, normal);
		project_polygon(projected_points_values2, p2, normal);

		float min1 = projected_points_values1[0];
		float max1 = projected_points_values1[0];
		for (auto& value : projected_points_values1) {
			if (value < min1) {
				min1 = value;
			}
			if (value > max1) {
				max1 = value;
			}
		}

		float min2 = projected_points_values2[0];
		float max2 = projected_points_values2[0];
		for (auto& value : projected_points_values2) {
			if (value < min2) {
				min2 = value;
			}
			if (value > max2) {
				max2 = value;
			}
		}

		if (min1 > max2 || min2 > max1) {
			return false;
		}

	}

	return true;
}

/**
* @brief compute normals for each edge of polygon
*
* computes normals of each polygon edge and normalizes them
*
* @param normals - output param of normals
* @param poly - vector of points to be computed normals from
*/
void compute_normals(std::vector<sf::Vector2f> &normals, const std::vector<sf::Vector2f> &poly) 
{

	for (size_t i = 0; i < poly.size(); ++i) {
		sf::Vector2f A(poly[i]);
		sf::Vector2f B(poly[(i + 1) % poly.size()]);
		sf::Vector2f normal(-(B.y - A.y), B.x - A.x);
		float normal_length = std::sqrt(normal.x * normal.x + normal.y * normal.y);
		normal /= (normal_length != 0) ? normal_length : 1;
		normals.push_back(normal);
	}

}

void project_polygon(std::vector<float> &projected_points_values, const std::vector<sf::Vector2f>& poly_in, const sf::Vector2f &normal)
{
	for (auto& p : poly_in) {
		projected_points_values.push_back(p.x * normal.x + p.y * normal.y);
	}
}