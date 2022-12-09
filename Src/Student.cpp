#include <ostream>
#include <string>
#include <iomanip>

#include "../Include/Student.hpp"

std::string Student::getGenderInString() const{
    switch(gender_){
        case Gender::Male:
            return "Male";
            break;
        case Gender::Female:
            return "Female";
            break;
        default:
            return "ERROR->Wrong Gender given";
    }
}

std::ostream& operator<<(std::ostream& os, const Student& student){

    os<<std::setw(15)<<std::left<<student.getName()
      <<std::setw(15)<<std::left<<student.getSurname()
      <<std::setw(15)<<std::left<<student.getAdress()
      <<std::setw(15)<<std::left<<student.getIndex()
      <<std::setw(15)<<std::left<<student.getPesel()
      <<std::setw(15)<<std::left<<student.getGenderInString();

    return os;
}

bool Student::operator==(const Student& other){
        return this->name_ == other.getName() && this->surname_ == other.getSurname() &&
               this->adress_ == other.getAdress() && this->index_ == other.getIndex() &&
               this->pesel_ == other.getPesel() && this->gender_ == other.getGender();
    }