#include "player.hpp"
Player::Player(sf::Vector2f origin, sf::Vector2f sizeG, sf::Color getColor, bool IsEnemy){
  pos = origin;
  size = sizeG;
  cc = getColor;
  enemy = IsEnemy;
  player.setSize(size);
  player.setFillColor(cc);
  player.setPosition(pos);
  player.setOrigin(size.x/2, size.y/2);
}
void Player::UpdatePos(int x, int y){
  /*if(x <= X_RES/4 && x >= 0+size.x/2 && !enemy){
    pos = sf::Vector2f(x,y);
  }else if(!enemy){
    pos = sf::Vector2f(player.getPosition(x),y);
  }
  else if(x <= 3*X_RES/4 && x >= 0+size.x/2 && enemy){
    pos = sf::Vector2f(x,y);
  }
  else{
    pos = sf::Vector2f(player.getPosition(x),y);
  }*/
  pos = sf::Vector2f(x,y);
}
sf::Vector2f Player::GetPos(){
  return pos;
}
bool Player::isEnemy(){
  return enemy;
}
//Converts class data into a drawable rectangle
void Player::Draw(sf::RenderWindow &Window){

  if(pos.x <= X_RES/4 && pos.x >= 0+size.x/2 && pos.y <= Y_RES-size.y/2 && pos.y >= 0+size.y/2 && !enemy){
    player.setPosition(pos);
  }
  else if(pos.y <= Y_RES-size.y/2 && pos.y >= 0+size.y/2 && !enemy) {
    player.setPosition(player.getPosition().x, pos.y);
  }
  else if(pos.x <= X_RES/4 && pos.x >= 0+size.x/2 && !enemy) {
    player.setPosition(pos.x, player.getPosition().y);
  }else if(!enemy){
    player.setPosition(player.getPosition().x, player.getPosition().y);
  }
  if(enemy){
    player.setPosition(pos);
  }
  //get network information from the port then update enemy here

  Window.draw(player);
}
