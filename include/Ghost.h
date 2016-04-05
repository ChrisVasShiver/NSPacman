/*
 * Ghost.h
 *
 *  Created on: 22 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef GHOST_H_
#define GHOST_H_

#include <vector>

class Ghost {
public:
	//Virtual functions are used, because Inky, Pibky, Blinky & Clyde inherit these functions
	//Determines possible directions for the next move
	virtual void determineDirection(std::vector<std::vector<int>> &map) = 0;
	//Executes chosen move for this GameObject
	virtual void determineMove(std::vector<std::vector<int>> &map) = 0;
};

#endif /* GHOST_H_ */
