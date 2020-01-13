/***************************************************************************
** Project Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Header file to declare the Turtle class that will be
**               defined in the turtle.cpp file.
***************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

class Turtle: public Animal
{
        public:
		Turtle();
		Turtle(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1);
};

#endif
