/*
 * player.cpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#include "../includes/player.hpp"

Player::Player(){
	if(!texturePlayer.loadFromFile("assets/steve.png") || !jumpSound.setAudio("assets/jump.wav")){
		isPlayerCreated = false;
	}

	playerSprite.setTexture(texturePlayer);

	texturePlayer.setSmooth(true);

	playerSprite.setOrigin(playerSprite.getLocalBounds().width/2., playerSprite.getLocalBounds().height/2.);
	playerSprite.setPosition(200,560);
	playerSprite.setScale(0.065, 0.065);
	this->positionX = 200;
	this->positionY = 560;

	//cout << "player: " << playerSprite.getOrigin().x << endl;
}

int Player::getVelX(){
	return velX;
}

int Player::getVelY(){
	return velY;
}

float Player::getPositionX(){
	return playerSprite.getPosition().x;
}

float Player::getPositionY(){
	return playerSprite.getPosition().y;
}

void Player::setVelToZero(){
	velX = 0;
}

void Player::setisColliding(bool isCollidingWithaPlatform){
	isColliding = isCollidingWithaPlatform;
}

bool Player::getisColliding(){
	return isColliding;
}

bool Player::getisJumping(){
	return isJumping;
}

float Player::getHeight(){
	return playerSprite.getLocalBounds().height;
}

sf::Sprite Player::getSprite(){
	return playerSprite;
}

void Player::move(){
	if(!isColliding && !isJumping && !canGoUp && !canGoDown){
		velY+=gravity;
		if(canJump){
			canMove = false;
		}
		canJump = false;
	}else if(!isColliding && isJumping && !canGoUp && !canGoDown){
		velY = -2;
		canJump = false;
	}
	else if(isColliding && isJumping && !canGoUp && !canGoDown){
		velY = -2;
		canJump = false;
	}
	else{
		velY = 0;
		canMove = true;
		canJump = true;
	}

	if(isInLadder){
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && canMove == true){
			canGoUp = true;

			velY = -1;
		}

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && canMove == true){
			canGoDown = true;

			velY = 1;
		}
	}else{
		canGoUp = false;
		canGoDown = false;
	}

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && canMove == true /*&& (playerSprite.getPosition().x >= playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 5)*/){
		playerSprite.setScale(-0.065, 0.065);

		velX = -constVelX;
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && canMove == true /*&& (playerSprite.getPosition().x <= 800 - playerSprite.getTexture()->getSize().x * playerSprite.getScale().x / 4.1)*/){
		playerSprite.setScale(0.065, 0.065);

		velX = constVelX;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump == true && !isJumping){
		lastPositionY = getPositionY();

		if(canJump){
			jumpSound.play();
		}

		isJumping = true;
		constVelX = 4;
	}

	if(getPositionY() <= lastPositionY - 25){
		isJumping = false;
		constVelX = 6;
	}

	playerSprite.setPosition(playerSprite.getPosition().x + velX, playerSprite.getPosition().y + velY);
	positionX = playerSprite.getPosition().x;
	positionY = playerSprite.getPosition().y;
}

bool Player::collisionTest(Platforms &platform){
	bool collision;

	if(playerSprite.getGlobalBounds().intersects(platform.getShape().getGlobalBounds()) && velY > 0 && lastPositionY < platform.getPositionY()){
		if(!canGoUp && !canGoDown){
			playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
		}

		collision = true;

	}else{
		collision = false;
	}

	return collision;
}

bool Player::inLadder(Ladder &ladder){

	if((getPositionX() > ladder.getPositionX()) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x)) && (getPositionY() >= ladder.getPositionY() - 35) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))/*&& (getPositionY() >= ladder.getPositionY() + 30)*/){
		isInLadder = true;
	}
	else{
		isInLadder = false;
	}

	//0cout << isInLadder << endl;

	return isInLadder;
}

void Player::draw(sf::RenderWindow &window){
	window.draw(playerSprite);
}
