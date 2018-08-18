#include "player.hpp"
Player::Player(sf::Vector2f get_position, sf::Vector2f get_scale, sf::Color get_color, bool get_enemy)
{
	 		position =  get_position;
			scale = 		get_scale;
			color = 		get_color;
			enemy = 		get_enemy;
			sprite.setFillColor(color);
			sprite.setSize(scale);
			sprite.setPosition(position);

}

void Player::set_position(sf::Vector2f get_position){
	position = get_position;
	sprite.setPosition(position);
}
sf::Vector2f Player::get_location(){
	return position;
}
sf::Vector2f Player::get_size(){
	return scale;
}
sf::RectangleShape Player::draw(){
	return sprite;
}

bool Player::is_enemy(){
	return enemy;
}
