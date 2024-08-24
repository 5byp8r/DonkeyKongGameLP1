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

int main(int argc, char **argv) {
	sf::RenderWindow window(sf::VideoMode(800,600), "Donkey Kong");
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	sf::Texture marioTexture;
	sf::Sprite marioSprite;

	int velMarioX = 0, velMarioY = 0;

	sf::Image icon = sf::Image { };
	icon.loadFromFile("assets/iconPage.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	marioTexture.loadFromFile("assets/mario.png");
	marioSprite.setTexture(marioTexture);

	marioSprite.setOrigin(marioSprite.getLocalBounds().width/2., marioSprite.getLocalBounds().height/2.);
	marioSprite.setPosition(400,300);
	marioSprite.setScale(0.07, 0.07);

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
		window.display();
		sf::sleep(sf::milliseconds(10.0f));
	}

	return 0;
}
