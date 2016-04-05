/*
 * Pacman.h
 *
 *  Created on: 22 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef PACMAN_H_
#define PACMAN_H_
#include "GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>

//inherits functions from class GameObjectstruct
class Pacman : public GameObjectStruct {
public:
	//Initializes the start position of this GameObject
	Pacman();
	//Checks whether a given input is valid as direction
	bool determineMove();
	//Executes chosen move for this GameObject
	void doMove(std::vector<std::vector<int>> &map);
private:
	SDL_Event e;
};



#endif /* PACMAN_H_ */
