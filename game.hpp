#ifndef _GAME_HPP
#define _GAME_HPP
#include "main.hpp"
#include "ball.hpp"
#include "player.hpp"


class Game
{
  private:
      sf::Clock           clock;
      sf::Time            time;
      sf::Clock           clock1;
      sf::Time            time1;
      sf::Event           event;
      Player              player1;
      Player              enemy;
      Ball                pong_ball;
      sf::Color           screen;
      sf::UdpSocket       s_socket;
      sf::UdpSocket       r_socket;
      std::thread         first;
      int                 count;
  public:
    Game(sf::RenderWindow &window);
    void check_events(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    int  exit();

};
#endif
