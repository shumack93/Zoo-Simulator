/***************************************************************************
** Project Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Implementation file to define the constructors and
**               functions declared in the animal.hpp file.
***************************************************************************/

#include "animal.hpp"

Animal::Animal()
{
	age = 0;
	cost = 0;
	numberOfBabies = 0;
	baseFoodCost = 0;
	payoff = 0;
}

Animal::Animal(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1)
{
	age = age1;
	cost = cost1;
	numberOfBabies = numberOfBabies1;
	baseFoodCost = baseFoodCost1;
	payoff = payoff1;
}

int Animal::getAge()
{
	return age;
}

void Animal::setAge(int newAge)
{
	age = newAge;
}

int Animal::getCost()
{
	return cost;
}

void Animal::setCost(int newCost)
{
	cost = newCost;
}

int Animal::getBabies()
{
	return numberOfBabies;
}

void Animal::setBabies(int newBabies)
{
	numberOfBabies = newBabies;
}

int Animal::getFoodCost()
{
	return BASE_FOOD_COST;
}

void Animal::setFoodCost(int newFoodCost)
{
	baseFoodCost = newFoodCost;
}

int Animal::getPayoff()
{
	return payoff;
}

void Animal::setPayoff(int newPayoff)
{
	payoff = newPayoff;
}
