/***********************************************************************
*  Source File:
*     Board
*
*  Author:
*     John Ellefson
*
*  Summary:
*	  The implementation for the Board class.
************************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include "Board.h"
using namespace std;


/******************************************
* Board : Display
* Displays the tic-tac-toe board on screen.
*****************************************/
void Board::display()
{
	// Display the current game board on the screen
	cout << endl;
	cout << "    A   B   C\n";
	cout << " 1  " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << endl;
	cout << "   -----------" << endl;
	cout << " 2  " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << endl;
	cout << "   -----------" << endl;
	cout << " 3  " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << endl;

}

/******************************************
* Board : Add Symbol To Board
* Adds the given symbol to the specified coordinate.
*****************************************/
bool Board::addSymbolToBoard(string coord, bool isXTurn)
{
	int row = 0;
	int col = 0;

	// Convert the column char to lowercase
	char lowercaseCol = tolower(coord[0]);

	// Ensure that coord is only 2 characters long
	if (coord.length() != 2)
		return false;

	// Determine the specified col
	if (lowercaseCol == 'a')
		col = 0;
	else if (lowercaseCol == 'b')
		col = 1;
	else if (lowercaseCol == 'c')
		col = 2;
	else
		return false;

	// Determine the specified row
	if (coord[1] == '1')
		row = 0;
	else if (coord[1] == '2')
		row = 1;
	else if (coord[1] == '3')
		row = 2;
	else
		return false;

	// Place the active player's symbol in the specified locaiton
	if (grid[row][col] == ' ')
	{
		if (isXTurn)
			grid[row][col] = 'X';
		else
			grid[row][col] = 'O';
	}
	else
		return false;

	// The symbol was successfully placed
	return true;
}

/******************************************
* Board : Is Any 3 In A Row
* Determines whether there is 3 in a row of a symbol.
*****************************************/
bool Board::isAny3InARow()
{
	char line[3];

	// Check each horizontal line for 3 same symbols in a row 
	for (int r = 0; r <= 2; r++)
	{
		for (int c = 0; c <= 2; c++)
			line[c] = grid[r][c];

		// Check if all symbols in this line are the same and not a space
		if (line[0] == line[1] && line[1] == line[2] && line[0] != ' ')
			return true;
	}

	// Check each vertical line for 3 same symbols in a row 
	for (int c = 0; c <= 2; c++)
	{
		for (int r = 0; r <= 2; r++)
			line[r] = grid[r][c];

		// Check if all symbols in this line are the same and not a space
		if (line[0] == line[1] && line[1] == line[2] && line[0] != ' ')
			return true;
	}

	// Check each diagional line for 3 same symbols in a row 
	if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[0][0] != ' ')
		return true;
	if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0] && grid[0][2] != ' ')
		return true;

	// No lines had 3 same symbols in a row
	return false;
}

/******************************************
* Board : Is Board Filled
* Determines whether of not the board is
* completely filled or not.
*****************************************/
bool Board::isBoardFilled()
{
	// Check each element for empty spaces to determine if the board is filled
	for (int r = 0; r <= 2; r++)
		for (int c = 0; c <= 2; c++)
		{
			// If empty spaces are found, then the board is not filled
			if (grid[r][c] == ' ')
				return false;
		}

	// No empty spaces were found so the board is filled
	return true;
}