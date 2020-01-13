/***************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Main function to run the zoo tycoon game.
**		 
***************************************************************************/

#include<iostream>
#include "continue.hpp"
#include "limitedInputValidation.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Zoo myZoo(100000);
	int begTigers = 0, begPenguins = 0, begTurtles = 0, dayCount = 1;
	bool keepPlaying;
	
	cout << endl << "Welcome to your new zoo!" << endl << "You have $100,000 to begin your zoo with. Let's buy some animals!" << endl;

	cout << endl << "Tigers cost $10,000 each. How many tigers would you like to purchase, 1 or 2? (Enter 1 or 2)" << endl;
	cin >> begTigers;
	limitedInputValidation(begTigers, 1, 2);

	cout << "Penguins cost $1,000 each. How many penguins would you like to purchase, 1 or 2? (Enter 1 or 2)" << endl;
	cin >> begPenguins;
	limitedInputValidation(begPenguins, 1, 2);
	
	cout << "Turtles cost $100 each. How many turtles would you like to purchase, 1 or 2? (Enter 1 or 2)" << endl;
	cin >> begTurtles;
	limitedInputValidation(begTurtles, 1, 2);

	//If statements that add the first animals to our arrays based
	//on use input above.
	if (begTigers == 1)
	{
		Tiger t1 (1, 10000, 0, BASE_FOOD_COST * 5, 2000);
		myZoo.addTiger(t1);
	}
	else
	{
		Tiger t1 (1, 10000, 0, BASE_FOOD_COST * 5, 2000);
		Tiger t2 (1, 10000, 0, BASE_FOOD_COST * 5, 2000);
		myZoo.addTiger(t1);
		myZoo.addTiger(t2);
	}

	if (begPenguins == 1)
	{
		Penguin p1 (1, 1000, 0, BASE_FOOD_COST, 100);
		myZoo.addPenguin(p1);
	}
	else
	{
		Penguin p1 (1, 1000, 0, BASE_FOOD_COST, 100);
		Penguin p2 (1, 1000, 0, BASE_FOOD_COST, 100);
		myZoo.addPenguin(p1);
		myZoo.addPenguin(p2);
	}

	if (begTurtles == 1)
	{
		Turtle tt1 (1, 100, 0, BASE_FOOD_COST * .5, 5);
		myZoo.addTurtle(tt1);
	}
	else
	{
		Turtle tt1 (1, 100, 0, BASE_FOOD_COST * .5, 5);
		Turtle tt2 (1, 100, 0, BASE_FOOD_COST * .5, 5);
		myZoo.addTurtle(tt1);
		myZoo.addTurtle(tt2);
	}

	cout << endl << "Congratulations! You are starting your zoo with " << begTigers << " tiger(s), " << begPenguins << " penguin(s), " << "and " << begTurtles << " turtle(s). You have $" << myZoo.getBankBalance() << " remaining." << endl << endl;

	//Start of the do-while loop that allows the user to continue playing the game after the end of each day.
	do
	{
		int choice1 = 0, choice2 = 0;

		cout << "---------------------" << endl << "Day " << dayCount << endl << "---------------------" << endl << endl;

		myZoo.increaseAge();
		myZoo.randomEvent();
		myZoo.calcProfit();
		myZoo.addProfit();

		cout << endl << "Total food cost for today: $" << myZoo.getTotalFoodCost() << endl;
		cout << "Your zoo made a profit today of: $" << myZoo.getProfit() << endl;
		cout << "Bank balance after profits/food expense: $" << myZoo.getBankBalance() << endl << endl;
		
		cout << "Would you like to buy one adult animal? Enter 1 for yes, or enter 2 for no." << endl;
		cin >> choice1;
		limitedInputValidation(choice1, 1, 2);

		//Gives the user the choice of animal to purchase if they selected 1 above.
		if (choice1 == 1)
		{
			cout << "What type of animal would you like to purchase? Enter 1 for a tiger, 2 for a penguin, or 3 for a turtle." << endl;
			cin >> choice2;
			limitedInputValidation(choice2, 1, 3);

			if (choice2 == 1)
			{
				Tiger t3(3, 10000, 0, BASE_FOOD_COST * 5, 2000);
				myZoo.addTiger(t3);
			}
			else if (choice2 == 2)
			{
				Penguin p3(3, 1000, 0, BASE_FOOD_COST, 100);
				myZoo.addPenguin(p3);
			}
			else if (choice2 == 3)
			{
				Turtle tt3(3, 100, 0, BASE_FOOD_COST * .5, 5);
				myZoo.addTurtle(tt3);
			}
		}
		else
		{
		}

		cout << endl << "End of Day Animal Count" << endl << "------------------------" << endl;
		cout << "Tiger count: " << myZoo.getNumberOfTigers() << endl;	
		cout << "Penguin count: " << myZoo.getNumberOfPenguins() << endl;	
		cout << "Turtle count: " << myZoo.getNumberOfTurtles() << endl << endl;	
		
		cout << "End of Day Bank Balance: $" << myZoo.getBankBalance() << endl << endl;
	
		//Resets profit to 0 and tiger payoff to $2,000 at the end of each day.
		myZoo.setProfit(0);
		myZoo.resetTigerPayoff();
	
		dayCount++;

		//Reruns the coninueGame() function that lets the user choose to keep playing or quit.
		keepPlaying = continueGame();
	}
	while (keepPlaying == true);

	return 0;
}
