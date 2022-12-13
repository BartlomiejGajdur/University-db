#include <ostream>
#include <string>
#include <iomanip>

#include "../Include/Student.hpp"


size_t Student::counter = 0;
void Student::print(std::ostream& os) const{
     os<<std::setw(15)<<std::left<<name_
      <<std::setw(15)<<std::left<<surname_
      <<std::setw(15)<<std::left<<adress_
      <<std::setw(15)<<std::left<<index_
      <<std::setw(15)<<std::left<<pesel_
      <<std::setw(15)<<std::left<<this->getGenderInString()
      <<std::setw(15)<<std::left<<"-N/N-";
}
std::ostream& operator<<(std::ostream& os,  Student& student){

    student.print(os);

    return os;
}

bool Student::operator==(const Person& other){
        return this->name_ == other.getName() && this->surname_ == other.getSurname() &&
               this->adress_ == other.getAdress() &&
               this->pesel_ == other.getPesel() && this->gender_ == other.getGender();
    }

