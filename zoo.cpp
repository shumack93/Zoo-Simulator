/***************************************************************************
** Project Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Implementation file to define the Zoo class that was
**               declared in the zoo.hpp file.
***************************************************************************/

#include "zoo.hpp"

using std::cout;
using std::cin;
using std::endl;

Zoo::Zoo()
{
	bankBalance = 100000;
	profit = 0;
	numberOfTigers = 0;
	numberOfPenguins = 0;
	numberOfTurtles = 0;
	tigerSpace = 10;
	penguinSpace = 10;
	turtleSpace = 10;

	arrayOfTigers = new Tiger[tigerSpace];
	arrayOfPenguins = new Penguin[penguinSpace];
	arrayOfTurtles = new Turtle[turtleSpace];
}

Zoo::Zoo(int startingBalance)
{
	bankBalance = startingBalance;
	profit = 0;
	numberOfTigers = 0;
	numberOfPenguins = 0;
	numberOfTurtles = 0;
	tigerSpace = 10;
	penguinSpace = 10;
	turtleSpace = 10;

	arrayOfTigers = new Tiger[tigerSpace];
	arrayOfPenguins = new Penguin[penguinSpace];
	arrayOfTurtles = new Turtle[turtleSpace];
}

//Checks to see if number of tigers is equal to current array capacity.
//If it is, the function doubles the size of the array, then adds a tiger.
//If not, it just adds a tiger, adds one to the tiger count, and deducts the cost.
void Zoo::addTiger(Tiger newTiger)
{
	if (numberOfTigers == tigerSpace)
	{
		Tiger* newTigerArray = new Tiger[2 * tigerSpace];
	
		for (int i = 0; i < tigerSpace; i++)
			newTigerArray[i] = arrayOfTigers[i];
	
		delete[] arrayOfTigers;

		tigerSpace = 2 * tigerSpace;

		arrayOfTigers = newTigerArray;
	}

	arrayOfTigers[numberOfTigers] = newTiger;

	numberOfTigers++;

	bankBalance = bankBalance - newTiger.getCost();
}

//Checks to see if number of penguins is equal to current array capacity.
//If it is, the function doubles the size of the array, then adds a penguin.
//If not, it just adds a penguin, adds one to the penguin count, and deducts the cost.
void Zoo::addPenguin(Penguin newPenguin)
{
	if (numberOfPenguins == penguinSpace)
	{
		Penguin* newPenguinArray = new Penguin[2 * penguinSpace];
	
		for (int i = 0; i < penguinSpace; i++)
			newPenguinArray[i] = arrayOfPenguins[i];
	
		delete[] arrayOfPenguins;

		penguinSpace = 2 * penguinSpace;

		arrayOfPenguins = newPenguinArray;
	}

	arrayOfPenguins[numberOfPenguins] = newPenguin;

	numberOfPenguins++;

	bankBalance = bankBalance - newPenguin.getCost();
}

//Checks to see if number of turtles is equal to current array capacity.
//If it is, the function doubles the size of the array, then adds a turtle.
//If not, it just adds a turtle, adds one to the turtle count, and deducts the cost.
void Zoo::addTurtle(Turtle newTurtle)
{
	if (numberOfTurtles == turtleSpace)
	{
		Turtle* newTurtleArray = new Turtle[2 * turtleSpace];
	
		for (int i = 0; i < turtleSpace; i++)
			newTurtleArray[i] = arrayOfTurtles[i];
	
		delete[] arrayOfTurtles;

		turtleSpace = 2 * turtleSpace;

		arrayOfTurtles = newTurtleArray;
	}

	arrayOfTurtles[numberOfTurtles] = newTurtle;

	numberOfTurtles++;

	bankBalance = bankBalance - newTurtle.getCost();
}

//Function removes a tiger as long as there is one to remove.
bool Zoo::removeTiger()
{
	if (numberOfTigers == 0)
		return false;
	else
	{
		cout << "A tiger has been removed from your zoo." << endl;

		numberOfTigers--;

		return true;
	}
}

//Function removes a penguin as long as there is one to remove.
bool Zoo::removePenguin()
{
	if (numberOfPenguins == 0)
		return false;
	else
	{
		cout << "A penguin has been removed from your zoo." << endl;

		numberOfPenguins--;

		return true;
	}
}

