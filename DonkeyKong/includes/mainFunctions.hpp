/*
 * mainFunctions.hpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#ifndef SOURCE_MAINFUNCTIONS_HPP_
#define SOURCE_MAINFUNCTIONS_HPP_

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "player.hpp"
#include "platforms.hpp"
#include "ladder.hpp"

using namespace std;

vector<Platforms> createPlatforms();

string setIcon(sf::RenderWindow &window);

vector<Ladder> createLadders();

void checkPlayerStatus(Player *player, bool *collisionChecker, sf::RenderWindow &window, size_t numPlataforma, vector<Platforms> *platforms);

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player);

#endif /* SOURCE_MAINFUNCTIONS_HPP_ */