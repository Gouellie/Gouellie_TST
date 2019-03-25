#include <iostream>
#include "FileManager.h"

// https://www.codewithc.com/banking-record-system-project-c/

bool FileManager::Quit = false;

int main()
{
    FileManager::Debug();
    while (!FileManager::Quit)
    {
        FileManager::ShowMainMenu();
    }
    std::cout << "Goodbye." << std::endl;
    system("pause");
    return 0;
}