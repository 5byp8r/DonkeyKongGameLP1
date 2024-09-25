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
#include "ladder.hpp"
#include "sounds.hpp"

using namespace std;

class Player{
private:
	sf::Texture texturePlayer;
	sf::Sprite playerSprite;
	Sounds jumpSound;
	float velX = 0, velY = 0;
	float positionX;
	float positionY;
public:
	bool isPlayerCreated = true;
	bool isColliding = false;
	bool canMove = true;
	bool isJumping = false;
	bool canJump = true;
	bool spaceWasPressed = false;
	bool isInLadder = false;
	bool canGoUp = false;
	bool canGoDown = false;
	float gravity = 0.5;
	float lastPositionY = 0.0;
	int constVelX = 8;

	Player();

	int getVelX();

	int getVelY();

	float getPositionX();

	float getPositionY();

	void setVelToZero();

	void setisColliding(bool isCollidingWithaPlatform);

	bool getisColliding();

	bool getisJumping();

	float getHeight();

	sf::Sprite getSprite();

	void move();

	bool collisionTest(Platforms &platform);

	bool inLadder(Ladder &ladder);

	void draw(sf::RenderWindow &window);
};

#endif /* SOURCE_PLAYER_HPP_ */
