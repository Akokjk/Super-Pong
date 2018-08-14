#ifndef _PLAYER_HPP
#define _PLAYER_HPP
#include "pong.hpp"
class Player{
	private:
		sf::Vector2f pos;
		sf::Vector2f size;
		sf::Color cc;
		bool enemy;
		sf::RectangleShape player;
	public:
		Player(sf::Vector2f origin, sf::Vector2f size, sf::Color getColor, bool IsEnemy);
		void UpdatePos(int x, int y);
		sf::Vector2f GetPos();
		bool isEnemy();
		void Draw(sf::RenderWindow &Window);
};
#endif
