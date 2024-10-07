/*
 * Kong.hpp
 *
 *  Created on: 26 de set. de 2024
 *      Author: Daniel
 */

#ifndef KONG_HPP_
#define KONG_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

class Kong {
private:
	sf::Texture textureKong;
	sf::Texture barrelKong;
	sf::Texture danceKong;
	sf::Texture happyKong;
	sf::Sprite spriteKong;
public:
	bool isKongCreated = true;
	bool firstTexture = true;
	bool danceTexture = false;
	bool barrelTexture = false;
	bool forceBarrel1 = true;
	bool forceBarrel2 = true;
	sf::Clock clock;

	Kong();

	int randomAnimation();

	void firstSprite();

	void danceAnimation1();

	void danceAnimation2();

	void barrelAnimation();

	void happyAnimation();

	void chooseAnimation();

	void draw(sf::RenderWindow &window);

	sf::Sprite getSprite();
};

#endif /* KONG_HPP_ */
