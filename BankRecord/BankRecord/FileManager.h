#pragma once
#include <vector>
#include <string>
#include <memory>

class FileManager
{
public:
    // I want to keep the record private, but I couldn't figure out how to make the operator<< work :-/
    struct record
    {
        record() {};
        record(int accountNumb, float accountBalance, const char* firstName, const char* lastName)
            : m_accountNumb(accountNumb), m_balance(accountBalance), m_firstName(firstName), m_lastName(lastName) {};

        int m_accountNumb;
        float m_balance;
        std::string m_firstName;
        std::string m_lastName;
    };
    static bool Quit;
private:
    FileManager();
    static std::vector<record> files;
public:
    static void Debug();
    static void ShowMainMenu();
    static void AddRecord();
    static void ShowRecord();
    static void SearchRecord();
    static void UpdateRecord();
    static void DeleteRecord();
    static int  GetRecordsCount() {return files.size();}
    static void MainSelection(int);
    static void searchSelection(int);
private:
    static void AddRecord(int accountNumb, float accountBalance, const char* firstName, const char* lastName);
    static record createNewRecord();
    static std::string setName(const char* message);
    static int enterAccountNumb();
    static float setAccountBalance();
    static void searchByAccountNumb();
    static void searchByName();
    static FileManager::record* getRecord(int);
};
