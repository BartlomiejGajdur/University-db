#include <algorithm>
#include <iostream>
#include <iomanip>
#include "../Include/Database.hpp"

Database::Database(){};

void Database::add(const std::shared_ptr<Person>& student){

    vectorOfPeople_.push_back(student);
}

void Database::printDatabase(){
    std::cout<<"-------------------------------------------------DATABASE-------------------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(14)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    std::cout<<"__________________________________________________________________________________________________________\n";
    std::for_each(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                        [](const std::shared_ptr<Person>& student)
                                                                            {std::cout<<*student<<"\n";});
    std::cout<<"----------------------------------------------------------------------------------------------------------\n";
}

std::vector<std::shared_ptr<Person>> Database::findBySurname(const std::string& surname){
    std::vector<std::shared_ptr<Person>> findCorrectSurname;
    std::for_each(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                    [&surname,&findCorrectSurname](std::shared_ptr<Person> person)
                                                                    {
                                                                        if(person->getSurname() == surname)
                                                                            findCorrectSurname.push_back(person);
                                                                    });
    return findCorrectSurname;
}

// Student Database::findByPesel(const std::string& pesel){
//     std::make_shared<Person>(foundStudent);
//     auto it = std::find_if(vectorOfPeople_.begin(),vectorOfPeople_.end(),[&pesel](std::shared_ptr<Person> Student){return Student->getPesel() == pesel; });
//     if(it!=vectorOfPeople_.end()){
//         foundStudent = **it;
//         return foundStudent;
//     }
//     return foundStudent;
// }

void Database::sortBySurname(const Order& order){
    switch(order){
        case Order::Ascending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getSurname()<rhs->getSurname();});
        break;
        case Order::Descending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getSurname()>rhs->getSurname();});
        break;
        default:
        std::cout<<"ERROR! Wrong Order";
        break;
    }
}

void Database::sortByPesel(const Order& order){

    int counter = std::count_if(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& Student)
                                                                        { 
                                                                            return Student->getPesel()<="23";
                                                                            
                                                                        });

    switch(order){
        case Order::Ascending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()<rhs->getPesel();});
        
        std::rotate(vectorOfPeople_.begin(),vectorOfPeople_.begin()+counter,vectorOfPeople_.end());

        break;
        case Order::Descending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()>rhs->getPesel();});

        std::rotate(vectorOfPeople_.begin(),vectorOfPeople_.begin()+(vectorOfPeople_.size()-counter),vectorOfPeople_.end());
        break;
        default:
        std::cout<<"ERROR! Wrong Order Code";
        break;
    }
}

void Database::removeByIndex(const size_t index){

    vectorOfPeople_.erase(remove_if(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                                        [&index](const std::shared_ptr<Person>& lhs)
                                                                                        {
                                                                                            return lhs->getIndex() == index;  
                                                                                        })
                                                                                        ,vectorOfPeople_.end());
}

