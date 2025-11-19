/**
 * @file enemy.cpp
 *
 * @brief abstract enemy definitions (implementation).
 *
 */

#include "enemy.h"

/**
 * @brief Constructor.
 *
 */
enemy_c::enemy_c(
	const enemy_type_t &type, 
	const enemy_state_t &state,
	const sf::Vector2f &velocity,
	const sf::Vector2f &position, 
	const float speed,
	const float steering_force,
	const float is_alive,
	const float hp,
	const float armor_points,
	const float shield_points, 
	const float dmg, 
	const float armor_pen, 
	const float shield_pen, 
	const bool ready_to_fire
) 
	: next_path_point_idx(0)
	, type(type)
	, state(state)
	, velocity(velocity)
	, position(position)
	, speed(speed)
	, steering_force(steering_force)
	, is_alive(is_alive)
	, hp(hp)
	, armor_points(armor_points)
	, shield_points(shield_points)
	, dmg(dmg)
	, armor_pen(armor_pen)
	, shield_pen(shield_pen)
	, ready_to_fire(ready_to_fire)
{
}

/**
 * @brief Destructor.
 *
 */
enemy_c::~enemy_c()
{

}

/**
 * @brief Init.
 *
 */
void enemy_c::init()
{
	//load path from file ?
	path.push_back({100,100});
	path.push_back({50,300});
	path.push_back({200,400});
	path.push_back({600,300});
	path.push_back({700,500});
	path.push_back({600,200});

	if (path.size() > 0) {

	}
}

/**
 * @brief Update called every frame.
 *
 */
void enemy_c::update(const float delta_time)
{

}

/**
 * @brief draw to render target.
 *
 */
void enemy_c::draw(sf::RenderTarget& target)
{

}

bool enemy_c::can_be_destroyed() {

}

void enemy_c::move(const float delta_time) {

	if (path.size() > 1) {
		move_follow_path(delta_time);
	}

	position += velocity * delta_time;
	
}

void enemy_c::move_follow_path(const float delta_time)
{
	sf::Vector2f *next_pos = &path[next_path_point_idx];
	sf::Vector2f direction = *next_pos - position;

	float dist_from_point = direction.lengthSquared(); //use linear lenght maybe not squared?

	if (dist_from_point > 0.01) {
		sf::Vector2f desired_vel = direction.normalized() * speed;
		sf::Vector2f steering = (desired_vel - velocity);
		steering *= steering_force;
		velocity += steering * delta_time;
	}

	if (dist_from_point < 20.f * 20.f) {
		next_path_point_idx = (next_path_point_idx + 1) % path.size();
		std::vector<sf::Vector2f> directions;
		directions.reserve(3);
		directions.push_back({ 0.05f,0.1f });
		directions.push_back({ -0.05f,0.1f });
		directions.push_back({ 0.f,0.12f });
		fire(directions);
	}
}

void enemy_c::fire()
{

}

void enemy_c::fire(const std::vector<sf::Vector2f>& directions)
{

}

void enemy_c::fire(const sf::Vector2f& pos) 
{

}

void enemy_c::get_damage(float damage)
{
	hp -= damage;
	if (hp <= 0) {
		is_alive = false;
	}
}

