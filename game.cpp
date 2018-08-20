#include "game.hpp"

void get_info(Player *player1, Player *enemy, Ball *pong_ball,
  sf::UdpSocket *socket, int* count){
    sf::IpAddress recipient = "localhost";
    unsigned short port = 12000;
    //std::cout << "Input Enemy IP: "
    //std::cin >> recipient;
    //std::cout << "Input Enemy Port: "
    //'std::cin >> port;
    while(1){

      sf::Vector2f data[1];
      data[0] = player1->get_location();
      std::size_t received;
      socket->send(data, sizeof(data), recipient, port);
      socket->receive(data, sizeof(data), received, recipient, port);
      enemy->set_position(data[0]);
      count[0]++;
  }
}

Game::Game(sf::RenderWindow &window):
pong_ball(sf::Vector2f(X_RES/2, Y_RES/2), 20, sf::Vector2f(.5, .5), sf::Color(255, 0, 0, 255)),
player1(sf::Vector2f(X_RES/7, Y_RES/2), sf::Vector2f(50, 150), sf::Color(0, 0, 0, 255), false),
enemy(sf::Vector2f(7*X_RES/8, Y_RES/2), sf::Vector2f(50, 150), sf::Color(24, 24, 45, 255), true)
{
  clock.restart();
  clock1.restart();
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
  socket.bind(54000);
  first = std::thread(get_info, &player1, &enemy, &pong_ball, &socket, &count);
  first.detach();

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
        default:
          break;
      }
  }
}
void Game::draw(sf::RenderWindow &window)
{

  //if(pong_ball.get_location().x < 40) screen = sf::Color(255,0,0);
  window.clear(screen);
  window.draw(player1.draw());

  //window.draw(pong_ball.draw());


  window.display();
}





void Game::update(sf::RenderWindow &window)
{

    time = clock.getElapsedTime();
    time1 = clock1.getElapsedTime();

    if(time.asMilliseconds() >= 5 )
    {
      clock.restart();
      player1.set_position(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
      //enemy.set_position(sf::Vector2f(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));


      //std::cout << response.getBody() << std::endl;
      // check the status
    }

    if(time1.asMilliseconds() >= 1000 ){
      clock1.restart();
      std::cout << "\rPPS: " << count;
      count = 0;
    }

}
