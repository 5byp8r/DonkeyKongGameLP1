/*
 * ladder.cpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#include "../includes/ladder.hpp"

Ladder::Ladder(int i, sf::Vector2f size, int* contadorEscadaPosition, int* positionX, int* positionY){
	if(i < 3){
		*positionX = 710;
		*positionY = 510 + *contadorEscadaPosition;
	}
	else{
		if(i == 3){
			*contadorEscadaPosition = 0;
		}
		if(i < 5){
			*positionX = 110;
			*positionY = 422 + *contadorEscadaPosition;
		}
		else {
			if(i == 5){
				*contadorEscadaPosition = 0;
			}
			if(i < 7){
				*positionX = 681;
				*positionY = 341 + *contadorEscadaPosition;
			}
			else {
				if(i == 7){
					*contadorEscadaPosition = 0;
				}
				if(i < 9){
					*positionX = 101;
					*positionY = 262 + *contadorEscadaPosition;
				}
				else {
					if(i == 9){
						*contadorEscadaPosition = 0;
					}
					if(i < 11){
						*positionX = 681;
						*positionY = 180 + *contadorEscadaPosition;
					}
					else {
						if(i == 11){
							*contadorEscadaPosition = 0;
						}
						if(i < 14){
							*positionX = 386;
							*positionY = 85 + *contadorEscadaPosition;
						}
					}
				}
			}
		}
	}
	*contadorEscadaPosition += 30;
	ladder.setSize(size);
	ladder.setPosition(*positionX,*positionY);
	this->size = size;
}

void Ladder::setTexture(sf::Texture* texture){
	this->texture = *texture;

	ladder.setTexture(&this->texture);
}

sf::RectangleShape Ladder::getShape(){
	return ladder;
}

float Ladder::getPositionY(){
	return ladder.getPosition().y;
}

float Ladder::getPositionX(){
	return ladder.getPosition().x;
}

void Ladder::draw(sf::RenderWindow &window){
	window.draw(ladder);
}
