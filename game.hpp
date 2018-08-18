#ifndef _GAME_HPP
#define _GAME_HPP
#include "main.hpp"
#include "ball.hpp"
#include "player.hpp"


class Game
{
  private:
    sf::Clock   clock;
    sf::Time    time;
    sf::Event   event;
    Player      player1;
    Player      enemy;
    Ball        pong_ball;
    sf::Color   screen; 


  public:
    Game(sf::RenderWindow &window);
    void check_events(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);

};
#endif
