/***********************************************************************
*  Source File:
*     Game
*
*  Author:
*     John Ellefson
*
*  Summary:
*	  The implementation for the Game class.
************************************************************************/

#include "Game.h"
#include <stdlib.h>


/******************************************
* Game : Default Constructor
* Sets initial game state and player turn.
*****************************************/
Game::Game()
{
	isXTurn = true;
	state = in_game;
}

/******************************************
* Game : Run
* Runs the game based on current game state.
*****************************************/
void Game::run()
{
	string coordInput;

	while (state != end_game)
	{
		switch (state)
		{

		// *************** Game Is In Progress ******************
		case in_game:
			// Display the board
			board.display();

			// Indicate who's turn it is
			cout << "\nIt is ";
			if (isXTurn == true)
				cout << "X's turn\n";
			else
				cout << "O's turn\n";

			// Prompt the player to enter coordinates to place the next symbol
			cout << "Enter coordinates to place ";
			if (isXTurn == true)
				cout << "an X: ";
			else
				cout << "a O: ";
			getline(cin, coordInput);

			// Clear the screen so it will be directly replaced with the new output
			system("cls");

			// Attempt to add a symbol to the specified location, if successful, check the board to see if the game is over
			if (board.addSymbolToBoard(coordInput, isXTurn))
			{
				// Add the move to the move history queue
				if (isXTurn)
					moveHistory.push("X:" + coordInput);
				else
					moveHistory.push("O:" + coordInput);

				// If Board is fully filled, the game is a draw
				if (board.isBoardFilled())
					state = draw;

				// If any line has 3 of a specific symbol in a row, then the respective player wins
				if (board.isAny3InARow())
					if (isXTurn)
						state = xWin;
					else
						state = oWin;

				// If the game is still active alternate turns
				if (state == in_game)
					isXTurn = !isXTurn;
			}
			else
				cout << "\nERROR: The coordindate you entered is invalid.\n\n";
			break;


		// *************** Draw ******************
		case draw:
			board.display();

			cout << "\nThe game is a draw\n";
			state = end_game;
			break;

		// *************** X Wins ******************
		case xWin:
			board.display();

			cout << "\nPlayer X wins!\n";
			state = end_game;
			break;

		// *************** O Wins ******************
		case oWin:
			board.display();

			cout << "\nPlayer O wins!\n";
			state = end_game;
			break;
		}
	}

	// Print the move history for the game
	cout << "\nMove History:\n";
	while (!moveHistory.empty())
	{
		cout << moveHistory.front();
		moveHistory.pop();

		// Print commas after each move execpt the last 
		if (moveHistory.size() != 0)
			cout << ", ";
		else
			cout << endl;
	}
}