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
    std::cout<<adam;
    

    return 0;
}