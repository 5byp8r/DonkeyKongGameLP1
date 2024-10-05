/*
 * barrel.cpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Davi Sollar
 */

#include "../includes/barrel.hpp"

Barrel::Barrel(){
	if(!textureBarrel.loadFromFile("assets/barrel.png")){
		isBarrelCreated = false;
	}

	barrelSprite.setTexture(textureBarrel);

	textureBarrel.setSmooth(true);

	barrelSprite.setOrigin(barrelSprite.getLocalBounds().width/2., barrelSprite.getLocalBounds().height/2.);
	barrelSprite.setPosition(170,154);
	barrelSprite.setScale(0.13, 0.13);
	this->positionX = 170;
	this->positionY = 154;
	for (int i = 0; i < 6; i++){
		positionYLadders.push_back(0);
	}
}


Barrel::~Barrel(){}

int Barrel::getVelX(){
	return velX;
}

int Barrel::getVelY(){
	return velY;
}

float Barrel::getPositionX(){
	return barrelSprite.getPosition().x;
}

float Barrel::getPositionY(){
	return barrelSprite.getPosition().y;
}

sf::Texture Barrel::getTexture(){
	return textureBarrel;
}

void Barrel::setTexture(sf::Texture* texture){
	textureBarrel = *texture;

	barrelSprite.setTexture(*texture);
}

void Barrel::setVelToZero(){
	velX = 0;
}

void Barrel::setisColliding(bool isCollidingWithaPlatform){
	isColliding = isCollidingWithaPlatform;
}

bool Barrel::getisColliding(){
	return isColliding;
}


float Barrel::getHeight(){
	return barrelSprite.getLocalBounds().height;
}

sf::Sprite Barrel::getSprite(){
	return barrelSprite;
}

void Barrel::randomDecises(){
	decision = rand() % 69;
}

