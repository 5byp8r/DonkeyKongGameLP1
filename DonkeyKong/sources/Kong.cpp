/*
 * Kong.cpp
 *
 *  Created on: 26 de set. de 2024
 *      Author: Daniel
 */

#include "../includes/Kong.hpp"

Kong::Kong() {
	if(!danceKong.loadFromFile("assets/kongDance.png")){
		isKongCreated = false;
	}
	if(!barrelKong.loadFromFile("assets/kongBarrel.png")){
		isKongCreated = false;
	}
	if(!happyKong.loadFromFile("assets/kongHappy.png")){
		isKongCreated = false;
	}
	if(!textureKong.loadFromFile("assets/kong.png")){
		isKongCreated = false;
	}
	spriteKong.setTexture(textureKong);

	spriteKong.setPosition(70, 79);
	spriteKong.setScale(0.1,0.1);
}
int Kong::randomAnimation(){
	int i;
		i=rand()%100;
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
	clock.restart();
	firstTexture = false;
	danceTexture = true;
	forceBarrel1 = true;
}

void Kong::danceAnimation2(){

	spriteKong.setScale(-0.1,0.1);
	spriteKong.setPosition(170, 79);
	clock.restart();
	danceTexture = false;
}

void Kong::barrelAnimation(){
	spriteKong.setTexture(barrelKong);
	spriteKong.setScale(-0.08,0.08);
	spriteKong.setPosition(175, 88);
	clock.restart();
	firstTexture = false;
	barrelTexture = true;
	forceBarrel1 = false;
	forceBarrel2 = false;
}

void Kong::happyAnimation(){
	spriteKong.setTexture(happyKong);
	clock.restart();
	firstTexture = false;
	forceBarrel2 = true;
}

void Kong::chooseAnimation(){
	int i = randomAnimation();
	int time = clock.getElapsedTime().asSeconds();

		if ((firstTexture == true) && (time > 0.2)) {
			//clock.restart();
			if(i>=75 && !forceBarrel1){
				danceAnimation1();
			}
			else if(i<=25 && !forceBarrel2){
				happyAnimation();
			}
			else{
				barrelAnimation();
			}
		}

		else if((danceTexture == true) && (time > 0.2)) {
			danceAnimation2();
		}

		else if(time > 0.2) {
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
