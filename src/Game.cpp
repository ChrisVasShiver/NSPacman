/*
 * Game.cpp
 *
 *  Created on: 29 mrt. 2016
 *      Author: Christiaan Visscher & Thierry Sterrenburg
 *		 Group: 02
 */

#include "Game.h"
#include <iostream>

Game::Game() {
	lives = 3;
	score = 0;
	scaredTimer = 0;
	hasFruit = false;
}

Pacman& Game::getPacman() {
	return pacman;
}

Blinky& Game::getBlinky() {
	return blinky;
}

Clyde& Game::getClyde() {
	return clyde;
}

Inky& Game::getInky() {
	return inky;
}

Pinky& Game::getPinky() {
	return pinky;
}

int& Game::getLives() {
	return lives;
}

int& Game::getScore() {
	return score;
}

std::vector<GameObjectStruct> Game::getObjects() {
	return objects;
}

std::vector<GameObjectStruct>& Game::getEmptyPlaces() {
	return emptyPlaces;
}

bool Game::isGameOver() {
	//The game stops when there are no dots or lives left
	if(dotObjects.size() <= 0) {
		return true;
	} else if(dotObjects.size() == 1 && (dotObjects[0].type == CHERRY || dotObjects[0].type == STRAWBERRY || dotObjects[0].type == ORANGE || dotObjects[0].type == LEMON || dotObjects[0].type == APPEL || dotObjects[0].type == GRAPES)) {
		return true;
	}	else if(lives <= 0) {
		return true;
	} else {
		return false;
	}
}

bool Game::containsFruit() {
	return hasFruit;
}


void Game::update() {
	//Clears the objects from the board
	objects.clear();
	//Pushes the dots in the objects vector
	for(GameObjectStruct dot : dotObjects) {
		objects.push_back(dot);
	}
	//Pushes Pacman and the Ghosts in the objects vector
	objects.push_back(pacman);
	objects.push_back(blinky);
	objects.push_back(clyde);
	objects.push_back(inky);
	objects.push_back(pinky);
}

void Game::updateScaredTimer() {
	//Updates the timer and when there is no time left the Ghosts are set to their initial type
	if(scaredTimer > 0) {
		scaredTimer--;
	} else {
		blinky.type = BLINKY;
		clyde.type = CLYDE;
		inky.type = INKY;
		pinky.type = PINKY;
	}
}

void Game::initDots(std::vector<std::vector<int>> &map) {
	for(int y =maxHeight; y >= 0; y--){
		//Places the energizers in the corners of the board
		//On all other places there are dots placed
		for(int x=0; x < maxWidth; x++){
			if((x==1 || x==maxWidth-2) && (y == 1 || y==maxHeight-1)){
                GameObjectStruct energizer;
                energizer.type = ENERGIZER;
                energizer.x = x;
                energizer.y = y;
                dotObjects.push_back(energizer);
			}
			else if(map[y][x] == 0){
                GameObjectStruct dot;
                dot.type = DOT;
                dot.x = x;
                dot.y = y;
                dotObjects.push_back(dot);
			}
		}
	}
}

void Game::setFruit() {
	//creates a random number between 0 and 5, which will result in a fruit
	int random = rand() % 6;
	//picks a random place out of all empty places
	int ranPlace = rand() % emptyPlaces.size();
	GameObjectStruct fruit;
	if(random == 0){
		fruit.type=CHERRY;
	}else if(random == 1){
		fruit.type =STRAWBERRY;
	}else if(random == 2){
		fruit.type =ORANGE;
	}else if(random == 3){
			fruit.type =LEMON;
	}else if(random == 4){
			fruit.type =APPEL;
	}else if(random == 5){
		fruit.type =GRAPES;
	}
	//places the fruit on the board
	fruit.x = emptyPlaces[ranPlace].x;
	fruit.y = emptyPlaces[ranPlace].y;
	//sets boolean for fruit on true, so that no other fruit will be placed.
	hasFruit = true;
	//erases the empty place from the vector with empty places
	emptyPlaces.erase(emptyPlaces.begin() + ranPlace);
	//pushes the fruit to the vector with the dots
	dotObjects.push_back(fruit);
}

void Game::hasDotCollision() {
	//Checks if there is a collision between Pacman and a dot, and if so add one point to the score
	for(unsigned int i = 0; i < dotObjects.size(); i++) {
		if(dotObjects[i].x == pacman.x && dotObjects[i].y == pacman.y) {
			if(dotObjects[i].type == DOT) {
				score++;

	//If there is a collision between Pacman and an energizer, than there is Scared Timer set.
	//The Ghosts will set to the type scared.
			} else if(dotObjects[i].type == ENERGIZER) {
				scaredTimer = scareTime;
				score = score + ESCORE;
				pinky.type=SCARED;
				inky.type=SCARED;
				blinky.type=SCARED;
				clyde.type=SCARED;

	//Checks if there is a collision between Pacman and a fruit, and if so add points to the score and set the boolean hasfruit on false.
			}else if(dotObjects[i].type == CHERRY || dotObjects[i].type == STRAWBERRY || dotObjects[i].type == ORANGE || dotObjects[i].type == LEMON || dotObjects[i].type == APPEL || dotObjects[i].type == GRAPES){
				score = score + FSCORE;
				hasFruit = false;
			}
	//The position of the eaten object is added to the vector of empty places and erased from the vector with the dots.
			emptyPlaces.push_back(dotObjects[i]);
			dotObjects.erase(dotObjects.begin() + i);
		}
	}
}

void Game::hasGhostCollision() {
	//Checks for every Ghost if the location is the same as Pacman.
	//When the location is the same, it determines whether the Ghost is scared or not.
	//If the Ghost is scared, the Ghost will set to it's initial state and points will be added to the score.
	//If the Ghosts is not scared the lives will be decremented with one live and Pacman and the Ghosts will get their initial location.
	if(pacman.x == inky.x && pacman.y == inky.y) {
		if(inky.type==SCARED){
			inky.x = 12;
			inky.y = 13;
			inky.type = INKY;
			score= score + GSCORE;
		}else{
			if(!(lives <= 0)) {
				lives--;
				resetPositions();
			}
		}
	} else if(pacman.x == blinky.x && pacman.y == blinky.y) {
		if(blinky.type == SCARED){
			blinky.x = 13;
			blinky.y = 13;
			blinky.type = BLINKY;
			score= score+GSCORE;
		}else{
			if(!(lives <= 0)) {
				lives--;
				resetPositions();
			}
		}
	} else if(pacman.x == pinky.x && pacman.y == pinky.y) {
		if(pinky.type==SCARED){
			pinky.x=14;
			pinky.y=13;
			pinky.type=PINKY;
			score= score+GSCORE;
		}else{
			if(!(lives <= 0)) {
				lives--;
				resetPositions();
			}
		}
	} else if(pacman.x == clyde.x && pacman.y == clyde.y) {
		if(clyde.type==SCARED){
			clyde.x=15;
			clyde.y=13;
			clyde.type=CLYDE;
			score= score+GSCORE;
		}else{
			if(!(lives <= 0)) {
				lives--;
				resetPositions();
			}
		}
	}
}

void Game::resetPositions() {
	pacman.x = 13;
	pacman.y = 5;
	pacman.dir = UP;

	inky.x = 12;
	inky.y = 13;
	inky.type = INKY;

	blinky.x = 13;
	blinky.y = 13;
	blinky.type = BLINKY;

	pinky.x = 14;
	pinky.y = 13;
	pinky.type = PINKY;

	clyde.x = 15;
	clyde.y = 13;
	clyde.type = CLYDE;
}
