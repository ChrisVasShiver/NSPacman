/*
 * Blinky.h
 *
 *  Created on: 21 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef BLINKY_H_
#define BLINKY_H_
#include "GameObjectStruct.h"
#include "Ghost.h"

//inherits functions from class Ghost & GameObjectstruct
class Blinky : public GameObjectStruct, public Ghost {
public:
	//Initializes the start position of this GameObject
	Blinky();
	//Determines possible directions for the next move,
	//but goes preferably not in the opposite direction of the last movement
	void determineDirection(std::vector<std::vector<int>> &map);
	//Executes chosen move for this GameObject
	void determineMove(std::vector<std::vector<int>> &map);
};

#endif /* BLINKY_H_ */
