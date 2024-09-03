/*
 * platforms.hpp
 *
 *  Created on: 28 de ago. de 2024
 *      Author: Revii
 */

#ifndef SOURCE_PLATFORMS_HPP_
#define SOURCE_PLATFORMS_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class Platforms{
private:
	sf::RectangleShape platform;
	sf::Texture platformTexture;
	sf::Vector2f size;

public:
	Platforms(int i, sf::Vector2f size, int* contadorChaoPosition, int* floorRotation, int* positionX, int* positionY, float* rotation);

	sf::RectangleShape getShape();

	void setTexture(sf::Texture texture);

	float getPositionX();

	float getPositionY();

	float getHeight();

	float getWidth();

	sf::Vector2f getSize();
};

#endif /* SOURCE_PLATFORMS_HPP_ */
