/***************************************************************************
** Project Mame: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Implementation file for the continueGame function that 
**               allows the user to choose to keep playing or quit.
***************************************************************************/

#include "continue.hpp"

bool continueGame()
{
	int choose;

	cout << "Would you like to continue the game? Enter 1 if you would like to play another day. Enter 2 to exit the game." << endl;
	cin >> choose;

	//Built-in input validation for the game loop.
	while (choose > 2 || choose < 1 || cin.fail() || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(5000, '\n');

		cout << endl << "Invalid input. Please try again." << endl << "Enter 1 to play another day, or enter 2 to exit the game." << endl;
 		cin >> choose;
	}
        
	if (choose == 1)
		return true;
	else if (choose == 2)
		return false;
}
