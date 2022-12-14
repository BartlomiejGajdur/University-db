#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>


#include "../Include/Database.hpp"

Database::Database(){};

void Database::add(const std::shared_ptr<Person>& person){

    vectorOfPeople_.push_back(person);
}

void Database::add(const Student& person){
             this->add(std::make_shared<Student>(person));
        }
        
void Database::add(const Employee& person){
        this->add(std::make_shared<Employee>(person));
        }

void Database::printDatabase(){
    std::cout<<"-------------------------------------------------DATABASE-------------------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(17)<<std::left<<" |Adress"
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

std::shared_ptr<Person> Database::findByPesel(const std::string& pesel){
    std::shared_ptr<Person> foundPerson;
    auto it = std::find_if(vectorOfPeople_.begin(),vectorOfPeople_.end(),[&pesel](std::shared_ptr<Person> Student){return Student->getPesel() == pesel; });
    if(it!=vectorOfPeople_.end()){
        foundPerson = *it;
        return foundPerson;
    }
    return nullptr;
}

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

// POPRAWIC
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


std::stringstream Database::formatPrint(){
    std::stringstream stream;

    stream<<"-------------------------------------------------DATABASE-------------------------------------------------\n";
    stream<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(18)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    stream<<"__________________________________________________________________________________________________________\n";
    std::for_each(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                        [&stream](const std::shared_ptr<Person>& student)
                                                                            {stream<<*student<<"\n";});
    stream<<"----------------------------------------------------------------------------------------------------------\n";

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

void Database::saveDatabaseToFile(){
    this->saveDatabaseToFile("DatabaseOfStudents");
}

void Database::generateRandomPeople(const size_t& numberOfPeopleToGenerate){

    int choice;
    for(int i = 0;i<numberOfPeopleToGenerate; i++){

        choice = generate::generateRandomNumber(1,2);
        std::string pesel  = generate::generatePesel();

        switch (choice)
        {
        case 1:
        vectorOfPeople_.push_back(std::make_shared<Student>(generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel));
            break;
        
        case 2:
        vectorOfPeople_.push_back(std::make_shared<Employee>(generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel,generate::generateEarnings()));
            break;
        
        default:
            std::cout<<"Something bad happened!\n\n";
            break;
        } 
    }
}

void Database::generateSelectedProffesion(const size_t& numberOfPeopleToGenerate, const Proffesion& proffesion){
    switch (proffesion)
    {
    case Proffesion::Student:
        for(int i = 0;i<numberOfPeopleToGenerate; i++){
            std::string pesel  = generate::generatePesel();
            vectorOfPeople_.push_back(std::make_shared<Student>(generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel));  
        }
        break;
    case Proffesion::Employee:
         for(int i = 0;i<numberOfPeopleToGenerate; i++){
            std::string pesel  = generate::generatePesel();
            vectorOfPeople_.push_back(std::make_shared<Employee>(generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel,generate::generateEarnings()));
         }
         break;
    
    default:
        std::cout<<"ERROR! Wronrg proffesion!\n";
        break;
    }
}