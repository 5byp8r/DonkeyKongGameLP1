/*
 * Kong.cpp
 *
 *  Created on: 26 de set. de 2024
 *      Author: Daniel
 */

#include "../includes/Kong.hpp"

Kong::Kong() {
	if(!danceKong.loadFromFile("assets/kongDance.png")){
	}
	if(!happyKong.loadFromFile("assets/kongHappy.png")){
	}
	if(!textureKong.loadFromFile("assets/kong.png")){
	}
	spriteKong.setTexture(textureKong);

	spriteKong.setPosition(70, 79);
	spriteKong.setScale(0.1,0.1);
}
int Kong::randomAnimation(){
	srand(time(0));
	int i;
		i=rand()%2;

	return i;
}

void Kong::firstSprite(){
	spriteKong.setTexture(textureKong);
	spriteKong.setScale(0.1,0.1);
	spriteKong.setPosition(70, 79);
	firstTexture = true;
	clock.restart();
}

void Kong::danceAnimation1(){

	spriteKong.setTexture(danceKong);
	firstTexture = false;
	danceTexture = true;

}

void Kong::danceAnimation2(){

	spriteKong.setScale(-0.1,0.1);
	spriteKong.setPosition(170, 79);
	danceTexture = false;

}

void Kong::happyAnimation(){

	spriteKong.setTexture(happyKong);
	firstTexture = false;

}

void Kong::chooseAnimation(){
	int i = randomAnimation();
	int time = clock.getElapsedTime().asSeconds();

		if ((firstTexture == true) && (time > 3.0)){
			//clock.restart();
			if(i==0){
				danceAnimation1();
			}
			else if(i==1){
				happyAnimation();
			}
		}

		else if((danceTexture == true) && (time > 4.0)) {
			danceAnimation2();
		}

		else if(time > 5.0) {
			firstSprite();
		}
	//}
}
void Kong::draw(sf::RenderWindow &window){
	window.draw(spriteKong);
}

sf::Sprite Kong::getSprite(){
	return spriteKong;
}
