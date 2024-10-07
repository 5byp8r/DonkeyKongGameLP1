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

bool testCreation(sf::RenderWindow &window, sf::Texture *textureFundo, sf::Sprite *fundoImage, sf::Texture *textureBarrel, sf::Font *font, Musics *backgroundMusic, vector<Platforms> *platforms, vector<Ladder> *ladders, vector<Barrel> *barrels, Player *player, Kong *kong){
	if(!textureFundo->loadFromFile("assets/backgroundNight.png")){
		return false;
	}

	fundoImage->setTexture(*textureFundo);

	if(!textureBarrel->loadFromFile("assets/barrel.png")){
		return false;
	}

	textureBarrel->setSmooth(true);

	if(!font->loadFromFile("assets/font.ttc")){
		return false;
	}

	if(!backgroundMusic->setAudio("assets/music.ogg")){
		cout << "Impossível criar o som" << endl;

		return false;
	}

	backgroundMusic->play();

	if(platforms->empty()){
		cout << "Impossível criar plataformas" << endl;

		return false;
	}

	if(setIcon(window) == "error"){
		cout << "Impossível criar o ícone" << endl;

		return false;
	}

	if(ladders->empty()){
		cout << "Impossível criar plataformas" << endl;

		return false;
	}

	if(!player->isPlayerCreated){
		cout << "Player não criado" << endl;

		return false;
	}

	if(!kong->isKongCreated){
		cout << "Kong não criado" << endl;

		return false;
	}

	return true;
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

void deadDetector(Player *&player, vector<Barrel> *barrels, Kong *&kong, bool *isDead, Musics *music, sf::Clock *gameClock, sf::Time *gameTime, sf::Time *pausedTime, sf::Time *pausedTimeOld){
	if(*isDead){
		delete player;
		delete kong;
		barrels->clear();
		music->stop();
		gameClock->restart();
		*gameTime = sf::Time::Zero;
		*pausedTime = sf::Time::Zero;
		*pausedTimeOld = sf::Time::Zero;
		player = new Player();
		kong = new Kong();
		music->play();
		*isDead = false;
	}
}

void kongAnimations(Kong *kong, vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrels, sf::Texture *textureBarrel){
	kong->chooseAnimation();
	if(kong->barrelTexture == true){
		for(int i = 0; i < (kong->randomAnimation()%2)+1; i++){
			barrelCreator(barrels, collisionCheckerBarrels, textureBarrel, kong);
		}
		kong->barrelTexture = false;
	}
}

void barrelCreator(vector<Barrel> *barrels, vector<bool> *collisionCheckerBarrels, sf::Texture *textureBarrel, Kong *kong){
	Barrel barrel;

	barrel.setVelToZero();
	barrels->push_back(barrel);

	barrels->at(barrels->size() - 1).setTexture(textureBarrel);

	collisionCheckerBarrels->push_back(false);
}

void checkPlayerStatus(Player *player, vector<Barrel> *barrels, size_t numBarrels, bool *collisionCheckerPlayer, vector<bool> *collisionCheckerBarrels, sf::RenderWindow &window, size_t numPlataforma, vector<Platforms> *platforms, Musics *music, size_t numEscada, vector<Ladder> *ladders, Kong *kong, bool *isDead, bool *isWon){
	if(player->getPositionY() < 65.77){
		*isWon = true;
	}

	if(player->getPositionY() > 600 + player->getSprite().getLocalBounds().height * player->getSprite().getScale().y){
		*isDead = true;
	}

	player->move();

	if(player->getSprite().getGlobalBounds().intersects(kong->getSprite().getGlobalBounds()))
	{
		*isDead = true;
	}

	player->setisColliding(*collisionCheckerPlayer);

	for(numPlataforma = 0; numPlataforma < platforms->size(); numPlataforma++){
		if(player->collisionTest(platforms->at(numPlataforma))){
			*collisionCheckerPlayer = true;
			break;
		}
	}

	player->setisColliding(*collisionCheckerPlayer);

	for(numEscada = 0; numEscada < ladders->size(); numEscada++){
		if(player->inLadder(ladders->at(numEscada))){
			break;
		}
	}

	for(numBarrels = 0; numBarrels < barrels->size(); numBarrels++){
		barrels->at(numBarrels).move();

		if(player->getSprite().getGlobalBounds().intersects(barrels->at(numBarrels).getSprite().getGlobalBounds())){
			*isDead = true;
		}


		barrels->at(numBarrels).setisColliding(collisionCheckerBarrels->at(numBarrels));

		for(numPlataforma = 0; numPlataforma < platforms->size(); numPlataforma++){
			if(barrels->at(numBarrels).collisionTest(platforms->at(numPlataforma))){
				collisionCheckerBarrels->at(numBarrels) = true;
				break;
			}
		}

		barrels->at(numBarrels).setisColliding(collisionCheckerBarrels->at(numBarrels));

		for(numEscada = 0; numEscada < ladders->size(); numEscada++){
			if(barrels->at(numBarrels).inLadder(ladders->at(numEscada))){
				break;
			}
		}

		if(barrels->at(numBarrels).endTrack){
			barrels->erase(barrels->begin() + numBarrels);
		}
	}
}

void timeManager(sf::Clock *gameClock, sf::Time *gameTime, sf::Time *pausedTime, sf::Time *pausedTimeOld, sf::Time *winTime, sf::Time *recordTime, sf::Time *devTime, bool *timePause, bool *isPaused, bool *isWon){
	if(!(*isPaused) && !(*isWon)){
		if(*recordTime < *devTime){
			*devTime = sf::Time::Zero;
		}
		*pausedTimeOld = *pausedTime;
		*gameTime = gameClock->getElapsedTime();
		*gameTime = *gameTime - *pausedTime;
		*timePause = false;
	}
	else if(*isPaused && !(*isWon)){
		if(!(*timePause)){
			*gameTime = gameClock->getElapsedTime();
		}
		*timePause = true;

		*pausedTime = *pausedTimeOld + gameClock->getElapsedTime() - *gameTime;
	}
	else if(!(*isPaused) && *isWon){
		if(!(*timePause)){
			*gameTime = gameClock->getElapsedTime();
		}
		*timePause = true;

		*winTime = *gameTime - *pausedTime;
		if(*winTime < *recordTime){
			*recordTime = *winTime;
		}
	}
}

void hudUpdater(sf::Text *txtTime, sf::Font *font, sf::Time *gameTime, sf::RenderWindow &window){
	float seconds = gameTime->asSeconds();
	seconds = floorf(seconds * 100) / 100;
	int minutes = seconds / 60;
	seconds = seconds - minutes * 60;
	int seconds2 = seconds;
	int milliseconds = (seconds - seconds2) * 100;
	stringstream ss;
	ss << "Time: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds;
	txtTime->setString(ss.str());
	txtTime->setFont(*font);
	txtTime->setCharacterSize(20);
	txtTime->setPosition(sf::Vector2f(620, 10));
}

void pauseMenu(sf::Text *txtPause1, sf::Text *txtPause2, sf::Font *font, sf::RenderWindow &window){
	txtPause1->setString("PAUSED");
	txtPause1->setFont(*font);
	txtPause1->setCharacterSize(50);
	txtPause1->setPosition(sf::Vector2f(window.getSize().x/2 - txtPause1->getGlobalBounds().width/2, window.getSize().y/2 - txtPause1->getGlobalBounds().height/2 - 15));

	txtPause2->setString("Press ESC to continue");
	txtPause2->setFont(*font);
	txtPause2->setCharacterSize(25);
	txtPause2->setPosition(sf::Vector2f(window.getSize().x/2 - txtPause2->getGlobalBounds().width/2, window.getSize().y/2 + txtPause2->getGlobalBounds().height/2 + 15));
}

void winMenu(sf::Text *txtWin1, sf::Text *txtWin2, sf::Text *txtWin3, sf::Font *font, sf::Time *winTime, sf::Time *recordTime, sf::Time *devTime, sf::RenderWindow &window){
	txtWin1->setString("YOU WIN");
	txtWin1->setFont(*font);
	txtWin1->setStyle(sf::Text::Bold);
	txtWin1->setCharacterSize(50);
	txtWin1->setPosition(sf::Vector2f(window.getSize().x/2 - txtWin1->getGlobalBounds().width/2, window.getSize().y/2 - txtWin1->getGlobalBounds().height/2 - 30));

	if(*winTime == *recordTime){
		float seconds = winTime->asSeconds();
		seconds = floorf(seconds * 100) / 100;
		int minutes = seconds / 60;
		seconds = seconds - minutes * 60;
		int seconds2 = seconds;
		int milliseconds = (seconds - seconds2) * 100;
		stringstream ss;
		if(*recordTime < *devTime){
			ss << "Your time was: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds << ". You beat the dev time!";
		}
		else if(*devTime == sf::Time::Zero){
			ss << "Your time was: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds << ". You beat your record!";
		}
		else{
			ss << "Your time was: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds << ". You beat your record! Now beat the dev time!";
			txtWin2->setLetterSpacing(0.6);
		}
		txtWin2->setString(ss.str());
	}
	else{
		float secondsWin = winTime->asSeconds();
		secondsWin = floorf(secondsWin * 100) / 100;
		int minutesWin = secondsWin / 60;
		secondsWin = secondsWin - minutesWin * 60;
		int seconds2Win = secondsWin;
		int millisecondsWin = (secondsWin - seconds2Win) * 100;
		if(*winTime < sf::seconds(30.0f) && *devTime != sf::Time::Zero){
			float seconds = devTime->asSeconds();
			seconds = floorf(seconds * 100) / 100;
			int minutes = seconds / 60;
			seconds = seconds - minutes * 60;
			int seconds2 = seconds;
			int milliseconds = (seconds - seconds2) * 100;
			stringstream ss;
			ss << "Your time was: " << std::setfill('0') << std::setw(1) << minutesWin << ":" << std::setfill('0') << std::setw(2) << seconds2Win << "." << std::setfill('0') << std::setw(2) << millisecondsWin << ".The dev time is: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds << ".";
			txtWin2->setString(ss.str());
		}
		else{
			float seconds = devTime->asSeconds();
			seconds = floorf(seconds * 100) / 100;
			int minutes = seconds / 60;
			seconds = seconds - minutes * 60;
			int seconds2 = seconds;
			int milliseconds = (seconds - seconds2) * 100;
			stringstream ss;
			ss << "Your time was: " << std::setfill('0') << std::setw(1) << minutesWin << ":" << std::setfill('0') << std::setw(2) << seconds2Win << "." << std::setfill('0') << std::setw(2) << millisecondsWin << ".Your record is: " << std::setfill('0') << std::setw(1) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds2 << "." << std::setfill('0') << std::setw(2) << milliseconds << ".";
			txtWin2->setString(ss.str());
		}
	}
	txtWin2->setFont(*font);
	txtWin2->setCharacterSize(20);
	txtWin2->setPosition(sf::Vector2f(window.getSize().x/2 - txtWin2->getGlobalBounds().width/2, window.getSize().y/2 + txtWin2->getGlobalBounds().height/2 + 15));

	txtWin3->setString("Press Enter to restart or close to exit");
	txtWin3->setFont(*font);
	txtWin3->setCharacterSize(20);
	txtWin3->setPosition(sf::Vector2f(window.getSize().x/2 - txtWin3->getGlobalBounds().width/2, window.getSize().y/2 + txtWin3->getGlobalBounds().height/2 + 45));
}

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, size_t numBarrels, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player, vector<Barrel> *barrels, Kong *kong, sf::Text *txtTime){
	window.clear(sf::Color::Black);

	window.draw(fundoImage);

	window.draw(*txtTime);

	for(numEscada = 0; numEscada < ladders->size(); numEscada++){
		ladders->at(numEscada).draw(window);
	};

	for(numPlataforma = 0; numPlataforma<platforms->size();numPlataforma++){
		window.draw(platforms->at(numPlataforma).getShape());
	};

	for(numBarrels = 0; numBarrels < barrels->size(); numBarrels++){
		barrels->at(numBarrels).draw(window);
	};

	player->draw(window);

	kong->draw(window);

	window.display();
}

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, size_t numEscada, size_t numPlataforma, size_t numBarrels, vector<Ladder> *ladders, vector<Platforms> *platforms, Player *player, vector<Barrel> *barrels, Kong *kong, sf::Text *txtTime, sf::Text *txtPause1, sf::Text *txtPause2){
	window.clear(sf::Color::Black);

	window.draw(fundoImage);

	window.draw(*txtTime);

	for(numEscada = 0; numEscada < ladders->size(); numEscada++){
		ladders->at(numEscada).draw(window);
	};

	for(numPlataforma = 0; numPlataforma<platforms->size();numPlataforma++){
		window.draw(platforms->at(numPlataforma).getShape());
	};

	for(numBarrels = 0; numBarrels < barrels->size(); numBarrels++){
		barrels->at(numBarrels).draw(window);
	};

	player->draw(window);

	kong->draw(window);

	window.draw(*txtPause1);
	window.draw(*txtPause2);

	window.display();
}

void windowDraw(sf::RenderWindow &window, sf::Sprite &fundoImage, sf::Text *txtWin1, sf::Text *txtWin2, sf::Text *txtWin3){
	window.clear(sf::Color::Black);

	window.draw(fundoImage);

	window.draw(*txtWin1);
	window.draw(*txtWin2);
	window.draw(*txtWin3);

	window.display();
}
