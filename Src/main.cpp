#include <algorithm>
#include <iostream>

#include "../Include/Database.hpp"
#include "../Include/Employee.hpp"
#include "../Include/Generator.hpp"
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

    Database db;

   // db.add(std::make_shared<Employee>(Bartek5));
        db.add(Adam);
//     db.generateRandomPeople(3);
//     db.generateSelectedProffesion(5,Proffesion::Employee);
      db.generateSelectedProffesion(10,Proffesion::Student);
         db.printDatabase();

//     db.modifyEarnings("53081891465",12000);
//    // db.modifyEarnings("95081685721",12000);
//    // db.printDatabase();

//     db.generateRandomPeople(20);
    
//     db.printDatabase();
//     db.loadDataFromFile();
//     db.saveDatabaseToFile();
//     db.printDatabase();
    
//     db.sortBySurname(Order::Ascending);


//     char zn{'1'};

//     std::cout<<zn<<"      "<<int(zn)<<"\n";
//     char zn1{'x'};

//     std::cout<<zn1<<"      "<<int(zn1)<<"\n";
    db.removeRange(3,1);
        db.printDatabase();

    return 0;
}