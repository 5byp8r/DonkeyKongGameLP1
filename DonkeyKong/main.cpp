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

	sf::RectangleShape plataforma[7];
	plataforma[0].setSize(sf::Vector2f(680, 15));
	plataforma[0].setFillColor(sf::Color::Red);
	plataforma[0].setPosition(50,570);

	plataforma[1].setSize(sf::Vector2f(630, 15));
	plataforma[1].setFillColor(sf::Color::Cyan);
	plataforma[1].setPosition(50,470);
	plataforma[1].setRotation(2.f);

	plataforma[2].setSize(sf::Vector2f(630, 15));
	plataforma[2].setFillColor(sf::Color::Cyan);
	plataforma[2].setPosition(720,390);
	plataforma[2].setRotation(178.f);

	plataforma[3].setSize(sf::Vector2f(630, 15));
	plataforma[3].setFillColor(sf::Color::Cyan);
	plataforma[3].setPosition(50,290);
	plataforma[3].setRotation(2.f);

	plataforma[4].setSize(sf::Vector2f(630, 15));
	plataforma[4].setFillColor(sf::Color::Cyan);
	plataforma[4].setPosition(720,210);
	plataforma[4].setRotation(178.f);

	plataforma[5].setSize(sf::Vector2f(620, 15));
	plataforma[5].setFillColor(sf::Color::Red);
	plataforma[5].setPosition(50,130);

	plataforma[6].setSize(sf::Vector2f(90, 15));
	plataforma[6].setFillColor(sf::Color::White);
	plataforma[6].setPosition(180,60);

	sf::Texture marioTexture;
	sf::Sprite marioSprite;

	int velMarioX = 0, velMarioY = 0;

	sf::Image icon = sf::Image { };
	icon.loadFromFile("assets/iconPage.png");
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	marioTexture.loadFromFile("assets/mario.png");
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
		int NumPlataforma=0;
		while(NumPlataforma<7){
			window.draw(plataforma[NumPlataforma]);
			NumPlataforma++;
		};
		window.display();
		sf::sleep(sf::milliseconds(10.0f));
	}

	return 0;
}
