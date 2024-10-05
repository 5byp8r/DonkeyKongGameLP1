/*
 * main.cpp
 *
 *  Created on: 22 de ago. de 2024
 *      Author: Revii
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "includes/mainFunctions.hpp"

using namespace std;

int main(int argc, char **argv){
	std::srand(std::time(0));

	size_t numEscada = 0;
	size_t numPlataforma = 0;
	size_t numBarrels = 0;
	bool collisionCheckerPlayer;
	vector<bool> collisionCheckerBarrels;

	sf::ContextSettings settings;
	sf::VideoMode videoMode(800,600);
	sf::Texture textureFundo;
	sf::Texture* textureBarrel = new sf::Texture;
	sf::Sprite fundoImage;

	Musics backgroundMusic;
	vector<Platforms> platforms = createPlatforms();
	vector<Ladder> ladders = createLadders();
	vector<Barrel> barrels;
	Player* player = new Player();
	//Barrel* barrel = new Barrel();
	Kong* kong = new Kong();
	bool isDead = false;
	bool isWin = false;

	settings.antialiasingLevel = 8;

	sf::RenderWindow window(videoMode, "MineKong", sf::Style::Close | sf::Style::Titlebar, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	if(!textureFundo.loadFromFile("assets/backgroundNight.png")){
		return -1;
	}

	fundoImage.setTexture(textureFundo);

	if(!textureBarrel->loadFromFile("assets/barrel.png")){
		return -1;
	}

	textureBarrel->setSmooth(true);

	if(!backgroundMusic.setAudio("assets/music.ogg")){
		cout << "Impossível criar o som" << endl;

		return -1;
	}

	backgroundMusic.play();

	if(platforms.empty()){
		cout << "Impossível criar plataformas" << endl;

		return -1;
	}

	if(setIcon(window) == "error"){
		cout << "Impossível criar o ícone" << endl;
		return -1;
	}

	if(ladders.empty()){
		cout << "Impossível criar plataformas" << endl;

		return -1;
	}

	if(!player->isPlayerCreated){
		cout << "Player não criado" << endl;

		return -1;
	}

	if(!kong->isKongCreated){
		cout << "Kong não criado" << endl;

		return -1;
	}

	while(window.isOpen()){
		sf::Event event;

		kongAnimations(kong, &barrels, &collisionCheckerBarrels, textureBarrel);

		deadDetector(player, &barrels, kong, &isDead, &isWin, &backgroundMusic);

		player->setVelToZero();

		collisionCheckerPlayer = false;
		for(numBarrels = 0; numBarrels < barrels.size(); numBarrels++){
		collisionCheckerBarrels.at(numBarrels) = false;
		}

		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				backgroundMusic.stop();
				window.close();
			}

			if(event.type == sf::Event::MouseButtonPressed){
				cout << event.mouseButton.x << "," << event.mouseButton.y << endl;
			}
		}

		checkPlayerStatus(player, &barrels, numBarrels, &collisionCheckerPlayer, &collisionCheckerBarrels, window, numPlataforma, &platforms, &backgroundMusic, numEscada, &ladders, kong, &isDead, &isWin);

		windowDraw(window, fundoImage, numEscada, numPlataforma, numBarrels, &ladders, &platforms, player, &barrels, kong);

		sf::sleep(sf::milliseconds(10.0f));
	}

	delete player;
    delete kong;
	delete textureBarrel;

	//cout << player.positionYLadder1 << "," << player.positionYLadder2 << "," << player.positionYLadder3 << "," << player.positionYLadder4 << "," << player.positionYLadder5 << "," << player.positionYLadder6 << endl;

	return 0;
}
