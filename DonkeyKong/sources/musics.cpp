/*
 * Musics.cpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: Davi Sollar
 */

#include "../includes/musics.hpp"

Musics::Musics(){}

bool Musics::setAudio(string location){
	if(music.openFromFile(location)){
		setAudioLocation(location);
		return true;
	}else{
		return false;
	}
}

void Musics::play(){
	music.play();
}

void Musics::pause(){
	music.pause();
}

void Musics::stop(){
	music.stop();
}

void Musics::loop(){
	music.setLoop(true);
}

void Musics::setVolume(int volume){
	music.setVolume(volume);
	saveVolume(volume);
}
