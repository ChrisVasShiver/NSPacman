/*
 * main.cpp
 *
 *  Created on: Jan 29, 2015
 *      Author: frits
 *       Group: TA's
 */

#include "UI.h"
#include "GameObjectStruct.h"
#include <SDL2/SDL.h>
#include <vector>
#include "board.h"
#include "main.h"

int main(int argc, char* argv[]) {

	// Create a new ui object
	UI ui(map); // <-- use map from your game objects.

	// Start timer for game update, call this function every 100 ms.
	timer_id = SDL_AddTimer(125, gameUpdate, (void *)nullptr);

	/* Put game init code here */
	game.initDots(map);
	game.update();

	quit = game.getPacman().determineMove();

	while (!quit){
		// set timeout to limit frame rate
		Uint32 timeout = SDL_GetTicks() + 20;

		// Handle the input
		quit = game.getPacman().determineMove();

		// Set the score
		ui.setScore(game.getScore()); /* <-- Put your code in the setter */

		// Set the amount of lives
		ui.setLives(game.getLives()); /* <-- Put your code in the setter */

		// Render the scene
		ui.update(game.getObjects()); /* <-- Put your code in the update function (e.g. game->getStructs()) */

		while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
		    /* ... do work until timeout has elapsed */
		}
	}

	SDL_RemoveTimer(timer_id);

    return 0;
}


Uint32 gameUpdate(Uint32 interval, void *param)
{
	/** Do game loop update here **/
	game.getPacman().doMove(map);
	game.hasDotCollision();
	game.hasGhostCollision();
	game.getBlinky().determineDirection(map);
	game.getClyde().determineDirection(map);
	game.getInky().determinePDirection(map, game.getPacman());
	game.getPinky().determineDirection(map);
	game.getBlinky().determineMove(map);
	game.getClyde().determineMove(map);
	game.getInky().determineMove(map);
	game.getPinky().determineMove(map);
	game.update();
	game.hasDotCollision();
	game.hasGhostCollision();
	if(game.getEmptyPlaces().size() % 10 == 9 && !game.containsFruit()){
		game.setFruit();
	}
	game.updateScaredTimer();
	game.update();
	quit = game.isGameOver();
	return interval;
}
