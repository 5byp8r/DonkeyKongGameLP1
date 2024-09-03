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
	Ladder(int i, sf::Vector2f size, int* contadorEscadaPosition, int* positionX, int* positionY);

	void setTexture(sf::Texture* texture);

	void draw(sf::RenderWindow &window);
};

#endif /* LADDER_HPP_ */
