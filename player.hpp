#ifndef _PLAYER_HPP
#define _PLAYER_HPP
#include "main.hpp"
class Player
{
	private:
		sf::Vector2f 					position;
		sf::Vector2f 					scale;
		sf::Color 						color;
		sf::RectangleShape 		sprite;
		bool 									enemy;
	public:
		Player(
			sf::Vector2f 				get_position,
			sf::Vector2f 				get_scale,
			sf::Color 					get_color,
			bool 								get_enemy
		);
		void set_position(
			sf::Vector2f 				get_position
		);
		sf::Vector2f get_location();
		sf::Vector2f get_size();
		bool is_enemy();
		sf::RectangleShape draw();
};
#endif
