/*
 * sounds.cpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: davis
 */

#include "../includes/sounds.hpp"

using namespace std;

Sounds::Sounds(){}

bool Sounds::setSound(string Location){
	if(soundBuffer.loadFromFile(Location)){
		sound.setBuffer(soundBuffer);
		soundLocation = Location;
		return true;
	}else{
		return false;
	}
}

string Sounds::getSoundLocation(){
	return soundLocation;
}

void Sounds::play(){
	sound.play();
}

void Sounds::pause(){
	sound.pause();
}

void Sounds::stop(){
	sound.stop();
}
