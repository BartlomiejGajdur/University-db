#include <iostream>
#include "../Include/Database.hpp"
#include "../Include/Student.hpp"
int main(){ 

    Student adam{
        "Adam",
        "Kowalski",
        "Krakow 21",
        0,
        "000000000",
        Gender::Male
    };

    Student adam1{
        "Adaddm",
        "Kowalskdddi",
        "Krakow 21dd",
        0,
        "000011000",
        Gender::Female
    };

    Student adam2{
        "Adamaa",
        "Kowal",
        "Markowska 21",
        0,
        "000220000",
        Gender::Male
    };
    Database db;

    db.add(std::make_shared<Student>(adam));
    db.add(std::make_shared<Student>(adam1));
    db.add(std::make_shared<Student>(adam2));

    db.printDatabase();

    return 0;
}