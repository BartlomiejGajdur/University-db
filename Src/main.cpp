#include <algorithm>
#include <iostream>

#include "../Include/Database.hpp"
#include "../Include/Employee.hpp"
#include "../Include/Generator.hpp"
#include "../Include/Menu.hpp"
#include "../Include/Person.hpp"
#include "../Include/Student.hpp"
#include "../Include/validatePesel.hpp"

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


    //@@@MENU@@@
    Menu m;
    m.printMENU();
    return 0;
}