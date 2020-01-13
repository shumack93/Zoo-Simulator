/***************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Header file to declare the Penguin class that will be
**               defined in the penguin.cpp file.
***************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

class Penguin: public Animal
{
	public:
		Penguin();
		Penguin(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1);
};

#endif
