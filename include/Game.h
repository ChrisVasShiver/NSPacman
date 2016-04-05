/*
 * Game.h
 *
 *  Created on: 29 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#ifndef GAME_H_
#define GAME_H_
#include "Pacman.h"
#include "Blinky.h"
#include "Clyde.h"
#include "Inky.h"
#include "Pinky.h"
#include "GameObjectStruct.h"
#include <vector>

class Game {
public:
	//Creates a game
	Game();
	//Gets Pacman
	Pacman& getPacman();
	//Gets Blnky
	Blinky& getBlinky();
	//Gets Clyde
	Clyde& getClyde();
	//Gets Inky
	Inky& getInky();
	//Gets Pinky
	Pinky& getPinky();
	//Gets Lives
	int& getLives();
	//Gets Score
	int& getScore();
	//Gets Objects
	std::vector<GameObjectStruct> getObjects();
	//Gets Empty Places
	std::vector<GameObjectStruct>& getEmptyPlaces();
	//Checks if Pacman is GameOver
	bool isGameOver();
	//Checks if there is a fruit on the board
	bool containsFruit();

	//Sets dots for a new game
	void initDots(std::vector<std::vector<int>> &map);
	//Places a fruit on the board
	void setFruit();
	//Updates the board
	void update();
	//Updates the Scared Timer
	void updateScaredTimer();
	//Handles a collision between Pacman and a dot
	void hasDotCollision();
	//Handles a collision between Pacman and a Ghost
	void hasGhostCollision();
	//reset positions for Pacman and the Ghosts
	void resetPositions();


	//max height of the board
	static const int maxHeight = 26;
	//max with of the board;
	static const int maxWidth = 28;
private:
	//scaredtime;
	static const int scareTime = 50;
	//value of a fruit
	static const int FSCORE = 50;
	//value of a scaredGhost
	static const int GSCORE = 100;
	//value of an energizer
	static const int ESCORE = 20;
	//Create Pacman
	Pacman pacman;
	//Create Blinky
	Blinky blinky;
	//Create Clyde
	Clyde clyde;
	//Create Inky
	Inky inky;
	//Create Pinky
	Pinky pinky;
	//Create a vector of GameObjects(dots/energizers/fruits)
	std::vector<GameObjectStruct> dotObjects;
	//Create a vector of GameObjects
	std::vector<GameObjectStruct> objects;
	//Create a vector of all empty places
	std::vector<GameObjectStruct> emptyPlaces;
	//Keeps track of Pacmans lives
	int lives;
	//Keeps track of the score
	int score;
	//Timer for the scared Ghosts
	int scaredTimer;
	//Checks if there is a fruit on the board.
	bool hasFruit;
};

#endif /* GAME_H_ */
