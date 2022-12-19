#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Include/Menu.hpp"

void Menu::printMENU(){

    system("CLS");

    std::cout<<"> 1.  Print database\n";
    std::cout<<"> 2.  Save database to file\n";
    std::cout<<"> 3.  Add person\n";
    std::cout<<"> 4.  Generate random people\n";
    std::cout<<"> 5.  Generate random students\n";
    std::cout<<"> 6.  Generate random employees\n";
    std::cout<<"> 7.  Load people from file\n";
    std::cout<<"> 8.  Find person by surname\n";
    std::cout<<"> 9.  Find person by pesel\n";
    std::cout<<"> 10. Sort people by surname\n";
    std::cout<<"> 11. Sort people by pesel\n";
    std::cout<<"> 12. Sort people by salary\n";
    std::cout<<"> 13. Modify earings\n";
    std::cout<<"> 14. Remove range of people\n";
    std::cout<<"> 15. Remove person by index\n";
    std::cout<<"> 0. EXIT\n";

}

void Menu::Menu_PrintDatabase(){
    db.printDatabase();
    system("PAUSE");
}

void Menu::Menu_LoadDatabaseFromFile(){

    size_t choice;
    std::string fileName;

    std::cout<<">1. Load Database from default file\n";
    std::cout<<">2. Load Database from given file name\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            db.loadDataFromFile();
            choice = 0;
            break;
        case 2:
            system("CLS");
            std::cout<<"Insert a fileName and press ENTER\n>";
            std::cin>>fileName;
            db.loadDataFromFile(fileName);
            choice = 0;
            break;
        case 0:
            
            break;
        
        default:
            break;
        }
    }
}

void Menu::Menu_SaveDatabaseToFile(){
    size_t choice;
    std::string fileName;

    std::cout<<">1. Save Database to default file\n";
    std::cout<<">2. Load Database to given file name\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            db.saveDatabaseToFile();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            std::cout<<"Insert a fileName and press ENTER\n>";
            std::cin>>fileName;
            db.saveDatabaseToFile(fileName);
            system("PAUSE");
            choice = 0;
            break;
        case 0:
            
            break;
        
        default:
            break;
        }
    }
}

void Menu::Menu_GenerateRandomPeople(){
    size_t numOfPeople;
    std::cout<<"How many people generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateRandomPeople(numOfPeople);
}

void Menu::Menu_GenerateRandomStudents(){
    size_t numOfPeople;
    std::cout<<"How many students generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateSelectedProffesion(numOfPeople, Proffesion::Student);
}

void Menu::Menu_GenerateRandomEmployees(){
    size_t numOfPeople;
    std::cout<<"How many employees generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateSelectedProffesion(numOfPeople,Proffesion::Employee);
}

void Menu::Menu_SortBySurname(){
    size_t choice=1;
   

    std::cout<<">1. Sort By surname -> ASCENDING\n";
    std::cout<<">2. Sort By surname -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortBySurname(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortBySurname(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }
}
void Menu::Menu_SortByPesel(){
    size_t choice=1;
   

    std::cout<<">1. Sort By Pesel -> ASCENDING\n";
    std::cout<<">2. Sort By Pesel -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortByPesel(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortByPesel(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }

}

void Menu::Menu_SortBySalary(){
    size_t choice=1;
   

    std::cout<<">1. Sort By Salary -> ASCENDING\n";
    std::cout<<">2. Sort By Salary -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortBySalary(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortBySalary(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }
}


void Menu::runMenu(){

    size_t choice;
   
    while(choice!=0){

        system("CLS");
        printMENU();
        std::cout<<"\nInsert a number between 0 - 15\n>";
        std::cin>>choice;
        system("CLS");
        
        switch (choice)
        {
        case 1:
            Menu_PrintDatabase();
            break;
        case 2:
            Menu_SaveDatabaseToFile();
            break;
        case 4:
            Menu_GenerateRandomPeople();
            break;
        case 5:
            Menu_GenerateRandomStudents();
            break;
        case 6:
            Menu_GenerateRandomEmployees();
            break;
        case 7:
            Menu_LoadDatabaseFromFile();
            break;
        case 10:
            Menu_SortBySurname();
            break;
        case 11:
            Menu_SortByPesel();
            break;
        case 12:
            Menu_SortBySalary();
            break;
        default:
            break;
        }



    }

}