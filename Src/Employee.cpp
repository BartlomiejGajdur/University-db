#include <iomanip>

#include "../Include/Employee.hpp"

void Employee::print(std::ostream& os) const{
     os<<std::setw(15)<<std::left<<name_
      <<std::setw(15)<<std::left<<surname_
      <<std::setw(15)<<std::left<<adress_
      <<std::setw(15)<<std::left<<index_
      <<std::setw(15)<<std::left<<pesel_
      <<std::setw(15)<<std::left<<this->getGenderInString()
      <<std::setw(15)<<std::left<<earnings_<<" PLN";
}
std::ostream& operator<<(std::ostream& os,  Employee& Employee){

    Employee.print(os);
    return os;
}

bool Employee::operator==(const Person& other){
        return this->name_ == other.getName() && this->surname_ == other.getSurname() &&
               this->adress_ == other.getAdress() &&
               this->pesel_ == other.getPesel() && this->gender_ == other.getGender();
    }

