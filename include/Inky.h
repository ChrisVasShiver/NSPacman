/*
 * Inky.h
 *
 *  Created on: 21 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef INKY_H_
#define INKY_H_
#include "GameObjectStruct.h"
#include "Ghost.h"
#include "Pacman.h"

//inherits functions from class Ghost & GameObjectstruct
class Inky : public GameObjectStruct, public Ghost {
public:
	//Initializes the start position of this GameObject
	Inky();
	//Determines possible directions for the next move,
	//but goes preferably not in the opposite direction of the last movement
	void determineDirection(std::vector<std::vector<int>> &map);
	//Executes chosen move for this GameObject
	void determineMove(std::vector<std::vector<int>> &map);
	//Determines based on pacman's location the possible directions for the next move.
	void determinePDirection(std::vector<std::vector<int>> &map, Pacman pacman );
};
#endif /* INKY_H_ */
