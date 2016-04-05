/*
 * Blinky.cpp
 *
 *  Created on: 21 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#include "Blinky.h"
#include <stdlib.h>

Blinky::Blinky() {
	type = BLINKY;
	dir = UP;
	x = 13;
	y = 13;
}

void Blinky::determineDirection(std::vector<std::vector<int>> &map) {
	//The direction which is used for the latest movement is chosen
	//In each case there is a check of the three possible directions except for the opposite direction of the latest movement
	//When there are no possible directions, the gameObject reverses his latest movement
	switch(dir){
	case LEFT:
	{
		std::vector<Direction> directions;
		if(map[y - 1][x] == 0) {
			directions.push_back(UP);
		}
		if(map[y + 1][x] == 0) {
			directions.push_back(DOWN);
		}
		if(directions.size() > 0) {
			if(map[y][x-1] == 0) {
				directions.push_back(LEFT);
			}
			int random = rand() % directions.size();
			dir = directions[random];
		} else if(directions.size() == 0 && map[y][x-1] == 1) {
			dir = RIGHT;
		}
		break;
	}
	case RIGHT:
	{
		std::vector<Direction> directions;
		if(map[y - 1][x] == 0) {
			directions.push_back(UP);
		}
		if(map[y + 1][x] == 0) {
			directions.push_back(DOWN);
		}
		if(directions.size() > 0) {
			if(map[y][x+1] == 0) {
				directions.push_back(RIGHT);
			}
			int random = rand() % directions.size();
			dir = directions[random];
		} else if(directions.size() == 0 && map[y][x+1] == 1) {
			dir = LEFT;
		}
		break;
	}
	case UP:
	{
		std::vector<Direction> directions;
		if(map[y][x-1] == 0) {
			directions.push_back(LEFT);
		}
		if(map[y][x+1] == 0) {
			directions.push_back(RIGHT);
		}
		if(directions.size() > 0) {
			if(map[y -1][x] == 0) {
				directions.push_back(UP);
			}
			int random = rand() % directions.size();
			dir = directions[random];
		} else if(directions.size() == 0 && map[y-1][x] == 1) {
			dir = DOWN;
		}
		break;
	}
	case DOWN:
	{
		std::vector<Direction> directions;
		if(map[y][x-1] == 0) {
			directions.push_back(LEFT);
		}
		if(map[y][x+1] == 0) {
			directions.push_back(RIGHT);
		}
		if(directions.size() > 0) {
			if(map[y +1][x] == 0) {
				directions.push_back(DOWN);
			}
			int random = rand() % directions.size();
			dir = directions[random];
		} else if(directions.size() == 0 && map[y+1][x] == 1) {
			dir = UP;
		}
		break;
	}
	}
}

void Blinky::determineMove(std::vector<std::vector<int>> &map) {
	//Executes the if statement that suites the chosen direction.
	if(dir == LEFT) {
		//Do move.
		x--;
		//When this GameObject reaches the gap in the wall, the GameObject is placed on the other side of the board.
		if(x < 0) {
			x = 27;
		}
	} else if(dir == RIGHT) {
		//Do move.
		x++;
		//When this GameObject reaches the gap in the wall, the GameObject is placed on the other side of the board.
		if(x > 27){
			x=0;
		}
	} else if(dir == UP) {
		//Do move.
		y--;
	} else if(dir == DOWN) {
		//Do move.
		y++;
	}
}

