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

				//sf::Texture					sprite;

				sf::Vector2f				velocity;
				sf::Vector2f				position;
				float						speed;
				float						steering_force;
				//float						max_speed;
				//float						acceleration;
				
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
					, const sf::Vector2f &velocity
					, const sf::Vector2f &position
					, const float speed
					, const float steering_force
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

		virtual void						move(const float delta_time);
		virtual void						move_follow_path(const float delta_time);

		virtual void						fire();
		virtual void						fire(const std::vector<sf::Vector2f> &directions);
		virtual void						fire(const sf::Vector2f& pos);
};