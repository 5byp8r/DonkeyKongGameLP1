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

#include "sounds.hpp"
#include "musics.hpp"
#include "platforms.hpp"
#include "ladder.hpp"
#include "Kong.hpp"
#include "player.hpp"
#include "barrel.hpp"

using namespace std;

vector<Platforms> createPlatforms();

string setIcon(sf::RenderWindow &window);

vector<Ladder> createLadders();

void checkPlayerStatus(Player *player, vector<Barrel> *barrels, size_t numBarrels, bool *collisionCheckerPlayer, vector<bool> *collisionCheckerBarrels, sf::RenderWindow &window, size_t numPlataforma, vector<Platforms> *platforms, Musics *music, size_t numEscada, vector<Ladder> *ladders, Kong *kong, bool *isDead, bool *isWin);

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, size_t numBarrels, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player, vector<Barrel> *barrels, Kong *kong);

void kongAnimations(Kong *kong, vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrel, sf::Texture *textureBarrel);

void barrelCreator(vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrels, sf::Texture *textureBarrel, Kong *kong);

void deadDetector(Player *&player, vector<Barrel> *barrels, Kong *&kong, bool *isDead, bool *isWin, Musics *music);

#endif /* SOURCE_MAINFUNCTIONS_HPP_ */
