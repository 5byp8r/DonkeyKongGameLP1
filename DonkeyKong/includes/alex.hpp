/*
 * alex.hpp
 *
 *  Created on: 7 de out. de 2024
 *      Author: Revii
 */

#ifndef SOURCE_INCLUDES_ALEX_HPP_
#define SOURCE_INCLUDES_ALEX_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>

class Alex{
private:
	sf::Texture textureAlex;
	sf::Sprite spriteAlex;
public:
	bool isAlexCreated = true;

	Alex();

	void draw(sf::RenderWindow &window);
};

#endif /* SOURCE_INCLUDES_ALEX_HPP_ */
