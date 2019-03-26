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
    return 0;
}