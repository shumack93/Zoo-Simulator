/*********************************************************************************
** Program Name: Project 2 - Zoo Tycoon
** Author:       Cris Shumack
** Date:         02/03/2019
** Description:  Implementation file that defines our limitedInputValidation 
**               function that was declared in limitedInputValidation.hpp.
*********************************************************************************/

#include "limitedInputValidation.hpp"

using std::cin;
using std::cout;
using std::endl;

void limitedInputValidation(int& input, int min, int max)
{
        while (input < min || input > max || cin.fail() || cin.get() != '\n')
        {
                cin.clear();
                cin.ignore(5000, '\n');

                cout << "Invalid input. Please try again." << endl;

                cin >> input;
        }
}
