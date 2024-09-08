/*
 * audio.hpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: Davi Sollar
 */

#ifndef SRC_AUDIO_HPP_
#define SRC_AUDIO_HPP_

#include <iostream>
#include <SFML/audio.hpp>

using namespace std;

class Audio {
protected:
	string audioLocation;
	int volume;
	inline void saveVolume(int volume){
		this->volume = volume;
	};
public:
	Audio();
	bool setAudio(string location);
	void play();
	void pause();
	void stop();
	void loop();
	void setVolume();
	inline string getAudioLocation(){
		return audioLocation;
	};
	inline int getVolume(){
		return volume;
	};
	inline void setAudioLocation(string location){
		audioLocation = location;
	};
};

#endif /* SRC_AUDIO_HPP_ */
