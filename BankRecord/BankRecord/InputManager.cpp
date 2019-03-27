#include <iostream>
#include <string>
#include <limits>

#include "InputManager.h"

int GetSelectionNumb(int from, int to, std::string& options)
{
    int number;
    bool badInput;
    do
    {
        system("CLS"); // Clear Screen
        std::cout << options;
        if (!std::cin) // Handling 'fail' state caused by undesired characters.
        {
            std::cin.clear();
            std::cin.ignore();
        }
        std::cin >> number;
        badInput = (number < from || number > to);
        if (badInput)
        {
            std::cout << "Please enter a number between " << from << " and " << to << std::endl;
            system("pause");
        }
    } while (badInput);
    return number;
}