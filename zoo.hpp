/***************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Header file to declare the Zoo class that will be
**               defined in the zoo.cpp file.
***************************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include<iostream>
#include<cstdlib>
#include<ctime>
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

class Zoo
{
	private:
		Tiger* arrayOfTigers;
		Penguin* arrayOfPenguins;
		Turtle* arrayOfTurtles;
		Tiger* babyTiger;
		Penguin* babyPenguin;
		Turtle* babyTurtle;
		int bankBalance;
		int profit;
		int numberOfTigers;
		int numberOfPenguins;
		int numberOfTurtles;
		int tigerSpace;
		int penguinSpace;
		int turtleSpace;

	public:
		Zoo();
		~Zoo();
		Zoo(int startingBalance);
		Tiger* getTiger();
		Penguin* getPenguin();
		Turtle* getTurtle();
		void addTiger(Tiger tiger1);
		void addPenguin(Penguin penguin1);
		void addTurtle(Turtle turtle1);
		bool removeTiger();
		bool removePenguin();
		bool removeTurtle();
		void randomEvent();
		int getBankBalance();
		void setBankBalance(int newBalance);
		int getProfit();
		void setProfit(int reset);
		void calcProfit();
		void addProfit();
		void increaseAge();
		void resetTigerPayoff();
		int getNumberOfTigers();
		int getNumberOfPenguins();
		int getNumberOfTurtles();
		void totalFoodCost();
		int getTotalFoodCost();
		bool findAdultTurtle();
		bool findAdultPenguin();
		bool findAdultTiger();
};

#endif
