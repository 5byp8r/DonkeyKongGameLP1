/*
 * mainFunctions.hpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#ifndef SOURCE_MAINFUNCTIONS_HPP_
#define SOURCE_MAINFUNCTIONS_HPP_

#include <iostream>
#include <iomanip>
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

bool testCreation(sf::RenderWindow &window, sf::Texture *textureFundo, sf::Sprite *fundoImage, sf::Texture *textureBarrel, sf::Font *font, Musics *backgroundMusic, vector<Platforms> *platforms, vector<Ladder> *ladders, vector<Barrel> *barrels, Player *player, Kong *kong);

string setIcon(sf::RenderWindow &window);

vector<Ladder> createLadders();

void checkPlayerStatus(Player *player, vector<Barrel> *barrels, size_t numBarrels, bool *collisionCheckerPlayer, vector<bool> *collisionCheckerBarrels, sf::RenderWindow &window, size_t numPlataforma, vector<Platforms> *platforms, Musics *music, size_t numEscada, vector<Ladder> *ladders, Kong *kong, bool *isDead, bool *isWon);

void hudUpdater(sf::Text *txtTime, sf::Font *font, sf::Time *gameTime, sf::RenderWindow &window);

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, size_t numBarrels, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player, vector<Barrel> *barrels, Kong *kong, sf::Text *txtTime);

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, size_t numBarrels, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player, vector<Barrel> *barrels, Kong *kong, sf::Text *txtTime, sf::Text *txtPause1, sf::Text *txtPause2);

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, sf::Text *txtWin1, sf::Text *txtWin2, sf::Text *txtWin3);

void kongAnimations(Kong *kong, vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrel, sf::Texture *textureBarrel);

void barrelCreator(vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrels, sf::Texture *textureBarrel, Kong *kong);

void deadDetector(Player *&player, vector<Barrel> *barrels, Kong *&kong, bool *isDead, Musics *music, sf::Clock *gameClock, sf::Time *gameTime, sf::Time *pausedTime, sf::Time *pausedTimeOld);

void timeManager(sf::Clock *gameClock, sf::Time *gameTime, sf::Time *pausedTime, sf::Time *pausedTimeOld, sf::Time *winTime, sf::Time *recordTime, bool *timePause, bool *isPaused, bool *isWon);

void pauseMenu(sf::Text *txtPause1, sf::Text *txtPause2, sf::Font *font, sf::RenderWindow &window);

void winMenu(sf::Text *txtWin1, sf::Text *txtWin2, sf::Text *txtWin3, sf::Font *font, sf::Time *winTime, sf::Time *recordTime, sf::RenderWindow &window);

#endif /* SOURCE_MAINFUNCTIONS_HPP_ */
