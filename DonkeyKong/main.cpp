/*
 * main.cpp
 *
 *  Created on: 22 de ago. de 2024
 *      Author: Revii
 */

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/audio.hpp>
#include <ctime>

/* Antiga função
void createPlatforms(sf::RectangleShape *plataforma){
	int contadorChaoPosition = 0;
	int contadorChaoCriados = 0;
	int floorRotation = 0;

	for(int i = 0; i < 27; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(0 + contadorChaoPosition,570);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
	}

	contadorChaoPosition = 0;

	for(int i = contadorChaoCriados + 1; i < 50; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(50 + contadorChaoPosition, 480 + floorRotation);
		plataforma[i].setRotation(2.f);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
		floorRotation++;
	}

	contadorChaoPosition = 0;
	floorRotation = 0;

	for(int i = contadorChaoCriados + 1; i < 72; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(80 + contadorChaoPosition, 420 - floorRotation);
		plataforma[i].setRotation(-1.f);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
		floorRotation++;
	}

	contadorChaoPosition = 0;
	floorRotation = 0;

	for(int i = contadorChaoCriados + 1; i < 94; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(50 + contadorChaoPosition, 320 + floorRotation);
		plataforma[i].setRotation(1.f);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
		floorRotation++;
	}

	contadorChaoPosition = 0;
	floorRotation = 0;

	for(int i = contadorChaoCriados + 1; i < 116; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(80 + contadorChaoPosition, 260 - floorRotation);
		plataforma[i].setRotation(-1.f);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
		floorRotation++;
	}

	contadorChaoPosition = 0;
	floorRotation = 0;

	for(int i = contadorChaoCriados + 1; i < 126; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(680 - contadorChaoPosition, 185 - floorRotation);
		plataforma[i].setRotation(0.5f);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
		floorRotation++;
	}

	for(int i = contadorChaoCriados + 1; i < 139; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(680 - contadorChaoPosition, 185 - floorRotation);

		contadorChaoPosition += 30;
		contadorChaoCriados++;
	}

	contadorChaoPosition = 0;
	floorRotation = 0;

	for(int i = contadorChaoCriados; i < 142; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(285 + contadorChaoPosition, 100);

		contadorChaoPosition += 30;
	}

	contadorChaoPosition = 0;

	for(int i = 142; i < 144; i++){
		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(255 - contadorChaoPosition, 115);
		contadorChaoPosition += 30;
	}

	contadorChaoPosition = 0;
}*/

void createPlatforms(sf::RectangleShape *plataforma){
	int contadorChaoPosition = 0;
	int floorRotation = 0;
	int positionX = 0;
	int positionY = 570;
	float rotation = 0.f;

	for(int i = 0; i < 141; i++){
		if(i < 24){
			positionX = 30 + contadorChaoPosition;
		}
		else {
			if(i == 24){
				contadorChaoPosition = 0;
			}
			if(i < 47){
				positionX = 50 + contadorChaoPosition;
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
					positionX = 80 + contadorChaoPosition;
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
						positionX = 50 + contadorChaoPosition;
						positionY = 320 + floorRotation;
						rotation = 1.f;
						floorRotation++;
					}
					else {
						if(i == 91){
							contadorChaoPosition = 0;
							floorRotation = 0;
						}
						if(i < 113){
						positionX = 80 + contadorChaoPosition;
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
							positionX = 680 - contadorChaoPosition;
							positionY = 185 - floorRotation;
							rotation = 0.5f;
							floorRotation++;
							}
							else {
								if(i < 135){
								positionX = 680 - contadorChaoPosition;
								positionY = 185 - floorRotation;
								rotation = 0.f;
								}
								else {
									if(i == 135){
										contadorChaoPosition = 0;
										floorRotation = 0;
									}
									if(i < 139){
									positionX = 285 + contadorChaoPosition;
									positionY = 100;
									}
									else {
										if(i == 139){
											contadorChaoPosition = 0;
										}
										if(i < 141){
										positionX = 255 - contadorChaoPosition;
										positionY = 115;
										}
									}
								}
							}
						}
					}
				}
			}
		}

		plataforma[i].setSize(sf::Vector2f(30,15));
		plataforma[i].setPosition(positionX,positionY);
		plataforma[i].setRotation(rotation);

		contadorChaoPosition += 30;
	}

	contadorChaoPosition = 0;
}

int main(int argc, char **argv) {
	sf::RenderWindow window(sf::VideoMode(800,600), "Donkey Kong",
			sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	int NumPlataforma=0;

	sf::RectangleShape plataforma[141];

	createPlatforms(plataforma);

	sf::Texture platformTexture;

	if(!platformTexture.loadFromFile("assets/floorTexture.png")){
		return -1;
	}

	platformTexture.setSmooth(true);

	for(int i = 0; i < 141; i++){
		plataforma[i].setTexture(&platformTexture);
	}

	sf::Texture marioTexture;
	sf::Sprite marioSprite;

	int velMarioX = 0, velMarioY = 0;

	sf::Image icon = sf::Image { };
	if(!icon.loadFromFile("assets/iconPage.png")){
		return -1;
	}
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	if(!marioTexture.loadFromFile("assets/mario.png")){
		return -1;
	}
	marioSprite.setTexture(marioTexture);

	marioSprite.setOrigin(marioSprite.getLocalBounds().width/2., marioSprite.getLocalBounds().height/2.);
	marioSprite.setPosition(130,551);
	marioSprite.setScale(0.065, 0.065);

	while(window.isOpen()){
		sf::Event event;
		velMarioX = 0;
		velMarioY = 0;

		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				window.close();
			}
		}

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (marioSprite.getPosition().x >= marioSprite.getTexture()->getSize().x * marioSprite.getScale().x / 5)){
			velMarioX = -5;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (marioSprite.getPosition().x <= 800 - marioSprite.getTexture()->getSize().x * marioSprite.getScale().x / 4.1)){
			velMarioX = 5;
		}

		marioSprite.setPosition(marioSprite.getPosition().x + velMarioX, marioSprite.getPosition().y + velMarioY);

		window.clear(sf::Color::Black);
		window.draw(marioSprite);
		window.draw(marioSprite);
		/*while(NumPlataforma<8){
			window.draw(plataforma[NumPlataforma]);
			NumPlataforma++;
		};*/

		for(NumPlataforma = 0; NumPlataforma<141;NumPlataforma++){
			window.draw(plataforma[NumPlataforma]);
		};

		window.display();
		sf::sleep(sf::milliseconds(10.0f));
	}

	return 0;
}
