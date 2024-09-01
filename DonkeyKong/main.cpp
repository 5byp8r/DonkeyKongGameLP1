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
#include "player.hpp"
#include "platforms.hpp"
#include "ladder.hpp"

int main(int argc, char **argv){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800,600), "Donkey Kong", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	bool collisionChecker;

	sf::Texture textureFundo;
	sf::Sprite fundoImage;

	if(!textureFundo.loadFromFile("assets/background.jpg")){
		return -1;
	}

	fundoImage.setTexture(textureFundo);

	vector<Platforms> platforms;
	sf::Texture platformTexture;
	size_t numPlataforma=0;
	int contadorChaoPosition = 0;
	int floorRotation = 0;
	int positionXPlatform = 0;
	int positionYPLatform = 0;
	float rotation = 0.f;

	for(int i = 0; i < 141; i++){
		Platforms platform(i, sf::Vector2f(30,15), &contadorChaoPosition, &floorRotation, &positionXPlatform, &positionYPLatform, &rotation);
		platforms.push_back(platform);
	}

	if(!platformTexture.loadFromFile("assets/floorMinecraft.png")){
		return -1;
	}

	for(size_t i = 0; i < platforms.size(); i++){
		platforms.at(i).setTexture(platformTexture);
	}

	platformTexture.setSmooth(true);

	sf::Image icon = sf::Image { };
	if(!icon.loadFromFile("assets/iconPage.png")){
		return -1;
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	vector<Ladder> escadas;
	sf::Texture ladderTexture;
	size_t numEscada=0;
	int contadorEscadaPosition = 0;
	int positionXLadder = 0;
	int positionYLadder = 0;

	for(int i = 1; i < 141; i++){
		Ladder ladder(i, sf::Vector2f(30,30), &contadorEscadaPosition, &positionXLadder, &positionYLadder);
		escadas.push_back(ladder);
	}

	if(!ladderTexture.loadFromFile("assets/minecraftLadder.png")){
		return -1;
	}

	for(numEscada = 0; numEscada < escadas.size(); numEscada++){
		escadas.at(numEscada).setTexture(&ladderTexture);
	}

	ladderTexture.setSmooth(true);

	Player player;

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
				window.close();
			}
		}

		if(player.getPositionY() > 600 + player.getSprite().getLocalBounds().height * player.getSprite().getScale().y){
			window.close();
		}

		player.move();

		player.setisColliding(collisionChecker);

		for(numPlataforma = 0; numPlataforma < platforms.size(); numPlataforma++){
			if(player.collisionTest(platforms.at(numPlataforma))){
				collisionChecker = true;
				break;
			}
		}

		player.setisColliding(collisionChecker);

		window.clear(sf::Color::Black);

		window.draw(fundoImage);

		for(numEscada = 0; numEscada < escadas.size(); numEscada++){
			escadas[numEscada].draw(window);
		};

		for(numPlataforma = 0; numPlataforma<platforms.size();numPlataforma++){
			window.draw(platforms[numPlataforma].getShape());
		};

		player.draw(window);

		window.display();
		sf::sleep(sf::milliseconds(10.0f));
	}

	return 0;
}
