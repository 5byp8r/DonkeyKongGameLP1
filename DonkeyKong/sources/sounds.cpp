/*
 * sounds.cpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: Davi Sollar
 */

#include "../includes/sounds.hpp"

using namespace std;

Sounds::Sounds(){}

bool Sounds::setAudio(string location){
	if(soundBuffer.loadFromFile(location)){
		sound.setBuffer(soundBuffer);
		setAudioLocation(location);
		return true;
	}else{
		return false;
	}
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

void Sounds::setVolume(int volume){
	sound.setVolume(volume);
	saveVolume(volume);
}