void Barrel::move(){
	if(!isColliding && !goUp && !goDown){
		velY+=gravity;

	}
	else{
		velY = 0;
		canMove = true;
	}

	if(isUpon){
		goingUp = false;
		goUp = false;
		canMove = true;
		isColliding = true;
	}

	if(getPositionY()< (154 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionY()>= (134 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)  && getPositionX() < 695 && canMove == true && !goingUp && !goingDown){
		velX = constVelX;
		endTrack = false;
		decisionVector[0] = 0;
	}
	else{
		randomDecises();
		if((decision%2 == 0 || decisionVector[0] == 1) && decisionVector[0] != 3 && decisionVector[0] != 2){
			if(getPositionY() <= (219 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
			velX = 0;
			goDown = true;
			goUp = false;
			goingUp = false;
			goingDown = true;
			decisionVector[0] = 1;
			velY = 1;
			}
			else{
				canMove = true;
				goDown = false;
				goingDown = false;
				velY = 0;
				decisionVector[0] = 3;
			}
		}
		else if (decisionVector[0] == 2 || decisionVector[0] != 3){
			if (getPositionX() < 740){
				velX = constVelX;
				decisionVector[0] = 2;
			}
			else if (getPositionY() <= (217 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
				velX = 0;
			}
			else{
				decisionVector[0] = 3;
			}
		}
		else{
			if(getPositionY()< (247 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionY()> (217 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionX() > 116 && canMove == true && !goingUp && !goingDown){
					velX = -constVelX;
					decisionVector[1] = 0;
				}
				else{
					randomDecises();
					if((decision%2 == 0 || decisionVector[1] == 1) && decisionVector[1] != 3 && decisionVector[1] != 2){
						if(getPositionY() <= (300 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
						velX = 0;
						goDown = true;
						goUp = false;
						goingUp = false;
						goingDown = true;
						decisionVector[1] = 1;
						velY = 1;
						}
						else{
							canMove = true;
							goDown = false;
							goingDown = false;
							velY = 0;
							decisionVector[1] = 3;
						}
					}
					else if (decisionVector[1] == 2 || decisionVector[1] != 3){
						if (getPositionX() > 75){
							velX = -constVelX;
							decisionVector[1] = 2;
						}
						else if (getPositionY() <= (293 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
							velX = 0;
						}
						else{
							decisionVector[1] = 3;
						}
					}
					else{
						if(getPositionY()< (334 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionY()> (295 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)  && getPositionX() < 695 && canMove == true && !goingUp && !goingDown){
								velX = constVelX;
								decisionVector[2] = 0;
							}
							else{
								randomDecises();
								if((decision%2 == 0 || decisionVector[2] == 1) && decisionVector[2] != 3 && decisionVector[2] != 2){
									if(getPositionY() <= (380 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
									velX = 0;
									goDown = true;
									goUp = false;
									goingUp = false;
									goingDown = true;
									decisionVector[2] = 1;
									velY = 1;
									}
									else{
										canMove = true;
										goDown = false;
										goingDown = false;
										velY = 0;
										decisionVector[2] = 3;
									}
								}
								else if (decisionVector[2] == 2 || decisionVector[2] != 3){
									if (getPositionX() < 740){
										velX = constVelX;
										decisionVector[2] = 2;
									}
									else if (getPositionY() <= (360 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
										velX = 0;
									}
									else{
										decisionVector[2] = 3;
									}
								}
								else{
									if(getPositionY()< (405 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionY()> (360 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)  && getPositionX() > 126 && canMove == true && !goingUp && !goingDown){
											velX = -constVelX;
											decisionVector[3] = 0;
										}
										else{
											randomDecises();
											if((decision%2 == 0 || decisionVector[3] == 1) && decisionVector[3] != 3 && decisionVector[3] != 2){
												if(getPositionY() <= (462 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
												velX = 0;
												goDown = true;
												goUp = false;
												goingUp = false;
												goingDown = true;
												decisionVector[3] = 1;
												velY = 1;
												}
												else{
													canMove = true;
													goDown = false;
													goingDown = false;
													velY = 0;
													decisionVector[3] = 3;
												}
											}
											else if (decisionVector[3] == 2 || decisionVector[3] != 3){
												if (getPositionX() > 75){
													velX = -constVelX;
													decisionVector[3] = 2;
												}
												else if (getPositionY() <= (450 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
													velX = 0;
												}
												else{
													decisionVector[3] = 3;
												}
											}
											else{
												if(getPositionY()< (490 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionY()> (450 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)  && getPositionX() < 725 && canMove == true && !goingUp && !goingDown){
													velX = constVelX;
													decisionVector[4] = 0;
													}
													else{
														randomDecises();
														if((decision%2 == 0 || decisionVector[4] == 1) && decisionVector[4] != 3 && decisionVector[4] != 2){
															if(getPositionY() <= (545 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
																velX = 0;
																goDown = true;
																goUp = false;
																goingUp = false;
																goingDown = true;
																decisionVector[4] = 1;
																velY = 1;
															}
															else{
																canMove = true;
																goDown = false;
																goingDown = false;
																velY = 0;
																decisionVector[4] = 3;
															}
														}
														else if (decisionVector[4] == 2 || decisionVector[4] != 3){
															if (getPositionX() < 770){
																velX = constVelX;
																decisionVector[4] = 2;
															}
															else if (getPositionY() <= (539 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2)){
																velX = 0;
															}
															else{
																decisionVector[4] = 3;
															}
														}
														else{
															if(getPositionY() > (539 + barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2) && getPositionX() > 21 && canMove == true && !goingUp && !goingDown){
																velX = -constVelX;
															}
															else if(getPositionY() < 620){
																velX = 0;
															}
															else{
																//barrelSprite.setPosition(200, 154);
																//endTrack = true;
															}
														}
													}
											}
										}
								}
							}
					}
				}
			}
		}

	if(getPositionY() <= lastPositionY - 25){
		constVelX = 5;
	}

	if(!endTrack){
		barrelSprite.setPosition(barrelSprite.getPosition().x + velX, barrelSprite.getPosition().y + velY);
	}

	positionX = barrelSprite.getPosition().x;
	positionY = barrelSprite.getPosition().y;

	//cout << goUp << "," << goDown << "," << goingUp << "," << goingDown << "," << canMove << "," << isColliding << "," << isInLadder << "," << isUpon << ", velY:" << velY << ", constVelX:" << constVelX << ",velX:" << velX  << "," << lastPositionY << endl;
}

bool Barrel::collisionTest(Platforms &platform){
	bool collision;

	if(barrelSprite.getGlobalBounds().intersects(platform.getShape().getGlobalBounds()) && velY > 0 && lastPositionY < platform.getPositionY()){
		if((!goUp && !goDown)){
			barrelSprite.setPosition(getPositionX(), (platform.getPositionY() - barrelSprite.getLocalBounds().height * barrelSprite.getScale().y/2));
		}

		lastPositionY = 0;
		collision = true;

	}else{
		collision = false;
	}

	return collision;
}

bool Barrel::inLadder(Ladder &ladder){
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
			positionYLadders[0] = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
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
			positionYLadders[1] = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y - 1;
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
			positionYLadders[2] = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
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
			positionYLadders[3] = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y - 1;
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
			positionYLadders[4] = ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y;
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
			positionYLadders[5] = (ladder.getPositionY() + ladder.getShape().getLocalBounds().height * ladder.getShape().getScale().y) - 10;
		}
	}

	//cout << isInLadder << endl;

	return isInLadder;
}

void Barrel::draw(sf::RenderWindow &window){
	window.draw(barrelSprite);
}
