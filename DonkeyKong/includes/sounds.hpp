/*
 * sounds.hpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: Davi Sollar
 */

#ifndef SRC_SOUNDS_HPP_
#define SRC_SOUNDS_HPP_

#include "audios.hpp"

using namespace std;

class Sounds: public Audio{
private:
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
public:
	Sounds();
	bool setAudio(string location);
	void play();
	void pause();
	void stop();
	void setVolume(int volume);
};

#endif /* SRC_SOUNDS_HPP_ */
