#ifndef _BALL_HPP
#define _BALL_HPP
#include "main.hpp"
class Ball
{
  private:
    sf::Vector2f        position;
    uint8_t             radius;
    sf::Vector2f        magnitude;
    sf::Color           color;
    sf::CircleShape     sprite;
  public:
    Ball(
      sf::Vector2f      get_position,
      uint8_t           get_radius,
      sf::Vector2f      get_magnitude,
      sf::Color         get_color
    );
    void set_position(
      sf::Vector2f      get_position
    );
    void set_magnitude(
      sf::Vector2f      get_magnitude
    );
    void check_collision(
      sf::Vector2f      get_position,
      sf::Vector2f      get_size,
      bool              enemy
    );
    sf::Vector2f get_location();
    sf::Vector2f get_magnitude();
    sf::CircleShape draw();

};
#endif