//Function removes a turtle as long as there is one to remove.
bool Zoo::removeTurtle()
{
	if (numberOfTurtles == 0)
		return false;
	else
	{
		cout << "A turtle has been removed from your zoo." << endl;

		numberOfTurtles--;

		return true;
	}
}

//Cycles through the array of tigers. If the getAge function returns 3 or more,
//this function returns true. If none return 3 or more, it returns false.
bool Zoo::findAdultTiger()
{
	bool adultTiger = false;

	for (int i = 0; i < numberOfTigers; i++)
	{
		if (arrayOfTigers[i].getAge() >= 3)
		{
			arrayOfTigers[i].setBabies(arrayOfTigers[i].getBabies() + 1);

			adultTiger = true;
		}
	}
	
	return adultTiger;
}

//Cycles through the array of penguins. If the getAge function returns 3 or more,
//this function returns true. If none return 3 or more, it returns false.
bool Zoo::findAdultPenguin()
{
	bool adultPenguin = false;

	for (int i = 0; i < numberOfPenguins; i++)
	{
		if (arrayOfPenguins[i].getAge() >= 3)
		{
			arrayOfPenguins[i].setBabies(arrayOfPenguins[i].getBabies() + 1);

			adultPenguin = true;
		}
	}
	
	return adultPenguin;
}

//Cycles through the array of turtles. If the getAge function returns 3 or more,
//this function returns true. If none return 3 or more, it returns false.
bool Zoo::findAdultTurtle()
{
	bool adultTurtle = false;

	for (int i = 0; i < numberOfTurtles; i++)
	{
		if (arrayOfTurtles[i].getAge() >= 3)
		{
			arrayOfTurtles[i].setBabies(arrayOfTurtles[i].getBabies() + 1);

			adultTurtle = true;
		}
	}
	
	return adultTurtle;
}

//Function generates one of four random events using the rand() function.
void Zoo::randomEvent()
{
	//To ensure the rand() function generates something different each time.
	srand(time(NULL));
	
	int event, animalType;
	Tiger babyTiger(0, 0, 0, BASE_FOOD_COST * 5, 2000);
	Penguin babyPenguin(0, 0, 0, BASE_FOOD_COST, 100);
	Turtle babyTurtle(0, 0, 0, BASE_FOOD_COST * .5, 5);

	event = rand() % 4 + 1;

	//If this random event is selected, a random number is generated (1-3) to determine
	//which type of animal gets sick. It then checks to see if there is an animal of
	//that type to die. If not, it moves to the next type of animal.
	if (event == 1)
	{
		bool remove;
		
		cout << "Random Event: A sickness has occurred and one of your animals has died." << endl;

		animalType = rand() % 3 + 1;

		if (animalType == 1)
		{
			remove = removeTiger();

			if (!remove)
				remove = removeTurtle();

			if (!remove)
				remove = removePenguin();
		}
		else if (animalType == 2)
		{
			remove = removePenguin();

			if (!remove)
				remove = removeTiger();

			if (!remove)
				remove = removeTurtle();
		}
		else if (animalType == 3)
		{
			remove = removeTurtle();

			if (!remove)
				remove = removePenguin();

			if (!remove)
				remove = removeTurtle();
		}

		if (!remove)
			cout << "Random Event: Your zoo has no animals for the sickness to kill." << endl;
	}
	//If this random event is generated, the function generates a random amount between 250 and 500
	//for each tiger in the array and adds it to the payoff.
	else if (event == 2)
	{
		int tigerBonus;

		cout << "Random Event: There was a boom in zoo attendance today!" << endl;

		for (int i = 0; i < numberOfTigers; i++)
		{
			srand(time(NULL));
			tigerBonus = rand() % 251 + 250;

			arrayOfTigers[i].setPayoff(arrayOfTigers[i].getPayoff() + tigerBonus);
		}
	}
	//If this random event is generated, a random number (1-3) is generated to determine which
	//type of animal will have a baby. It uses the findAdult() functions to determine if there
	//is an animal of that type old enough to have a baby. If there is, a baby is added to the
	//correct array via the addAnimal() functions and the cost is added back to the bank since
	//it was born, not purchased.
	else if (event == 3)
	{
		bool addBabyTiger, addBabyPenguin, addBabyTurtle;

		animalType = rand() % 3 + 1;
		
		if (animalType == 1)
		{
			addBabyTiger = findAdultTiger();
		
			//If the findAdultTiger() function returns true, a message is printed and
			//a baby tiger is added to the array of tigers.
			if (addBabyTiger)
			{
				cout << "Random Event: A baby tiger was born!" << endl;

				addTiger(babyTiger);

				bankBalance = bankBalance + 10000;
			}
			else
				cout << "Random Event: None of your tigers can have babies." << endl;
		}
		else if (animalType == 2)
		{
			addBabyPenguin = findAdultPenguin();
		
			if (addBabyPenguin)
			{
				cout << "Random Event: 5 baby penguins were born!" << endl;

				for (int i = 0; i < 5; i++)
				{
					addPenguin(babyPenguin);

					bankBalance = bankBalance + 1000;
				}
			}
			else
				cout << "Random Event: None of your penguins can have babies." << endl;
		}
		else if (animalType == 3)
		{
			addBabyTurtle = findAdultTurtle();
		
			if (addBabyTurtle)
			{
				cout << "Random Event: 10 baby turtles were born!" << endl;

				for (int i = 0; i < 10; i++)
				{
					addTurtle(babyTurtle);

					bankBalance = bankBalance + 100;
				}
			}
			else
				cout << "Random Event: None of your turtles can have babies." << endl;
		}
	}
	else if (event == 4)
	{
		cout << "Random Event: Nothing special happened today." << endl;
	}
}

