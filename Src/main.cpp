#include <algorithm>
#include <iostream>

#include "../Include/Database.hpp"
#include "../Include/Employee.hpp"
#include "../Include/Generator.hpp"
#include "../Include/Menu.hpp"
#include "../Include/Person.hpp"
#include "../Include/Student.hpp"
#include "../Include/validatePesel.hpp"

int countLetters(std::string& adress){
    auto it = std::count_if(adress.begin(),adress.end(),[](char zn){
                                                                return !std::isdigit(zn);
                                                                    });
    adress.insert(adress.begin()+(--it),' ');
    return it;
}

int main(){ 

     Student Adam{
        "Adam",
        "bowalski",
        "Krakow 44-129",
        "95081685721"   
        };


    Employee Bartek5{
        "Krzysiek",
        "Oszucinski",
        "Krakow 66-123",
        "53081891465",
        4800
    };
    //Load config -> pobiera z pliku config.txt odpowiednia date czyli do vectora w sb przypisuje dobre wartosic plikow 
//     Database db;
//     std::string a{"Configuracja1"};
//     db.generateRandomPeople(5);
//     db.saveConfiguration(a);
//     db.printDatabase();
//     db.clearVectorOfPeople();
//     db.loadDataFromFile("DatabaseOfStudentsINPUT");
//    // db.loadDataFromFile("config/Configuracja1");
//     db.generateRandomPeople(5);
//     db.saveDatabaseToFile("DatabaseOfStudentsOUTPUT");
//     db.printDatabase();

    // db.printDatabase();
    //@@@MENU@@@
    Menu m;
    m.runMenu();


    // std::string a{"Wroclaw66-211"};

    // std::cout<<a<<" ->"<<countLetters(a)<<"\n";
    // std::cout<<a;


    return 0;
}