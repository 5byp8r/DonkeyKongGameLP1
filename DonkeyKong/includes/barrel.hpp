/*
 * barrel.hpp
 *
 *  Created on: 27 de ago. de 2024
 *      Author: Davi Sollar
 */

#ifndef SOURCE_BARREL_HPP_
#define SOURCE_BARREL_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctgmath>
#include <vector>
#include <ctime>
#include "platforms.hpp"
#include "ladder.hpp"

using namespace std;

class Barrel{
private:
	sf::Texture textureBarrel;
	sf::Sprite barrelSprite;
	float velX = 0, velY = 0;
	bool baseBarrel = true;
	float positionX;
	float positionY;
public:
	int decision = 0;
	vector<int> decisionVector = {0,0,0,0,0};
	bool endTrack = false;
	bool isBarrelCreated = true;
	bool isColliding = false;
	bool canMove = true;
	bool isInLadder = false;
	bool goUp = false;
	bool goDown = false;
	bool goingUp = false;
	bool goingDown = false;
	bool isUpon = false;
	float gravity = 0.5;
	float lastPositionY = 0.0;

	vector<float> positionYLadders;
	int constVelX = 3;

	Barrel();

	~Barrel();

	int getVelX();

	int getVelY();

	float getPositionX();

	float getPositionY();

	sf::Texture getTexture();

	void setTexture(sf::Texture* texture);

	void setVelToZero();

	void setisColliding(bool isCollidingWithaPlatform);

	bool getisColliding();

	float getHeight();

	sf::Sprite getSprite();

	void randomDecises();

	void move();

	bool collisionTest(Platforms &platform);

	bool inLadder(Ladder &ladder);

	void draw(sf::RenderWindow &window);
};

#endif /* SOURCE_BARREL_HPP_ */
