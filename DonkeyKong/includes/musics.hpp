/*
 * Musics.hpp
 *
 *  Created on: 3 de set. de 2024
 *      Author: Davi Sollar
 */

#ifndef SRC_INCLUDES_MUSICS_HPP_
#define SRC_INCLUDES_MUSICS_HPP_

#include "audios.hpp"

using namespace std;

class Musics: public Audio{
private:
	sf::Music music;
public:
	Musics();
	bool setAudio(string location);
	void play();
	void pause();
	void stop();
	void loop();
	void setVolume(int volume);
};

#endif /* SRC_INCLUDES_MUSICS_HPP_ */
