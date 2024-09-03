/*
 * sounds.hpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: davis
 */

#ifndef SRC_SOUNDS_HPP_
#define SRC_SOUNDS_HPP_

#include <iostream>
#include <SFML/audio.hpp>

using namespace std;

class Sounds {
protected:
	sf::Sound sound;
	sf::SoundBuffer soundBuffer;
	string soundLocation;

public:
	Sounds();
	bool setSound(string Location);
	string getSoundLocation();
	void play();
	void pause();
	void stop();
};

#endif /* SRC_SOUNDS_HPP_ */
