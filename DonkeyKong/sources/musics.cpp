/*
 * Musics.cpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: davis
 */

#include "../includes/musics.hpp"

Musics::Musics(){}

bool Musics::setMusic(string Location){
	if(music.openFromFile(Location)){
		musicLocation = Location;
		return true;
	}else{
		return false;
	}
}

string Musics::getMusicLocation(){
	return musicLocation;
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
