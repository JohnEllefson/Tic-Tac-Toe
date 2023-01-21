/***********************************************************************
*  Header File:
*     Game
* 
*  Author:
*     John Ellefson
* 
*  Summary:
*     Runs the game and keeps track of the game state.
************************************************************************/

#pragma once
#include <iostream>
#include <string>
#include <queue>
#include "board.h"
using namespace std;


// Enumeration to hold the game state
enum GameStatus { in_game, draw, xWin, oWin, end_game }; 

/*************************************************************************
 * GAME
 * Runs the game and keeps track of the game state.
 *************************************************************************/
class Game
{
private:
	Board board;
	GameStatus state;
	bool isXTurn;
	queue<string> moveHistory;

public:
	Game();
	void run();
};