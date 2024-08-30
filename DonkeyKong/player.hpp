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
#include <ctgmath>
#include "platforms.hpp"

using namespace std;

class Player{
private:
	sf::Texture texturePlayer;
	sf::Sprite playerSprite;
	float velX = 0, velY = 0;
	float positionX;
	float positionY;
public:
	bool isPlayerCreated = true;
	bool isColliding = false;
	bool canMove = true;

	Player(){
		if(!texturePlayer.loadFromFile("assets/mario.png")){
			isPlayerCreated = false;
		}
		playerSprite.setTexture(texturePlayer);

		playerSprite.setOrigin(playerSprite.getLocalBounds().width/2., playerSprite.getLocalBounds().height/2.);
		playerSprite.setPosition(130,0);
		playerSprite.setScale(0.065, 0.065);
		this->positionX = 130;
		this->positionY = 551;
	}

	int getVelX(){
		return velX;
	}

	int getVelY(){
		return velY;
	}

	float getPositionX(){
		return playerSprite.getPosition().x;
	}

	float getPositionY(){
		return playerSprite.getPosition().y;
	}

	void setVelToZero(){
		velX = 0;
	}

	void setisColliding(bool isCollidingWithaPlatform){
		isColliding = isCollidingWithaPlatform;
	}

	bool getisColliding(){
		return isColliding;
	}

	float getHeight(){
		return playerSprite.getLocalBounds().height;
	}

	void move(){
		if(!isColliding){
			velY = 2;
			canMove = false;
		}else{
			velY = 0;
			canMove = true;
		}

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && (playerSprite.getPosition().x >= playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 5) && canMove == true){
			playerSprite.setScale(-0.065, 0.065);

			velX = -5;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && (playerSprite.getPosition().x <= 800 - playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 4.1) && canMove == true){
			playerSprite.setScale(0.065, 0.065);

			velX = 5;
		}

		playerSprite.setPosition(playerSprite.getPosition().x + velX, playerSprite.getPosition().y + velY);
		positionX = playerSprite.getPosition().x;
		positionY = playerSprite.getPosition().y;
	}

	bool collisionTest(Platforms &platform){
		bool collision;

		if(platform.getPositionX() > 400){
			if((getPositionX() - 12.3975 >= (platform.getPositionX())) && (getPositionX() - 12.3975 <= (platform.getPositionX() + platform.getSize().x))){
				if(getPositionY() + ((playerSprite.getLocalBounds().height * playerSprite.getScale().y)/2) >= platform.getPositionY()){
					collision = true;
					playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
				}
			}else{
				collision = false;
			}
		}else if(platform.getPositionX() < 400 && playerSprite.getScale().x > 0){
			if((getPositionX() + 13.3975 >= (platform.getPositionX())) && (getPositionX() - 12.3975 <= (platform.getPositionX() + platform.getSize().x))){
				if(getPositionY() + ((playerSprite.getLocalBounds().height * playerSprite.getScale().y)/2) >= platform.getPositionY()){
					collision = true;
					playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
				}
			}else{
				collision = false;
			}
		}else if(platform.getPositionX() < 400 && playerSprite.getScale().x < 0){
			if(platform.getPositionY() > 500){
				if((getPositionX() + 12.3975 >= (platform.getPositionX())) && (getPositionX() + 12.3975 <= (platform.getPositionX() + platform.getSize().x))){
					if(getPositionY() + ((playerSprite.getLocalBounds().height * playerSprite.getScale().y)/2) >= platform.getPositionY()){
						collision = true;
						playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
					}
				}else{
					collision = false;
				}
			}else if(platform.getPositionY() < 500){
				if((getPositionX() - 14.3975 >= (platform.getPositionX())) && (getPositionX() - 14.3975 <= (platform.getPositionX() + platform.getSize().x))){
					if(getPositionY() + ((playerSprite.getLocalBounds().height * playerSprite.getScale().y)/2) >= platform.getPositionY()){
						//playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
						collision = true;
					}
				}else{
					collision = false;
				}
			}
		}

		return collision;
	}

	void draw(sf::RenderWindow &window){
		window.draw(playerSprite);
	}

};

#endif /* SOURCE_PLAYER_HPP_ */
