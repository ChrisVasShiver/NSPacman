/*
 * main.h
 *
 *  Created on: Feb 18, 2015
 *      Author: frits
 *       Group: TA's
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_
#include "Game.h"
// ID of the timer that calls the update function
SDL_TimerID timer_id;

// Callback function of the timer.
Uint32 gameUpdate(Uint32 interval, void *param);

// Our event structure
SDL_Event e;
//Creates a game
Game game;
//Checks if Pacman is GameOver
bool quit;


#endif /* SRC_MAIN_H_ */
