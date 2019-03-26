#include <iostream>
#include <memory>

#include "FileManager.h"
#include "InputManager.h"

struct FileManager::record;
std::vector<FileManager::record> FileManager::files;

std::ostream& operator<<(std::ostream& stream, const FileManager::record& other)
{
    stream << " Account Number: " << other.m_accountNumb << std::endl;
    stream << " First Name: " << other.m_firstName << std::endl;
    stream << " Last Name: " << other.m_lastName << std::endl;
    stream << " Account Balance: " << other.m_balance;
    return stream;
}

void FileManager::Debug()
{
    AddRecord( 128,  541.00f, "Gabo",      "Linso");
    AddRecord(  32,   12.73f, "Joe",       "Blow");
    AddRecord(  54, 1056.98f, "Jack",      "Black");
    AddRecord( 324,  354.29f, "Akwa",      "Fina");
}

void FileManager::ShowMainMenu()
{
    std::string text;
    text += "***Acount Information System***\n";
    text += "Records found: " + std::to_string(FileManager::GetRecordsCount()) + "\n";
    text += "Select one option below\n";
    text += "    1-->Add Record to file\n";
    text += "    2-->Show Record from file\n";
    text += "    3-->Search Record from file\n";
    text += "    4-->Update Record\n";
    text += "    5-->Delete Record\n";
    text += "    6-->Quit\n\n";
    text += "Enter your choice: ";
    FileManager::MainSelection(GetSelectionNumb(1, 6, text));
}

void FileManager::AddRecord()
{
    files.push_back(createNewRecord());
}

void FileManager::AddRecord(int accountNumb, float accountBalance, const char* firstName, const char* lastName)
{
    record newRecord(accountNumb, accountBalance, firstName, lastName);
    files.push_back(newRecord);
}

void FileManager::ShowRecord()
{
    std::cout << "Showing " << GetRecordsCount() << " Record(s)" << std::endl;
    for each (record rec in files)
    {
        std::cout << "===============================" << std::endl;
        std::cout << rec << std::endl;
    }
    std::cout << "===============================" << std::endl;
}

void FileManager::SearchRecord()
{
    std::string text;
    text += "***Acount Information System***\n";
    text += "Records found: " + std::to_string(FileManager::GetRecordsCount()) + "\n";
    text += "Select one option below\n";
    text += "    1-->Search by Account Number\n";
    text += "    2-->Search by Name\n";
    text += "    3-->Return to main menu\n\n";
    text += "Enter your choice: ";
    FileManager::searchSelection(GetSelectionNumb(1, 3, text));
}

void FileManager::UpdateRecord()
{

}

void FileManager::DeleteRecord()
{

}

FileManager::record FileManager::createNewRecord()
{
    record newRecord;
    newRecord.m_accountNumb = enterAccountNumb();
    newRecord.m_firstName   = setName("Enter First Name: ");
    newRecord.m_lastName    = setName("Enter Last Name: ");
    newRecord.m_balance     = setAccountBalance();
    return newRecord;
}

std::string FileManager::setName(const char* message)
{
    char nameBuffer[12];
    std::cout << message;
    std::cin >> nameBuffer;
    std::string name(nameBuffer);
    return name;
}


int FileManager::enterAccountNumb()
{
    int accountNumb;
    std::cout << "Enter Account Number: ";
    std::cin >> accountNumb;
    return accountNumb;
}

float FileManager::setAccountBalance()
{
    float accountBalance;
    std::cout << "Enter Account Balance: ";
    std::cin >> accountBalance;
    return accountBalance;
}

void FileManager::searchByAccountNumb()
{
    int accountNumb = enterAccountNumb();
    std::cout << std::endl;
    for each (auto rec in files)
        if (rec.m_accountNumb == accountNumb)
        {
            std::cout << rec << std::endl;
            return;
        }
    std::cout << "No Record Found with Account Number " << accountNumb << std::endl;
}

FileManager::record* FileManager::getRecord(int accountNumb)
{
    return nullptr;
}


void FileManager::searchByName()
{

}

void FileManager::MainSelection(int selection)
{
    std::cout << std::endl;
    switch (selection)
    {
    case 1:
        FileManager::AddRecord();
        break;
    case 2:
        FileManager::ShowRecord();
        system("pause");
        break;
    case 3:
        FileManager::SearchRecord();
        break;
    case 4:
        FileManager::UpdateRecord();
        break;
    case 5:
        FileManager::DeleteRecord();
        break;
    case 6:
        std::cout << "Goodbye." << std::endl;
        system("pause");
        FileManager::Quit = true;
    default:
        break;
    }
}

void FileManager::searchSelection(int selection)
{
    std::cout << std::endl;
    switch (selection)
    {
    case 1:
        FileManager::searchByAccountNumb();
        system("pause");
        break;
    case 2:
        FileManager::searchByName();
        break;
    case 3:
        FileManager::ShowMainMenu();
        break;
    default:
        break;
    }
    FileManager::SearchRecord();
}
