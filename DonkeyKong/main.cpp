/*
 * main.cpp
 *
 *  Created on: 22 de ago. de 2024
 *      Author: Revii
 */

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include "includes/mainFunctions.hpp"

using namespace std;

int main(int argc, char **argv){
	size_t numEscada = 0;
	size_t numPlataforma = 0;
	bool collisionChecker;

	sf::ContextSettings settings;
	sf::VideoMode videoMode(800,600);
	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	Musics backgroundMusic;
	vector<Platforms> platforms = createPlatforms();
	vector<Ladder> ladders = createLadders();
	Player player;
	Kong kong;

	settings.antialiasingLevel = 8;

	sf::RenderWindow window(videoMode, "MineKong", sf::Style::Close | sf::Style::Titlebar, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	if(!textureFundo.loadFromFile("assets/backgroundNight.png")){
		return -1;
	}

	fundoImage.setTexture(textureFundo);

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

	if(!player.isPlayerCreated){
		cout << "Player não criado" << endl;

		return -1;
	}

	while(window.isOpen()){
		sf::Event event;

		player.setVelToZero();

		collisionChecker = false;

		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				backgroundMusic.stop();
				window.close();
			}

			if(event.type == sf::Event::MouseButtonPressed){
				cout << event.mouseButton.y << endl;
			}
		}

		checkPlayerStatus(&player, &collisionChecker, window, numPlataforma, &platforms, &backgroundMusic, numEscada, &ladders, &kong);

		kongAnimations(&kong);

		windowDraw(window, fundoImage, numEscada, numPlataforma, &ladders, &platforms, &player, &kong);

		sf::sleep(sf::milliseconds(10.0f));
	}

	//cout << player.positionYLadder1 << "," << player.positionYLadder2 << "," << player.positionYLadder3 << "," << player.positionYLadder4 << "," << player.positionYLadder5 << "," << player.positionYLadder6 << endl;

	return 0;
}
