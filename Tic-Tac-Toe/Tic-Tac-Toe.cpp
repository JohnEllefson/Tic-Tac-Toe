/*************************************************************
 *  Name:
 *      John Ellefson
 * 
 *  Assignment Name:
 *      Sprint #1: Tic-Tac-Toe
 * 
 *  Assignment Description:
 *         I chose the C++ module and to create a simple 2 player 
 *      tic-tac-toe game. The tic-tac-toe game takes coordinates
 *      from players to place their respective symbols on the board.
 *      Additionally, the game keeps track of the move history
 *      utilizing a queue and displays each move and the player
 *      who made them in order at the end of each game. 
 * 
 *  What was the hardest part? Be as specific as possible.
 *         The hardest part of this assignment was just re-familiarizing
 *      myself with C++ syntax since I haven't used it in some time.
 * 
 *  How long did it take for you to complete the assignment?
 *      12 hours
 *****************************************************************/

#include <iostream>
#include "Game.h"

/******************************************
* Main
* Creates and runs the game.
*****************************************/
int main()
{
	Game game;

	// Start the game
	game.run();
}