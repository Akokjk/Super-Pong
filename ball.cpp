#include "ball.hpp"

Ball::Ball(uint8_t Gradius, sf::Vector2f Gvelocity,  sf::Vector2f origin, sf::Color color){
  pos = origin;
  velocity = Gvelocity;
  cc = color;
  ball.setRadius(Gradius);
  ball.setFillColor(cc);
  ball.setPosition(pos);
  ball.setOrigin(Gradius/2, Gradius/2);
}
void Ball::updatePos(int x, int y){
  pos = sf::Vector2f(x, y);
}
sf::Vector2f Ball::GetPos(){
  return pos;
}
sf::Vector2f Ball::getVel(){
  return velocity;
}
void Ball::updateVel(int x, int y){
  velocity = sf::Vector2f(x, y);
}
void Ball::draw(sf::RenderWindow &Window){
    ball.setPosition(pos);
    Window.draw(ball);
}
//Takes the pattle posistions and also the size of them, this should work at any resolution 
void Ball::checkBounce(sf::Vector2f p1pos, sf::Vector2f p2pos, sf::Vector2f size){
  //wall collision
  if(pos.x+radius >= X_RES || pos.x+radius <= 0){
    velocity = sf::Vector2f(-velocity.x, velocity.y);
  }
  if(pos.y+radius >= Y_RES || pos.y+radius <= 0){
    velocity.y = -velocity.y;
  }

  //paddle collision logic, this needs to be better implemented
  if(pos.y+radius <= p1pos.y + size.y &&  pos.y+radius >= p1pos.y - size.y
    &&  pos.x+radius <= p1pos.x + size.x &&  pos.x+radius >= p1pos.x - size.x){
      velocity.x = -velocity.x;
      pos.x += size.x/2;
    }
    //enemy paddle
    if(pos.y+radius <= p2pos.y + size.y &&  pos.y+radius >= p2pos.y - size.y
      &&  pos.x+radius <= p2pos.x + size.x &&  pos.x+radius >= p2pos.x - size.x){
        velocity.x = -velocity.x;
        pos.x -= size.x/2;
      }
}
