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
        "000000000",
        Gender::Male
    };

    Student Kasia{
        "Kasia",
        "calkowski",
        "Krakow 21dd",
        0,
        "000011000",
        Gender::Female
    };

    Student Bartek{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        0,
        "000011000",
        Gender::Female
    };

    Database db;

    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek)); 

    db.printDatabase();

    db.sortBySurname(Order::Ascending);
    db.printDatabase();

    db.sortBySurname(Order::Descending);
    db.printDatabase();


    return 0;
}