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
    AddRecord( 128,  541.00f, "Guillaume", "Ouellet");
    AddRecord(  32,   12.73f, "Joe",       "Blow");
    AddRecord(  54, 1056.98f, "Jack",      "Black");
    AddRecord( 324,  354.29f, "Akwa",      "Fina");
}

void FileManager::ShowMainMenu()
{
    std::wstring text;
    text += L"***Acount Information System***\n";
    text += L"Records found: " + std::to_wstring(FileManager::GetRecordsCount()) + L"\n";
    text += L"Select one option below\n";
    text += L"    1-->Add Record to file\n";
    text += L"    2-->Show Record from file\n";
    text += L"    3-->Search Record from file\n";
    text += L"    4-->Update Record\n";
    text += L"    5-->Delete Record\n";
    text += L"    6-->Quit\n\n";
    text += L"Enter your choice: ";
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
    std::wstring text;
    text += L"***Acount Information System***\n";
    text += L"Records found: " + std::to_wstring(FileManager::GetRecordsCount()) + L"\n";
    text += L"Select one option below\n";
    text += L"    1-->Search by Account Number\n";
    text += L"    2-->Search by Name\n";
    text += L"    3-->Return to main menu\n\n";
    text += L"Enter your choice: ";
    FileManager::SearchSelection(GetSelectionNumb(1, 3, text));
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
    newRecord.m_accountNumb = setAccountNumb();
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


int FileManager::setAccountNumb()
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
        FileManager::Quit = true;
    default:
        break;
    }
}

void FileManager::SearchSelection(int selection)
{
    std::cout << std::endl;
    switch (selection)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        FileManager::ShowMainMenu();
        break;
    default:
        break;
    }
}
