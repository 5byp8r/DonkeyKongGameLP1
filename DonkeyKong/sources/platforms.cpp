/*
 * platforms.cpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#include "../includes/platforms.hpp"

Platforms::Platforms(int i, sf::Vector2f size, int* contadorChaoPosition, int* floorRotation, int* positionX, int* positionY, float* rotation){
	if(i < 24){
		*positionX = 41 + *contadorChaoPosition;
		*positionY = 570;
		}
		else {
			if(i == 24){
				*contadorChaoPosition = 0;
			}
			if(i < 47){
				*positionX = 61 + *contadorChaoPosition;
				*positionY = 480 + *floorRotation;
				*rotation = 2.f;
				*floorRotation = *floorRotation + 1;
			}
			else {
				if(i == 47){
					*contadorChaoPosition = 0;
					*floorRotation = 0;
				}
				if(i < 69){
					*positionX = 91 + *contadorChaoPosition;
					*positionY = 420 - *floorRotation;
					*rotation = -1.f;
					*floorRotation = *floorRotation + 1;
				}
				else {
					if(i == 69){
						*contadorChaoPosition = 0;
						*floorRotation = 0;
					}
					if(i < 91){
						*positionX = 61 + *contadorChaoPosition;
						*positionY = 320 + *floorRotation;
						*rotation = 3.f;
						*floorRotation = *floorRotation + 1;
					}
					else {
						if(i == 91){
							*contadorChaoPosition = 0;
							*floorRotation = 0;
						}
						if(i < 113){
						*positionX = 91 + *contadorChaoPosition;
						*positionY = 260 - *floorRotation;
						*rotation = -1.f;
						*floorRotation = *floorRotation + 1;
						}
						else {
							if(i == 113){
								*contadorChaoPosition = 0;
								*floorRotation = 0;
							}
							if(i < 123){
							*positionX = 691 - *contadorChaoPosition;
							*positionY = 175 - *floorRotation;
							*rotation = 0.5f;
							*floorRotation = *floorRotation + 1;
							}
							else {
								if(i < 135){
								*positionX = 691 - *contadorChaoPosition;
								*positionY = 175 - *floorRotation;
									*rotation = 0.f;
								}
								else {
									if(i == 135){
										*contadorChaoPosition = 0;
										*floorRotation = 0;
									}
									if(i < 139){
									*positionX = 296 + *contadorChaoPosition;
									*positionY = 85;
									}
									else {
										if(i == 139){
											*contadorChaoPosition = 0;
										}
										if(i < 141){
										*positionX = 266 - *contadorChaoPosition;
										*positionY = 100;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	*contadorChaoPosition += 30;
	platform.setSize(size);
	platform.setPosition(*positionX,*positionY);
	platform.setRotation(*rotation);
	this->size = size;
	//cout << "plataforma " << i << ": " << platform.getPosition().x << ", " << platform.getPosition().y << endl;
}

sf::RectangleShape Platforms::getShape(){
	return platform;
}

void Platforms::setTexture(sf::Texture texture){
	platformTexture = texture;

	platform.setTexture(&platformTexture);
}

float Platforms::getPositionX(){
	return platform.getPosition().x;
}

float Platforms::getPositionY(){
	return platform.getPosition().y;
}

float Platforms::getHeight(){
	return platform.getLocalBounds().height;
}

float Platforms::getWidth(){
	return platform.getLocalBounds().width;
}

sf::Vector2f Platforms::getSize(){
	return size;
}
