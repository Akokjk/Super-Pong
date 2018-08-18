#include "game.hpp"


Game::Game(sf::RenderWindow &window):
pong_ball(sf::Vector2f(X_RES/2, Y_RES/2), 20, sf::Vector2f(.5, .5), sf::Color(255, 0, 0, 255)),
player1(sf::Vector2f(X_RES/7, Y_RES/2), sf::Vector2f(50, 150), sf::Color(0, 0, 0, 255), false),
enemy(sf::Vector2f(7*X_RES/8, Y_RES/2), sf::Vector2f(50, 150), sf::Color(24, 24, 45, 255), true)
{
  clock.restart();
  screen = sf::Color(255,255,255);
  window.create(
    sf::VideoMode(X_RES, Y_RES),
    "Super Pong",
    sf::Style::Close
  );
  sf::Image icon;
  icon.loadFromFile("superpong.png");
  window.setMouseCursorVisible(false);
  window.setIcon(54,54,icon.getPixelsPtr());

}
void Game::check_events(sf::RenderWindow &window)
{
  while (window.pollEvent(event))
  {
      switch(event.type)
      {
        case sf::Event::Closed:
          window.close();
          break;
      }
  }
}
void Game::draw(sf::RenderWindow &window)
{

  if(pong_ball.get_location().x < 40) screen = sf::Color(255,0,0);
  window.clear(screen);
  window.draw(player1.draw());
  window.draw(enemy.draw());
  window.draw(pong_ball.draw());


  window.display();
}
void Game::update(sf::RenderWindow &window)
{
    time = clock.getElapsedTime();
    if(time.asMilliseconds() % 5 == 0)
    {

      player1.set_position(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
      enemy.set_position(sf::Vector2f(enemy.get_location().x, (pong_ball.get_location().y-(enemy.get_size().y/2))));
      //enemy.set_position(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
      pong_ball.check_collision(player1.get_location(), player1.get_size(), player1.is_enemy());
      pong_ball.check_collision(enemy.get_location(), enemy.get_size(), enemy.is_enemy());

    }
    //update non-timed based events
}
