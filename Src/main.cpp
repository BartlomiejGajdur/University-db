#include <algorithm>
#include <iostream>
#include "../Include/Database.hpp"
#include "../Include/Student.hpp"
int main(){ 

     Student Adam{
        "Adam",
        "bowalski",
        "Krakow 21",
        0,
        "95081685721",
        Gender::Male
    };

    Student Kasia{
        "Kasia",
        "calkowski",
        "Krakow 21dd",
        0,
        "89032892537",
        Gender::Female
    };

    Student Bartek{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        0,
        "67041681881",
        Gender::Female
    };
     Student Adam1{
        "Adam",
        "bowalski",
        "Krakow 21",
        0,
        "53050719156",
        Gender::Male
    };

    Student Kasia1{
        "Kasia",
        "calkowski",
        "Krakow 21dd",
        0,
        "55111555121",
        Gender::Female
    };

    Student Bartek1{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        0,
        "53081891465",
        Gender::Female
    };

    Database db;

    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek)); 
    db.add(std::make_shared<Student>(Adam1));
    db.add(std::make_shared<Student>(Kasia1));
    db.add(std::make_shared<Student>(Bartek1)); 

    db.printDatabase();

    db.sortBySurname(Order::Ascending);
    db.printDatabase();

    db.sortBySurname(Order::Descending);
    db.printDatabase();

    std::cout<<"\n\n@@@@@\n\n";

     db.sortByPesel(Order::Ascending);
    db.printDatabase();

    db.sortByPesel(Order::Descending);
    db.printDatabase();


    return 0;
}