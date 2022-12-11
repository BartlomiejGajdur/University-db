#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>


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

void Database::sortBySurname(const Order& order){
    switch(order){
        case Order::Ascending:
        std::sort(vectorOfStudents_.begin(),vectorOfStudents_.end(),[](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>& rhs)
                                                                    {return lhs->getSurname()<rhs->getSurname();});
        break;
        case Order::Descending:
        std::sort(vectorOfStudents_.begin(),vectorOfStudents_.end(),[](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>& rhs)
                                                                    {return lhs->getSurname()>rhs->getSurname();});
        break;
        default:
        std::cout<<"ERROR! Wrong Order";
        break;
    }
}

void Database::sortByPesel(const Order& order){

    int counter = std::count_if(vectorOfStudents_.begin(),vectorOfStudents_.end(),[](const std::shared_ptr<Student>& Student)
                                                                        { 
                                                                            return Student->getPesel()<="23";
                                                                            
                                                                        });

    switch(order){
        case Order::Ascending:
        std::sort(vectorOfStudents_.begin(),vectorOfStudents_.end(),[](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>& rhs)
                                                                    {return lhs->getPesel()<rhs->getPesel();});
        
        std::rotate(vectorOfStudents_.begin(),vectorOfStudents_.begin()+counter,vectorOfStudents_.end());

        break;
        case Order::Descending:
        std::sort(vectorOfStudents_.begin(),vectorOfStudents_.end(),[](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>& rhs)
                                                                    {return lhs->getPesel()>rhs->getPesel();});

        std::rotate(vectorOfStudents_.begin(),vectorOfStudents_.begin()+(vectorOfStudents_.size()-counter),vectorOfStudents_.end());
        break;
        default:
        std::cout<<"ERROR! Wrong Order Code";
        break;
    }
}

void Database::removeByIndex(const size_t index){

    vectorOfStudents_.erase(remove_if(vectorOfStudents_.begin(),vectorOfStudents_.end(),
                                                                                        [&index](const std::shared_ptr<Student>& lhs)
                                                                                        {return lhs->getIndex() == index;})
                                                                                        ,vectorOfStudents_.end());
}


std::stringstream Database::formatPrint(){
    std::stringstream stream;

    stream<<"-----------------------------------------DATABASE--------------------------------\n";
    stream<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(14)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"<<"\n";

    stream<<"_________________________________________________________________________________\n";
    std::for_each(vectorOfStudents_.begin(),vectorOfStudents_.end(),
                                                                        [&stream](const std::shared_ptr<Student>& student)
                                                                            {stream<<*student<<"\n";});
    stream<<"---------------------------------------------------------------------------------\n";

    return stream;
}

void Database::saveDatabaseToFile(const std::string& fileName){

    std::stringstream stream = formatPrint();
    std::string fileName_ = fileName;
    if(std::equal(fileName_.rbegin(),fileName_.rbegin()+4,"txt.")){
        fileName_ = "../"+fileName_;
    }else{
        fileName_ = "../"+fileName_ + ".txt";
    }
    
    std::fstream database(fileName_, database.out | database.trunc);

    if(database.is_open()){
        database<<stream.str();
        std::cout<<"Data saved corectlly! :)\n";
    }else
        std::cout<<"Data not saved! Error :(\n";
}