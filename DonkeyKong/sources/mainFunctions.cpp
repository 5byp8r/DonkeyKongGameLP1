/*
 * mainFuncions.cpp
 *
 *  Created on: 2 de set. de 2024
 *      Author: Revii
 */

#include "../includes/mainFunctions.hpp"

vector<Platforms> createPlatforms(){
	vector<Platforms> platforms;
	vector<Platforms> empty;

	sf::Texture platformTexture;
	int contadorChaoPosition = 0;
	int floorRotation = 0;
	int positionXPlatform = 0;
	int positionYPLatform = 0;
	float rotation = 0.f;

	for(int i = 0; i < 141; i++){
		Platforms platform(i, sf::Vector2f(30,15), &contadorChaoPosition, &floorRotation, &positionXPlatform, &positionYPLatform, &rotation);
		platforms.push_back(platform);
	}

	if(!platformTexture.loadFromFile("assets/floorMinecraft.png")){
		return empty;
	}

	for(size_t i = 0; i < platforms.size(); i++){
		platforms.at(i).setTexture(platformTexture);
	}

	platformTexture.setSmooth(true);

	return platforms;
}

string setIcon(sf::RenderWindow &window){
	sf::Image icon = sf::Image { };

	if(!icon.loadFromFile("assets/iconPage.png")){
		return "error";
	}

	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	return "truth";
}

vector<Ladder> createLadders(){
	vector<Ladder> ladders;
	vector<Ladder> empty;

	size_t numEscada = 0;
	sf::Texture ladderTexture;
	int contadorEscadaPosition = 0;
	int positionXLadder = 0;
	int positionYLadder = 0;

	for(int i = 1; i < 14; i++){
		Ladder ladder(i, sf::Vector2f(30,30), &contadorEscadaPosition, &positionXLadder, &positionYLadder);
		ladders.push_back(ladder);
	}

	if(!ladderTexture.loadFromFile("assets/minecraftLadder.png")){
		return empty;
	}

	for(numEscada = 0; numEscada < ladders.size(); numEscada++){
		ladders.at(numEscada).setTexture(&ladderTexture);
	}

	ladderTexture.setSmooth(true);

	return ladders;
}

void checkPlayerStatus(Player *player, bool *collisionChecker, sf::RenderWindow &window, size_t numPlataforma, vector<Platforms> *platforms, Musics *music){
	if(player->getPositionY() > 600 + player->getSprite().getLocalBounds().height * player->getSprite().getScale().y){
		music->play();
		window.close();
	}

	player->move();

	player->setisColliding(*collisionChecker);

	for(numPlataforma = 0; numPlataforma < platforms->size(); numPlataforma++){
		if(player->collisionTest(platforms->at(numPlataforma))){
			*collisionChecker = true;
			break;
		}
	}

	player->setisColliding(*collisionChecker);
}

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player){
	window.clear(sf::Color::Black);

	window.draw(fundoImage);

	for(numEscada = 0; numEscada < ladders->size(); numEscada++){
		ladders->at(numEscada).draw(window);
	};

	for(numPlataforma = 0; numPlataforma<platforms->size();numPlataforma++){
		window.draw(platforms->at(numPlataforma).getShape());
	};

	player->draw(window);

	window.display();
}
