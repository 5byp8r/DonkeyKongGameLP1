/*
 * game.cpp
 *
 *  Created on: 5 de out. de 2024
 *      Author: Davi Sollar
 */

#include "../includes/game.hpp"

Game::Game(){
	numEscada = 0;
	numPlataforma = 0;
	numBarrels = 0;
	videoMode.width = 800;
	videoMode.height = 600;
	gameClock = new sf::Clock;
	gameTime = new sf::Time;
	*gameTime = sf::Time::Zero;
	pausedTime = new sf::Time;
	*pausedTime = sf::Time::Zero;
	pausedTimeOld = new sf::Time;
	*pausedTimeOld = sf::Time::Zero;
	winTime = new sf::Time;
	*winTime = sf::Time::Zero;
	recordTime = new sf::Time;
	*recordTime = sf::seconds(99999999.9f);
	devTime = new sf::Time;
	*devTime = sf::seconds(20.0f);
	textureBarrel = new sf::Texture;
	platforms = createPlatforms();
	ladders = createLadders();
	player = new Player();
	kong = new Kong();
	alex = new Alex();
	isDead = false;
	isPaused = false;
	isWon = false;
}

bool Game::start(){
	std::srand(std::time(0));

	settings.antialiasingLevel = 8;

	window = new sf::RenderWindow(videoMode, "MineKong", sf::Style::Close | sf::Style::Titlebar, settings);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	if(!testCreation(*window, &textureFundo, &fundoImage, textureBarrel, &font, &backgroundMusic, &platforms, &ladders, &barrels, player, kong, alex)){
		return false;
	}

	return true;
}

void Game::update(){
	gameClock->restart();

	while(window->isOpen()){
			sf::Event event;

			while(window->pollEvent(event)){
				if(event.type == sf::Event::Closed){
					backgroundMusic.stop();
					window->close();
				}
				if (event.type == sf::Event::EventType::KeyPressed){
					if (event.key.code == sf::Keyboard::Escape){
						if(!isWon){
							isPaused = !(isPaused);
						}
						if (isPaused){
							backgroundMusic.pause();
						} else {
							backgroundMusic.play();
						}
					}
					if (event.key.code == sf::Keyboard::Enter){
						if(isWon){
							isWon = false;
							isDead = true;
						}
					}
				}
			}

			if(!isPaused && !isWon){
				deadDetector(player, &barrels, kong, &isDead, &backgroundMusic, gameClock, gameTime, pausedTime, pausedTimeOld);

				timeManager(gameClock, gameTime, pausedTime, pausedTimeOld, winTime, recordTime, devTime, &timePause, &isPaused, &isWon);

				hudUpdater(&txtTime, &font, gameTime, *window);

				kongAnimations(kong, &barrels, &collisionCheckerBarrels, textureBarrel);

				player->setVelToZero();

				collisionCheckerPlayer = false;
				for(numBarrels = 0; numBarrels < barrels.size(); numBarrels++){
					collisionCheckerBarrels.at(numBarrels) = false;
				}

				checkPlayerStatus(player, &barrels, numBarrels, &collisionCheckerPlayer, &collisionCheckerBarrels, *window, numPlataforma, &platforms, &backgroundMusic, numEscada, &ladders, kong, &isDead, &isWon);

				windowDraw(*window, fundoImage, numEscada, numPlataforma, numBarrels, &ladders, &platforms, player, &barrels, kong, &txtTime, alex);
			}
			else if(isPaused && !isWon){
				timeManager(gameClock, gameTime, pausedTime, pausedTimeOld, winTime, recordTime, devTime, &timePause, &isPaused, &isWon);

				pauseMenu(&txtPause1, &txtPause2, &font, *window);

				windowDraw(*window, fundoImage, numEscada, numPlataforma, numBarrels, &ladders, &platforms, player, &barrels, kong, &txtTime, &txtPause1, &txtPause2, alex);
			}
			else if(!isPaused && isWon){
				backgroundMusic.stop();

				timeManager(gameClock, gameTime, pausedTime, pausedTimeOld, winTime, recordTime, devTime, &timePause, &isPaused, &isWon);

				winMenu(&txtWin1, &txtWin2, &txtWin3, &font, winTime, recordTime, devTime, *window);

				windowDraw(*window, fundoImage, &txtWin1, &txtWin2, &txtWin3);
			}

			sf::sleep(sf::milliseconds(10.0f));
		}
}

Game::~Game(){
	delete window;
	delete player;
    delete kong;
    delete alex;
	delete textureBarrel;
	delete gameClock;
	delete gameTime;
	delete pausedTime;
	delete pausedTimeOld;
	delete winTime;
	delete recordTime;
}
