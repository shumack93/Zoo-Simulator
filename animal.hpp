/***************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Header file to declare the Animal class that will be
**               defined in the animal.cpp file.
***************************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define BASE_FOOD_COST 100

class Animal
{
	protected: 
		int age, cost, numberOfBabies, baseFoodCost, payoff;

	public:
		Animal();
		Animal(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1);
		virtual int getAge();
		virtual void setAge(int newAge);
		virtual int getCost();
		virtual void setCost(int newCost);
		virtual int getBabies();
		virtual void setBabies(int newBabies);
		virtual int getFoodCost();
		virtual void setFoodCost(int newFoodCost);
		virtual int getPayoff();
		virtual void setPayoff(int newPayoff);
};

#endif
