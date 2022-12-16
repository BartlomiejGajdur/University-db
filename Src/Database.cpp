#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <memory>


#include "../Include/Database.hpp"
#include "../Include/ValidatePesel.hpp"

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

    std::cout<<"----------------------------------------------DATABASE-------------------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(17)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    std::cout<<"_______________________________________________________________________________________________________\n";
    std::for_each(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                        [](const std::shared_ptr<Person>& student)
                                                                            {std::cout<<*student<<"\n";});
    std::cout<<"-------------------------------------------------------------------------------------------------------\n";
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

void Database::sortBySalary(const Order& order){

    switch(order){
        case Order::Ascending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getEarnings()<rhs->getEarnings();});
        break;
        case Order::Descending:
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getEarnings()>rhs->getEarnings();});
        break;
        default:
        std::cout<<"ERROR! Wrong Order";
        break;
    }
}


void Database::sortByPesel(const Order& order){

    std::string month;
  

    auto it = std::partition(vectorOfPeople_.begin(),vectorOfPeople_.end(),[&month](const std::shared_ptr<Person>& person)
                                                                    {   
                                                                        month= person->getPesel()[2];
                                                                        month+= person->getPesel()[3];
                                                                        return std::stoi(month) >=20;   
                                                                    });
    
    int distance = std::distance(vectorOfPeople_.begin(),it);
    int Counter = vectorOfPeople_.size()-distance;
    
    switch(order){
        case Order::Ascending:
            
        std::rotate(vectorOfPeople_.begin(),vectorOfPeople_.begin()+distance,vectorOfPeople_.end());
        
        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.begin()+Counter,[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()<rhs->getPesel();});
        
        std::sort(vectorOfPeople_.begin()+Counter,vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()<rhs->getPesel();});
        
       

        break;
        case Order::Descending:

        std::sort(vectorOfPeople_.begin(),vectorOfPeople_.begin()+distance,[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()>rhs->getPesel();});
        
        std::sort(vectorOfPeople_.begin()+distance,vectorOfPeople_.end(),[](const std::shared_ptr<Person>& lhs, const std::shared_ptr<Person>& rhs)
                                                                    {return lhs->getPesel()>rhs->getPesel();});

        
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

    stream<<"----------------------------------------------DATABASE-------------------------------------------------\n";
    stream<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(18)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    stream<<"_______________________________________________________________________________________________________\n";
    std::for_each(vectorOfPeople_.begin(),vectorOfPeople_.end(),
                                                                        [&stream](const std::shared_ptr<Person>& student)
                                                                            {stream<<*student<<"\n";});
    stream<<"-------------------------------------------------------------------------------------------------------\n";

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
    std::string pesel;
    for(int i = 0;i<numberOfPeopleToGenerate; i++){

        choice = generate::generateRandomNumber(1,2);
        do{
            pesel  = generate::generatePesel();
        }while(!PeselValidator::validatePesel(pesel));

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

    std::string pesel ="00000000000";

    for(int i = 0;i<numberOfPeopleToGenerate; i++){
        do{
            pesel  = generate::generatePesel();
        }while(!PeselValidator::validatePesel(pesel));
        
        switch (proffesion)
        {
        case Proffesion::Student:
                vectorOfPeople_.push_back(std::make_shared<Student>(generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel));         
            break;
        case Proffesion::Employee:
                vectorOfPeople_.push_back(std::make_shared<Employee>
                                        (generate::generateName(pesel),generate::generateSurname(),generate::generateAdress(),pesel,generate::generateEarnings()));
            break;
        
        default:
            std::cout<<"ERROR! Wronrg proffesion!\n";
            break;
        }
    }
}

void Database::modifyEarnings(const std::string& pesel,const size_t& earnings){

    std::shared_ptr<Person> person = this->findByPesel(pesel);
    if(person != nullptr){
        person->setEarnings(earnings);
    }else{
        std::cout<<"Cannot find the person by the given pesel!\n";
    }
    
}