#include <iostream>
#include "../Include/Database.hpp"
#include "../Include/Student.hpp"
int main(){ 

     Student Adam{
        "Adam",
        "Kowalski",
        "Krakow 21",
        0,
        "000000000",
        Gender::Male
    };

    Student Kasia{
        "Kasia",
        "Malkowski",
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

    // Database db;

    // db.add(std::make_shared<Student>(Adam));
    // db.add(std::make_shared<Student>(Kasia));
    // db.add(std::make_shared<Student>(Bartek)); 

    // db.printDatabase();

    std::vector<Student> expected{Kasia,Bartek};
    std::vector<Student> value{Kasia,Bartek};
    // std::vector<std::shared_ptr<Student>> expected{std::make_shared<Student>(Kasia),std::make_shared<Student>(Bartek)};
    // std::vector<std::shared_ptr<Student>> value{std::make_shared<Student>(Kasia),std::make_shared<Student>(Bartek)};
    if(std::equal(expected.begin(),expected.end(),value.begin())){
        std::cout<< "jea";
    }else std::cout<< "noo";
    return 0;
}