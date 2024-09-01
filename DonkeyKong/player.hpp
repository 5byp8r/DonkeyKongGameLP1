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
	bool isJumping = false;
	bool spaceWasPressed = false;
	float gravity = 0.5;
	float lastPositionY = 0.0;
	int constVelX = 6;

	Player(){
		if(!texturePlayer.loadFromFile("assets/steve.png")){
			isPlayerCreated = false;
		}
		playerSprite.setTexture(texturePlayer);

		texturePlayer.setSmooth(true);

		playerSprite.setOrigin(playerSprite.getLocalBounds().width/2., playerSprite.getLocalBounds().height/2.);
		playerSprite.setPosition(71,580);
		playerSprite.setScale(0.065, 0.065);
		this->positionX = 130;
		this->positionY = 551;

		//cout << "player: " << playerSprite.getOrigin().x << endl;
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

	sf::Sprite getSprite(){
		return playerSprite;
	}

	void move(){
		if(!isColliding && !isJumping){
			velY += gravity;
			canMove = false;
		}else if(!isColliding && isJumping){
			velY = -2;
			canMove = true;
		}
		else{
			velY = 0;
			canMove = true;
		}

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && canMove == true /*&& (playerSprite.getPosition().x >= playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 5)*/){
			playerSprite.setScale(-0.065, 0.065);

			velX = -constVelX;
		}
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && canMove == true /*&& (playerSprite.getPosition().x <= 800 - playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 4.1)*/){
			playerSprite.setScale(0.065, 0.065);

			velX = constVelX;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canMove == true && !isJumping){
			lastPositionY = getPositionY();

			//velY = -2;
			//gravity = 0;

			isJumping = true;
			constVelX = 4;
		}

		if(getPositionY() == lastPositionY - 30){
			//gravity = 0.5;
			isJumping = false;
			constVelX = 6;
		}

		playerSprite.setPosition(playerSprite.getPosition().x + velX, playerSprite.getPosition().y + velY);
		positionX = playerSprite.getPosition().x;
		positionY = playerSprite.getPosition().y;
	}

	bool collisionTest(Platforms &platform){
		bool collision;

		/*if(platform.getPositionX() >= 400){
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
						cout << getPositionX() << "," << getPositionY() << "," << playerSprite.getLocalBounds().height * playerSprite.getScale().y/2 << endl;
					}
				}else{
					collision = false;
				}
			}else if(platform.getPositionY() <= 180){
				if((getPositionX() + 14.3975 >= (platform.getPositionX())) && (getPositionX() - 14.3975 <= (platform.getPositionX() + platform.getSize().x))){
					if(getPositionY() + ((playerSprite.getLocalBounds().height * playerSprite.getScale().y)/2) >= platform.getPositionY()){
						//playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
						collision = true;
					}
				}else{
					collision = false;
				}
			}
		}*/

		if(playerSprite.getGlobalBounds().intersects(platform.getShape().getGlobalBounds()) && velY > 0 && lastPositionY < platform.getPositionY()){
			playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
			collision = true;

		}else{
			collision = false;
		}

		return collision;
	}

	void draw(sf::RenderWindow &window){
		window.draw(playerSprite);
	}

};

#endif /* SOURCE_PLAYER_HPP_ */
