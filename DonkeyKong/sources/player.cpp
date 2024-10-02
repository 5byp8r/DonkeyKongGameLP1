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

	positionYLadder1 = 0;
	positionYLadder2 = 0;
	positionYLadder3 = 0;
	positionYLadder4 = 0;
	positionYLadder5 = 0;
	positionYLadder6 = 0;
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
	if(!isColliding && !isJumping && !goUp && !goDown){
		velY+=gravity;
		if(canJump){
			canMove = false;
		}
		canJump = false;
	}else if(!isColliding && isJumping && !goUp && !goDown){
		velY = -2;
		canJump = false;
	}
	else if(isColliding && isJumping && !goUp && !goDown){
		velY = -2;
		canJump = false;
	}
	else{
		velY = 0;
		canMove = true;
		canJump = true;
	}

	if(isInLadder){
		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && canMove == true && !isUpon){
			goUp = true;
			goDown = false;
			goingUp = true;
			goingDown = false;
			velY = -1;
		}

		if((sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && canMove == true){
			goDown = true;
			goUp = false;
			goingUp = false;
			goingDown = true;

			if((getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder1 || (getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder2 || (getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder3 || (getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder4 || (getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder5 || (getPositionY() + playerSprite.getLocalBounds().height * playerSprite.getScale().y/2) == positionYLadder6)
			{
				velY = 0;

				canMove = true;
				goDown = false;
				goingDown = false;
			}else{
				velY = 1;
			}
		}
	}else{
		goUp = false;
		goDown = false;
		goingUp = false;
		goingDown = false;
	}

	if(isUpon){
		goingUp = false;
		goUp = false;
		canMove = true;
		isColliding = true;
	}

	if(goUp || goDown)
	{
		canJump = false;
	}

	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) && canMove == true && !goingUp && !goingDown){
		playerSprite.setScale(-0.065, 0.065);

		velX = -constVelX;
	}
	if((sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && canMove == true && !goingUp && !goingDown){
		playerSprite.setScale(0.065, 0.065);

		velX = constVelX;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump == true && !isJumping){
		lastPositionY = getPositionY();

		jumpSound.play();

		isJumping = true;
		constVelX = 4;
	}

	if(getPositionY() <= lastPositionY - 25){
		isJumping = false;
		constVelX = 8;
	}

	playerSprite.setPosition(playerSprite.getPosition().x + velX, playerSprite.getPosition().y + velY);
	positionX = playerSprite.getPosition().x;
	positionY = playerSprite.getPosition().y;

	//cout << goUp << "," << goDown << "," << goingUp << "," << goingDown << "," << canMove << "," << canJump << "," << isJumping << "," << isColliding << "," << isInLadder << "," << isUpon << ", velY:" << velY << ", constVelX:" << constVelX << ",velX:" << velX  << "," << lastPositionY << endl;
}

bool Player::collisionTest(Platforms &platform){
	bool collision;

	if(playerSprite.getGlobalBounds().intersects(platform.getShape().getGlobalBounds()) && velY > 0 && lastPositionY < platform.getPositionY()){
		if((!goUp && !goDown)){
			playerSprite.setPosition(getPositionX(), (platform.getPositionY() - playerSprite.getLocalBounds().height * playerSprite.getScale().y/2));
		}

		lastPositionY = 0;
		collision = true;

	}else{
		collision = false;
	}

	return collision;
}

bool Player::inLadder(Ladder &ladder){
	if(ladder.getPositionY() > 503){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 30) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 28){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 536){
			positionYLadder1 = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
		}
	}else if(ladder.getPositionY() > 418 && ladder.getPositionY() < 500){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 23) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 21){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 449 && ladder.getPositionY() < 536){
			positionYLadder2 = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y - 1;
		}
	}else if(ladder.getPositionY() > 340 && ladder.getPositionY() < 418){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 23) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 19.3){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 369 && ladder.getPositionY() < 449){
			positionYLadder3 = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
		}
	}else if(ladder.getPositionY() > 257 && ladder.getPositionY() < 340){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 23) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 21){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 288 && ladder.getPositionY() < 369){
			positionYLadder4 = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y - 1;
		}
	}else if(ladder.getPositionY() > 173 && ladder.getPositionY() < 257){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 27) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 25){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 205 && ladder.getPositionY() < 250){
			positionYLadder5 = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
		}
	}else if(ladder.getPositionY() > 83 && ladder.getPositionY() < 165){
		if((getPositionX() > (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x / 5))) && getPositionX() < (ladder.getPositionX() + (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x) - (ladder.getShape().getLocalBounds().width * ladder.getShape().getScale().x/5)) && (getPositionY() >= ladder.getPositionY() - 27) && (getPositionY() <= (ladder.getPositionY() + (ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y)))){
			isInLadder = true;
		}
		else{
			isInLadder = false;
		}

		if(getPositionY() < ladder.getPositionY() - 18.5){
			isUpon = true;
		}else{
			isUpon = false;
		}

		if(ladder.getPositionY() > 135 && ladder.getPositionY() < 162){
			positionYLadder6 = (ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y) - 10;
		}
	}

	//cout << isInLadder << endl;

	return isInLadder;
}

void Player::draw(sf::RenderWindow &window){
	window.draw(playerSprite);
}
