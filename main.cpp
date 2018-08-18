#include "game.hpp"
int main()
{
  sf::RenderWindow window;
  Game game(window);
  while (window.isOpen())
  {
    game.check_events(window);
    game.update(window);
    game.draw(window);
  }
  return 0;
}