int Zoo::getBankBalance()
{
	return bankBalance;
}

void Zoo::setBankBalance(int money)
{
	bankBalance = money;
}

int Zoo::getProfit()
{
	return profit;
}

void Zoo::setProfit(int reset)
{
	profit = reset;
}

//Calculates total profit by cycling through each animal array and adding
//the payoff amount.
void Zoo::calcProfit()
{
	for (int i = 0; i < numberOfTigers; i++)
		profit = profit + arrayOfTigers[i].getPayoff();
	
	for (int i = 0; i < numberOfPenguins; i++)
		profit = profit + arrayOfPenguins[i].getPayoff();
	
	for (int i = 0; i < numberOfTurtles; i++)
		profit = profit + arrayOfTurtles[i].getPayoff();
}

//Adds the total profit back to the bank balance.
void Zoo::addProfit()
{
	bankBalance = bankBalance + profit;
}

//Cycles through each space of each animal array and adds one to the age. Also
//deducts food cost for each animal from the bank balance.
void Zoo::increaseAge()
{
	for (int i = 0; i < numberOfTigers; i++)
	{
		arrayOfTigers[i].setAge(arrayOfTigers[i].getAge() + 1);
	}
	
	for (int i = 0; i < numberOfPenguins; i++)
	{
		arrayOfPenguins[i].setAge(arrayOfPenguins[i].getAge() + 1);
	}
	
	for (int i = 0; i < numberOfTurtles; i++)
	{
		arrayOfTurtles[i].setAge(arrayOfTurtles[i].getAge() + 1);
	}
	
	bankBalance = bankBalance - ((numberOfTigers * BASE_FOOD_COST * 5) + (numberOfPenguins * BASE_FOOD_COST) + (numberOfTurtles * BASE_FOOD_COST * .5));
}

int Zoo::getNumberOfTigers()
{
	return numberOfTigers;
}

int Zoo::getNumberOfPenguins()
{
	return numberOfPenguins;
}

int Zoo::getNumberOfTurtles()
{
	return numberOfTurtles;
}

//Resets the tiger payoff to $2,000 (20% of cost) after the attendance boom event.
void Zoo::resetTigerPayoff()
{
	for (int i = 0; i < numberOfTigers; i++)
		arrayOfTigers[i].setPayoff(2000);
}

int Zoo::getTotalFoodCost()
{
	int totalFoodCost = (numberOfTigers * BASE_FOOD_COST * 5) + (numberOfPenguins * BASE_FOOD_COST) + (numberOfTurtles * BASE_FOOD_COST * .5);

	return totalFoodCost;
}

//Free memory allocated for animal arrays.
Zoo::~Zoo()
{
	delete[] arrayOfTigers;
	delete[] arrayOfPenguins;
	delete[] arrayOfTurtles;
}
