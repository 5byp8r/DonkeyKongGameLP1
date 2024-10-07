/*
 * main.cpp
 *
 *  Created on: 22 de ago. de 2024
 *      Author: Revii
 */

#include "includes/game.hpp"

int main(int argc, char **argv){
	Game Game;
	if(!Game.start()){
		return -1;
	}
	Game.update();
	return 0;
}
