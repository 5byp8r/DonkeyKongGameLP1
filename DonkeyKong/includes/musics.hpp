/*
 * Musics.hpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: davis
 */

#ifndef SRC_INCLUDES_MUSICS_HPP_
#define SRC_INCLUDES_MUSICS_HPP_

#include <iostream>
#include <SFML/audio.hpp>

using namespace std;

class Musics {
private:
	sf::Music music;
	string musicLocation;

public:
	Musics();
	bool setMusic(string Location);
	string getMusicLocation();
	void play();
	void pause();
	void stop();
};

#endif /* SRC_INCLUDES_MUSICS_HPP_ */
