/***************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Implementation file to define the constructors and
**               functions declared in the turtle.hpp file.
***************************************************************************/

#include "animal.hpp"
#include "turtle.hpp"

Turtle::Turtle()
{
	age = 0;
	cost = 0;
	numberOfBabies = 0;
	baseFoodCost = 0;
	payoff = 0;
}

Turtle::Turtle(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1)
{
	age = age1;
	cost = cost1;
	numberOfBabies = numberOfBabies1;
	baseFoodCost = baseFoodCost1;
	payoff = payoff1;
}
