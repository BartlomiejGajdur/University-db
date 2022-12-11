#include <algorithm>
#include <iostream>
#include "../Include/Database.hpp"
#include "../Include/Student.hpp"
#include "../Include/validatePesel.hpp"

int main(){ 

     Student Adam{
        "Adam",
        "bowalski",
        "Krakow 21",
        "95081685721"   };

    Student Kasia{
        "Kasia",
        "calkowski",
        "Krakow 21dd",
        "89032892537"
    };

    Student Bartek{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        "05041681881"
    };
     Student Adam1{
        "Adam",
        "bowalski",
        "Krakow 21",
        "53050719156"   };

    Student Kasia1{
        "Kasia",
        "calkowski",
        "Krakow 21dd",
        "00111555121"
    };

    Student Bartek1{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        "53081891465"
    };

    Database db;

    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek)); 
    db.add(std::make_shared<Student>(Adam1));
    db.add(std::make_shared<Student>(Kasia1));
    db.add(std::make_shared<Student>(Bartek1)); 

    db.printDatabase();

    // db.sortBySurname(Order::Ascending);
    // db.printDatabase();

    // db.sortBySurname(Order::Descending);
    // db.printDatabase();

    // std::cout<<"\n\n@@@@@\n\n";

    //  db.sortByPesel(Order::Ascending);
    // db.printDatabase();

    // db.sortByPesel(Order::Descending);
    // db.printDatabase();
    // std::cout<<"\n\nREMOVING@@@@@@@@@@@@@@@@@@@n\n";
    // db.removeByIndex(2);
    // db.removeByIndex(5);
    // db.removeByIndex(8);
    // db.printDatabase();
    std::string Pesel{"92022919156"};
    if(PeselValidator::checkLeapYear(Pesel))
        std::cout<<"IsLeap\n";

    if(PeselValidator::checkDate(Pesel))
        std::cout<<"Dobra data\n";
    return 0;
}