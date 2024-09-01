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
#include "player.hpp"

using namespace std;

class Platforms{
private:
	sf::RectangleShape platform;
	sf::Texture platformTexture;
	sf::Vector2f size;

public:
	Platforms(sf::Vector2f size, int positionX, int positionY, float rotation){
		platform.setSize(size);
		platform.setPosition(positionX,positionY);
		platform.setRotation(rotation);
		this->size = size;
		//cout << "plataforma: " << platform.getPosition().x << ";" << platform.getPosition().y << endl;
	}

	sf::RectangleShape getShape(){
		return platform;
	}

	void setTexture(sf::Texture texture){
		platformTexture = texture;

		platform.setTexture(&platformTexture);
	}

	float getPositionX(){
		return platform.getPosition().x;
	}

	float getPositionY(){
		return platform.getPosition().y;
	}

	float getHeight(){
		return platform.getLocalBounds().height;
	}

	float getWidth(){
		return platform.getLocalBounds().width;
	}

	sf::Vector2f getSize(){
		return size;
	}
};

#endif /* SOURCE_PLATFORMS_HPP_ */
