/*
 * player.hpp
 *
 *  Created on: 27 de ago. de 2024
 *      Author: Revii
 */

#ifndef SOURCE_PLAYER_HPP_
#define SOURCE_PLAYER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Player{
private:
	sf::Texture texturePlayer;
	sf::Sprite playerSprite;
	int velX = 0, velY = 0;
public:
	bool isPlayerCreated = true;

	Player(){
		if(!texturePlayer.loadFromFile("assets/mario.png")){
			isPlayerCreated = false;
		}
		playerSprite.setTexture(texturePlayer);

		playerSprite.setOrigin(playerSprite.getLocalBounds().width/2., playerSprite.getLocalBounds().height/2.);
		playerSprite.setPosition(130,551);
		playerSprite.setScale(0.065, 0.065);
	}

	int getVelX(){
		return velX;
	}

	int getVelY(){
		return velY;
	}

	void setVelToZero(){
		velX = velY = 0;
	}

	void move(){
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (playerSprite.getPosition().x >= playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 5)){
			velX = -5;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (playerSprite.getPosition().x <= 800 - playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 4.1)){
			velX = 5;
		}

		playerSprite.setPosition(playerSprite.getPosition().x + velX, playerSprite.getPosition().y + velY);
	}

	void draw(sf::RenderWindow &window){
		window.draw(playerSprite);
	}

};

#endif /* SOURCE_PLAYER_HPP_ */
