/*
 * Pacman.cpp
 *
 *  Created on: 22 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#include "Pacman.h"

Pacman::Pacman() {
	type = PACMAN;
	dir = UP;
	x = 13;
	y = 5;
}

bool Pacman::determineMove() {
	bool quit = false;
	while (SDL_PollEvent(&e)){
		// Quit button.
		if (e.type == SDL_QUIT){
			quit = true;
		}

		// All keydown events
		if (e.type == SDL_KEYDOWN){
            switch (e.key.keysym.sym)
            {
            case SDLK_LEFT:   dir = LEFT; break;
            case SDLK_RIGHT:  dir = RIGHT; break;
            case SDLK_UP:     dir = UP; break;
            case SDLK_DOWN:   dir = DOWN; break;
            case SDLK_ESCAPE: quit= true; break;
            }
		}
	}
	return quit;
}

void Pacman::doMove(std::vector<std::vector<int>> &map) {
	switch(dir) {
	case LEFT:
		//Checks if the chosen movement is valid.
		if(map[y][x -1] != 1) {
			//Do move.
			x--;
		}
		//When this GameObject reaches the gap in the wall, the GameObject is placed on the other side of the board.
		if(x < 0){
			x=27;
		}
		break;
	case RIGHT:
		//Checks if the chosen movement is valid.
		if(map[y][x +1] != 1) {
			//Do move.
			x++;
		}
		//When this GameObject reaches the gap in the wall, the GameObject is placed on the other side of the board.
		if(x > 27){
			//Do move.
			x=0;
		}
		break;
	case UP:
		//Checks if the chosen movement is valid.
		if(map[y -1][x] != 1) {
			//Do move.
			y--;
		}
		break;
	case DOWN:
		//Checks if the chosen movement is valid.
		if(map[y +1][x] != 1) {
			//Do move.
			y++;
		}
		break;
	}
}

