/*
 * Inky.cpp
 *
 *  Created on: 21 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#include "Inky.h"
#include <stdlib.h>

Inky::Inky() {
	type = INKY;
	dir = UP;
	x = 12;
	y = 13;
}

void Inky::determineDirection(std::vector<std::vector<int>> &map) {
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

void Inky::determineMove(std::vector<std::vector<int>> &map) {
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

void Inky::determinePDirection(std::vector<std::vector<int>> &map, Pacman pacman ) {
	//The direction which is used for the latest movement is chosen
	//The method determine where pacman is and based upon the location of pacman it will choose a direction.
	//However, to avoid being stuck in the middle the ghost cannot move back.
	//Also he will panic out when he is scared and use the determineDirection method.
	//When there are no possible directions, the standard determineDirection is called, which then will determine the direction.
	if(type != SCARED) {
		if(pacman.x >= x && pacman.y >= y) {
			if(map[y][x + 1] == 0 && dir != LEFT) {
				dir = RIGHT;
			} else if(map[y + 1][x] == 0 && dir != UP) {
				dir = DOWN;
			} else {
				determineDirection(map);
			}
		} else if(pacman.x >= x && pacman.y <= y) {
			if(map[y][x + 1] == 0 && dir != LEFT) {
				dir = RIGHT;
			} else if(map[y - 1][x] == 0 && dir != UP) {
				dir = UP;
			} else {
				determineDirection(map);
			}
		} else if(pacman.x <= x && pacman.y >= y) {
			if(map[y][x - 1] == 0 && dir != RIGHT) {
				dir = LEFT;
			} else if (map[y + 1][x] == 0 && dir != UP) {
				dir = DOWN;
			} else {
				determineDirection(map);
			}
		} else if(pacman.x <= x && pacman.y <= y && dir != RIGHT) {
			if(map[y][x - 1] == 0) {
				dir = LEFT;
			} else if(map[y - 1][x] == 0 && dir != DOWN) {
				dir = UP;
			} else {
				determineDirection(map);
			}
		} else {
			determineDirection(map);
		}
	} else {
		determineDirection(map);
	}

}
