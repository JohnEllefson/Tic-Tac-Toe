/***********************************************************************
*  Header File:
*     Board
*
*  Author:
*     John Ellefson
*
*  Summary:
*     Manage the contents of the 3x3 tic-tac-toe board.
************************************************************************/

#pragma once
#include <iostream>
#include <string>
using namespace std;


/*************************************************************************
* Board
* Manages the contents of the tic-tac-toe board.
*************************************************************************/
class Board
{
private:
	char grid[3][3] = { {' ', ' ', ' '},
					  { ' ', ' ', ' ' },
					  { ' ', ' ', ' ' }};

public:
	Board() { };
	void display();
	bool addSymbolToBoard(string coord, bool isXTurn);

	bool isAny3InARow();
	bool isBoardFilled();
};