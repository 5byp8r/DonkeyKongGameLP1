/*
 * game.hpp
 *
 *  Created on: 5 de out. de 2024
 *      Author: Davi Sollar
 */

#ifndef SRC_GAME_HPP_
#define SRC_GAME_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "mainFunctions.hpp"
using namespace std;

class Game {
private:
		size_t numEscada;
		size_t numPlataforma;
		size_t numBarrels;
		bool collisionCheckerPlayer;
		vector<bool> collisionCheckerBarrels;

		sf::RenderWindow* window;
		sf::ContextSettings settings;
		sf::VideoMode videoMode;
		sf::Clock *gameClock;
		sf::Time *gameTime;
		sf::Time *pausedTime;
		sf::Time *pausedTimeOld;
		sf::Time *winTime;
		sf::Time *recordTime;
		sf::Time *devTime;
		sf::Texture textureFundo;
		sf::Texture* textureBarrel;
		sf::Sprite fundoImage;

		sf::Font font;
		sf::Text txtTime;
		sf::Text txtWin1;
		sf::Text txtWin2;
		sf::Text txtWin3;
		sf::Text txtPause1;
		sf::Text txtPause2;

		Musics backgroundMusic;
		vector<Platforms> platforms;
		vector<Ladder> ladders;
		vector<Barrel> barrels;
		Player* player;
		Kong* kong;
		bool isDead;
		bool isPaused;
		bool timePause;
		bool isWon;

public:
		Game();
		bool start();
		void update();
		~Game();
};

#endif /* SRC_GAME_HPP_ */
