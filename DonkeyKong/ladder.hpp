/*
 * ladder.hpp
 *
 *  Created on: 1 de set. de 2024
 *      Author: Revii
 */

#ifndef LADDER_HPP_
#define LADDER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.hpp"

using namespace std;

class Ladder{
private:
	sf::RectangleShape ladder;
	sf::Texture texture;
	sf::Vector2f size;
public:
	Ladder(int i, sf::Vector2f size, int* contadorEscadaPosition, int* positionX, int* positionY){
		if(i < 3){
				*positionX = 710;
				*positionY = 510 + *contadorEscadaPosition;
				}
				else {
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

	void setTexture(sf::Texture* texture){
		this->texture = *texture;

		ladder.setTexture(&this->texture);
	}

	void draw(sf::RenderWindow &window){
		window.draw(ladder);
	}
};

#endif /* LADDER_HPP_ */
