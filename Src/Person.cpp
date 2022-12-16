#include <iomanip>

#include "../Include/Person.hpp"

//Function shall convert Enum class Gender into string 
std::string Person::getGenderInString() const{

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

std::ostream& operator<<(std::ostream& os, const Person& person){

    person.print(os);
    return os;
}


//function shall set variable gender_ to appropriate value based on coded gender in Pesel
void Person::setGender(){

    int codedGender = int(pesel_[9])-48;
    
    if(codedGender % 2 == 0)
        gender_ = Gender::Female;
    else 
        gender_ = Gender::Male;
}

void Person::makeToUpper(){

    name_[0] = std::toupper(name_[0]);
    surname_[0] = std::toupper(surname_[0]);
}

void Person::setRandomData(){
    
    pesel_  = generate::generatePesel();
    name_   = generate::generateName(pesel_);
    surname_= generate::generateSurname();
    adress_ = generate::generateAdress();
}