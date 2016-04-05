/*
 * Pinky.h
 *
 *  Created on: 21 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef PINKY_H_
#define PINKY_H_
#include "GameObjectStruct.h"
#include "Ghost.h"

//inherits functions from class Ghost & GameObjectstruct
class Pinky : public GameObjectStruct, public Ghost {
public:
	//Initializes the start position of this GameObject
	Pinky();
	//Determines possible directions for the next move,
	//but goes preferably not in the opposite direction of the last movement
	void determineDirection(std::vector<std::vector<int>> &map);
	//Executes chosen move for this GameObject
	void determineMove(std::vector<std::vector<int>> &map);
};

#endif /* PINKY_H_ */
