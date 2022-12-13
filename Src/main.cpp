#include <algorithm>
#include <iostream>
#include "../Include/Database.hpp"
#include "../Include/Student.hpp"
#include "../Include/validatePesel.hpp"
#include "../Include/Person.hpp"
#include "../Include/Employee.hpp"
#include "../Include/Generator.hpp"

int main(){ 

    //  Student Adam{
    //     "Adam",
    //     "bowalski",
    //     "Krakow 21",
    //     "95081685721"   };

    // Student Kasia{
    //     "Kasia",
    //     "calkowski",
    //     "Krakow 21dd",
    //     "89032892537"
    // };

    // Student Bartek{
    //     "Kasia",
    //     "Malkowski",
    //     "Krakow 21dd",
    //     "05041681881"
    // };
    //  Student Adam1{
    //     "Adam",
    //     "bo3232walski",
    //     "Krakow 21",
    //     "53050719156"   };

    // Student Kasia1{
    //     "Kasia",
    //     "calkowski",
    //     "Krakow 21dd",
    //     "00111555121"
    // };

    // Employee Bartek1{
    //     "Krzysiek",
    //     "Osuch",
    //     "Krakow 21dd",
    //     "53081891465",
    //     5000
    // };

    // Employee Bartek2{
    //     "Krzysztof",
    //     "Gajdur",
    //     "Warszawa 21dd",
    //     "53081891465",
    //     7000
    // };

    // Employee Bartek3{
    //     "Karmowski",
    //     "Malkowski",
    //     "Warszawa 21dd",
    //     "53081891465",
    //     2400
    // };

    // Student Kasia5{
    //     "Dodane nowe",
    //     "calkowski",
    //     "Krakow 21dd",
    //     "00111555121"
    // };

    // Employee Bartek5{
    //     "Krzysiek",
    //     "Os323232uch",
    //     "Krakow 21dd",
    //     "53081891465",
    //     4444
    // };

    // Database db;

    // db.add(std::make_shared<Student>(Adam));
    // db.add(std::make_shared<Student>(Kasia));
    // db.add(std::make_shared<Employee>(Bartek2)); 
    // db.add(std::make_shared<Student>(Bartek)); 
    // db.add(std::make_shared<Student>(Adam1));
    // db.add(std::make_shared<Employee>(Bartek3)); 
    // db.add(std::make_shared<Student>(Kasia1));
    // db.add(std::make_shared<Employee>(Bartek1)); 
    // db.add(Bartek5);
    // db.add(Kasia5);

    // db.printDatabase();

    // // db.sortBySurname(Order::Ascending);
    // // db.printDatabase();

    // // db.sortBySurname(Order::Descending);
    // // db.printDatabase();

    // // std::cout<<"\n\n@@@@@\n\n";

    // //  db.sortByPesel(Order::Ascending);
    // // db.printDatabase();

    // // db.sortByPesel(Order::Descending);
    // // db.printDatabase();
    
    // // std::string Pesel{"92022919156"};
    // // if(PeselValidator::checkLeapYear(Pesel))
    // //     std::cout<<"IsLeap\n";

    // // if(PeselValidator::checkDate(Pesel))
    // //     std::cout<<"Dobra data\n";

    // // if(PeselValidator::checkDigit("55030101193"))
    // //     std::cout<<"ZGADZA SIE PESEL!\n";
    
    // // if(PeselValidator::checkDigit("55030101230"))
    // //     std::cout<<"Zgadza SIe pesel!\n";

    // // if(PeselValidator::validatePesel("62080697415"))
    // //     std::cout<<"ZGADZA SIE PESEL!\n";

    // // std::vector<std::shared_ptr<Person>> finnaly = db.findBySurname("Malkowski");
    // // //testy:
    // // for (auto vec : finnaly){
    // //     std::cout<<*vec<<"\n";
    // // }
    // // db.removeByIndex(1);
    // //  db.printDatabase();

    // db.saveDatabaseToFile("DatabaseOfStudents");
    
    //  std::cout<<*(db.findByPesel("0504123681881"));

   if(PeselValidator::validatePesel(generate::generatePesel())){
        std::cout<<"Jest super ten pesel!\n";
   }else{
        std::cout<<"ojjj\n";
   }

    return 0;
}