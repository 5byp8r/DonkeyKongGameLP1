/*
 * alex.cpp
 *
 *  Created on: 7 de out. de 2024
 *      Author: Revii
 */

#include "../includes/alex.hpp"

Alex::Alex()
{
	if(!textureAlex.loadFromFile("assets/Alex.png"))
	{
		isAlexCreated = false;
	}

	spriteAlex.setTexture(textureAlex);

	spriteAlex.setPosition(250, 49);
	spriteAlex.setScale(0.06,0.06);
}

void Alex::draw(sf::RenderWindow &window)
{
	window.draw(spriteAlex);
}
