#pragma once
#include <iostream>
#include <string>

int GetSelectionNumb(int from, int to, std::wstring& options)
{
    system("CLS"); // Clear Screen
    std::wcout << options;
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