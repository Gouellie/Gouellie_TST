#include <iostream>
#include <string>

#include "InputManager.h"

int GetSelectionNumb(int from, int to, std::string& options)
{
    system("CLS"); // Clear Screen
    std::cout << options;
    int number;
    std::cin >> number;
    if (number < from || number > to)
    {
        std::cout << "Please enter a number between " << from << " and " << to << std::endl;
        system("pause");
        number = GetSelectionNumb(from, to, options);
    }
    return number;
}