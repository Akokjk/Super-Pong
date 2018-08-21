#include "game.hpp"

void get_info(Player *player1, Player *enemy, Ball *pong_ball,
  sf::UdpSocket *s_socket, sf::UdpSocket *r_socket, int* count){
    sf::IpAddress recipient = "25.81.202.83";
    sf::IpAddress your_ip = "25.81.202.83";
    unsigned short y_port = 12000;
    unsigned short e_port = 12000;
    std::cout << "Enter your send port: ";
    std::cin >>  y_port;
    std::cout << "Input enemy ip & send port: ";
    std::cin >> recipient >> e_port;
    s_socket->bind(y_port);
    r_socket->bind(e_port);
    s_socket->setBlocking(false);
    r_socket->setBlocking(false);
    while(1){

      sf::Vector2f data[2];
      data[0] = player1->get_location();
      data[1] = pong_ball->get_location();
      std::size_t received = 0;
      if(s_socket->send(data, sizeof(data), recipient, y_port) != sf::Socket::Done) {
        std::cout << "\rError cannot send data";
      }
      sf::Vector2f data1[2];
      if(r_socket->receive(data1, sizeof(data1), received, recipient, e_port)!= sf::Socket::Done){
        std::cout << "\rError cannot recieve data";
      }
      std::cout << "\rReceived " << received << " bytes from " << recipient << " on port " << e_port << std::endl;
      enemy->set_position(data1[0]);
      if( y_port == 2525)pong_ball->set_position(data1[1]);
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

  first = std::thread(get_info, &player1, &enemy, &pong_ball, &s_socket, &r_socket,  &count);
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
  window.draw(enemy.draw());
  window.draw(pong_ball.draw());


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
      pong_ball.check_collision(player1.get_location(), player1.get_size(), player1.is_enemy());
      pong_ball.check_collision(enemy.get_location(), enemy.get_size(), enemy.is_enemy());

      //std::cout << response.getBody() << std::endl;
      // check the status
    }

    if(time1.asMilliseconds() >= 1000 ){
      clock1.restart();
      //std::cout << "\rPPS: " << count <<  std::endl;
      count = 0;
    }

}
