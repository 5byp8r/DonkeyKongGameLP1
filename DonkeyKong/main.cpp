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

vector<Platforms> createPlatforms(	){
	int contadorChaoPosition = 0;
	int floorRotation = 0;
	int positionX = 0;
	int positionY = 570;
	float rotation = 0.f;

	vector<Platforms> plataformas;

	for(int i = 0; i < 141; i++){
		if(i < 24){
			positionX = 41 + contadorChaoPosition;
		}
		else {
			if(i == 24){
				contadorChaoPosition = 0;
			}
			if(i < 47){
				positionX = 61 + contadorChaoPosition;
				positionY = 480 + floorRotation;
				rotation = 2.f;
				floorRotation++;
			}
			else {
				if(i == 47){
					contadorChaoPosition = 0;
					floorRotation = 0;
				}
				if(i < 69){
					positionX = 91 + contadorChaoPosition;
					positionY = 420 - floorRotation;
					rotation = -1.f;
					floorRotation++;
				}
				else {
					if(i == 69){
						contadorChaoPosition = 0;
						floorRotation = 0;
					}
					if(i < 91){
						positionX = 61 + contadorChaoPosition;
						positionY = 320 + floorRotation;
						rotation = 3.f;
						floorRotation++;
					}
					else {
						if(i == 91){
							contadorChaoPosition = 0;
							floorRotation = 0;
						}
						if(i < 113){
						positionX = 91 + contadorChaoPosition;
						positionY = 260 - floorRotation;
						rotation = -1.f;
						floorRotation++;
						}
						else {
							if(i == 113){
								contadorChaoPosition = 0;
								floorRotation = 0;
							}
							if(i < 123){
							positionX = 691 - contadorChaoPosition;
							positionY = 175 - floorRotation;
							rotation = 0.5f;
							floorRotation++;
							}
							else {
								if(i < 135){
								positionX = 691 - contadorChaoPosition;
								positionY = 175 - floorRotation;
								rotation = 0.f;
								}
								else {
									if(i == 135){
										contadorChaoPosition = 0;
										floorRotation = 0;
									}
									if(i < 139){
									positionX = 296 + contadorChaoPosition;
									positionY = 85;
									}
									else {
										if(i == 139){
											contadorChaoPosition = 0;
										}
										if(i < 141){
										positionX = 266 - contadorChaoPosition;
										positionY = 100;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		Platforms plataforma(sf::Vector2f(30,15), positionX, positionY, rotation);

		plataformas.push_back(plataforma);

		contadorChaoPosition += 30;
	}

	contadorChaoPosition = 0;

	return plataformas;
}


int main(int argc, char **argv){
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800,600), "Donkey Kong", sf::Style::Default, settings);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	bool collisionChecker;

	size_t numPlataforma=0;

	vector<Platforms> platforms = createPlatforms();

	sf::Texture platformTexture;

	if(!platformTexture.loadFromFile("assets/floorMinecraft.png")){
		return -1;
	}

	platformTexture.setSmooth(true);

	for(size_t i = 0; i < platforms.size(); i++){
		platforms.at(i).setTexture(platformTexture);
	}

	sf::Image icon = sf::Image { };
	if(!icon.loadFromFile("assets/iconPage.png")){
		return -1;
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	Player player;

	if(!player.isPlayerCreated){
		cout << "Player não criado" << endl;

		return -1;
	}

	Ladder ladder;

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

		ladder.draw(window);

		for(numPlataforma = 0; numPlataforma<platforms.size();numPlataforma++){
			window.draw(platforms[numPlataforma].getShape());
		};

		player.draw(window);

		window.display();
		sf::sleep(sf::milliseconds(10.0f));
	}

	return 0;
}
