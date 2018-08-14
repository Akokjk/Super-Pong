#ifndef PONG_H
#define PONG_H
//Headers
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdint>
#include <ctime>
#include "player.hpp"
#include "ball.hpp"
#define T_RATIO 1.8
#define Y_RES 800.0
#define X_RES (Y_RES*T_RATIO)
//prototypes
void fps_counter(sf::RenderWindow &window, time_t *last, int *count);

//Holds information on the player


#endif
