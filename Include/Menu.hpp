#include "Database.hpp"

class Menu{

public:
    Menu(){};
    void runMenu();

private:

    Database db;

    void printMENU();
    void Menu_PrintDatabase();
    void Menu_LoadDatabaseFromFile();
    void Menu_SaveDatabaseToFile();
    void Menu_GenerateRandomPeople();
    void Menu_GenerateRandomStudents();
    void Menu_GenerateRandomEmployees();
    void Menu_SortBySurname();
    void Menu_SortByPesel();
    void Menu_SortBySalary();

};