#include <algorithm>
#include <iostream>
#include <iomanip>
#include "../Include/Database.hpp"

Database::Database(){};

void Database::add(const std::shared_ptr<Student>& student){

    vectorOfStudents_.push_back(student);
}

void Database::printDatabase(){
    std::cout<<"-----------------------------------------DATABASE-----------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(14)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"<<"\n";

    std::cout<<"__________________________________________________________________________________________\n";
    std::for_each(vectorOfStudents_.begin(),vectorOfStudents_.end(),
                                                                        [](const std::shared_ptr<Student>& student)
                                                                            {std::cout<<*student<<"\n";});
    std::cout<<"------------------------------------------------------------------------------------------\n";
}