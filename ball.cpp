#include "ball.hpp"
Ball::Ball(sf::Vector2f get_position, uint8_t get_radius, sf::Vector2f get_magnitude, sf::Color get_color)
{
  position = get_position;
  radius = get_radius;
  magnitude = get_magnitude;
  color = get_color;

  sprite.setFillColor(color);
  sprite.setRadius(radius);
  sprite.setPosition(position);

}
void Ball::set_position(sf::Vector2f get_position)
{

  position = get_position;
  //sprite.setFillColor(sf::Color((int)(position.x)%255, (int)(position.y)%255, (int)(magnitude.x)%255, 255));
  sprite.setPosition(position);
}
void Ball::set_magnitude(sf::Vector2f get_magnitude)
{
  magnitude = get_magnitude;
}
sf::Vector2f Ball::get_location()
{
  return position;
}
sf::Vector2f Ball::get_magnitude()
{
  return magnitude;
}
sf::CircleShape Ball::draw()
{
  return sprite;
}
void Ball::check_collision(sf::Vector2f get_position, sf::Vector2f get_size, bool enemy)
{
  //collosion check for paddles
  //player paddle front side and enemy paddle back side 
  if(position.x >= get_position.x && position.x <= get_position.x+get_size.x+1
    && position.y >= get_position.y && position.y <= get_position.y+get_size.y){
   magnitude.x =  -magnitude.x*1.001;
    position.x = get_position.x+get_size.x+1.5;
    //sprite.setRadius(radius);

  }

    //player paddle back side
    if(position.x >= get_position.x-radius*2.0 && position.x <= get_position.x-2
      && position.y >= get_position.y && position.y <= get_position.y+get_size.y
      && !enemy){
      magnitude.x =  -magnitude.x*1.001;
      position.x = get_position.x-1.5-(float)radius*2.0;
      //sprite.setRadius(radius);
    }
  if(position.x >= get_position.x-radius*2.0 && position.x <= get_position.x-2
    && position.y >= get_position.y && position.y <= get_position.y+get_size.y
    && enemy){
    magnitude.x =  -magnitude.x*1.001;
    position.x = get_position.x-1.5-(float)radius*2.0;
    //sprite.setRadius(radius);
  }
  //Collosion Logic for walls
  if(position.y+(float)radius*2.0 > (float)Y_RES || position.y < 0.0){
    magnitude.y = -magnitude.y;
  }
  if(position.x+(float)radius*2.0 > (float)X_RES || position.x < 0.0){
    magnitude.x = -magnitude.x;
  }
  set_position(get_location() + get_magnitude());
}
