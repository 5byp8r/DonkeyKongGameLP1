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
	Ladder(){
		if(!texture.loadFromFile("assets/minecraftLadder.png")){
			return;
		}

		texture.setSmooth(true);

		this->size = sf::Vector2f(30,30);

		ladder.setTexture(&texture);
		ladder.setSize(this->size);

		ladder.setPosition(300, 580);
	}

	void draw(sf::RenderWindow &window){
		window.draw(ladder);
	}
};

#endif /* LADDER_HPP_ */
