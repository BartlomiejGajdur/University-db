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

std::vector<Student> Database::findBySurname(const std::string& surname){
    std::vector<Student> findCorrectSurname;
    std::for_each(vectorOfStudents_.begin(),vectorOfStudents_.end(),
                                                                    [&surname,&findCorrectSurname](std::shared_ptr<Student> student)
                                                                    {
                                                                        if(student->getSurname() == surname)
                                                                            findCorrectSurname.push_back(*student);
                                                                    });
    return findCorrectSurname;
}

Student Database::findByPesel(const std::string& pesel){
    Student foundStudent{};
    auto it = std::find_if(vectorOfStudents_.begin(),vectorOfStudents_.end(),[&pesel](std::shared_ptr<Student> Student){return Student->getPesel() == pesel; });
    if(it!=vectorOfStudents_.end()){
        foundStudent = **it;
        return foundStudent;
    }
    return foundStudent;
}