/***************************************************************************
** Project Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         01/29/2019
** Description:  Header file to declare the Tiger class that will be
**               defined in the tiger.cpp file.
***************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

class Tiger: public Animal
{
        public:
		Tiger();
		Tiger(int age1, int cost1, int numberOfBabies1, int baseFoodCost1, int payoff1);
};

#endif
