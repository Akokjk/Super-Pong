#ifndef _BALL_HPP
#define _BALL_HPP
#include "pong.hpp"
class Ball{
  private:
    sf::Vector2f pos;
    uint8_t radius;
    sf::Vector2f velocity;
    sf::Color cc;
    sf::CircleShape ball;
  public:
    Ball(uint8_t Gradius, sf::Vector2f Gvelocity,  sf::Vector2f origin, sf::Color color);
    void updatePos(int x, int y);
    sf::Vector2f GetPos();
    sf::Vector2f getVel();
    void updateVel(int x, int y);
    void draw(sf::RenderWindow &Window);
    void checkBounce(sf::Vector2f p1pos, sf::Vector2f p2pos, sf::Vector2f size);
};
#endif
