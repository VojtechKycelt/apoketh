/**
 * @file enemy.h
 *
 * @brief abstract enemy definitions (interface).
 *
 */

#pragma once
#include <SFML/Graphics.hpp>
#include "../../util/util.h"
/**
 * @brief Enum for enemy types.
 *
 */
enum enemy_type_t
{
	 ENEMY_TYPE_triangle
	,ENEMY_TYPE_square
	,ENEMY_TYPE_beattle
};

/**
 * @brief Enum for enemy states.
 *
 */
enum enemy_state_t
{
	 ENEMY_STATE_idle
	,ENEMY_STATE_attacking
	,ENEMY_STATE_path_follow
};

/**
 * @brief class enemy
 *
 * 
 */
class enemy_c {
	protected:
				/** Path that enemy moves along */
				std::vector<sf::Vector2f>	path;
				/** Idx to which point travel now */
				size_t						next_path_point_idx;
	public:
				enemy_type_t				type;
				enemy_state_t				state;

				//sf::Texture					sprite;

				sf::Vector2f				velocity;
				sf::Vector2f				position;
				float						speed;
				float						steering_force;
				//float						max_speed;
				//float						acceleration;

				bool						is_alive;

				float						hp;
				float						armor_points;
				float						shield_points;

				float						dmg;
				float						armor_pen;
				float						shield_pen;
				bool						ready_to_fire;

    public:
				enemy_c(
					  const enemy_type_t &type
					, const enemy_state_t &state
					, const sf::Vector2f &velocity
					, const sf::Vector2f &position
					, const float speed
					, const float steering_force
					, const float is_alive
					, const float hp
					, const float armor_points
					, const float shield_points
					, const float dmg
					, const float armor_pen
					, const float shield_pen
					, const bool ready_to_fire
				);
				~enemy_c();

		virtual	void						init();
		virtual	void						update(const float delta_time);
		virtual	void						draw(sf::RenderTarget& target);
		virtual	bool						can_be_destroyed();

		virtual void						move(const float delta_time);
		virtual void						move_follow_path(const float delta_time);

		virtual void						fire();
		virtual void						fire(const std::vector<sf::Vector2f> &directions);
		virtual void						fire(const sf::Vector2f& pos);

		virtual void						get_damage(float damage);
};