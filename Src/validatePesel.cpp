#include <iostream>

#include "../Include/validatePesel.hpp"

bool PeselValidator::checkLength(const std::string& Pesel){
    return Pesel.size() == peselLength;
}

//Function shall returns true if in given Pesel year is leap
bool PeselValidator::checkLeapYear(const std::string& Pesel){

    std::string yearSTRING{Pesel.begin(),Pesel.begin()+2};
    size_t yearINT;
    if(Pesel[2] == '3' || Pesel[2] == '2')
        yearINT = 2000 + std::stoi(yearSTRING);  
    else
        yearINT = 1900 + std::stoi(yearSTRING);

    return (yearINT % 4 == 0 && yearINT % 100 != 0) || 
           (yearINT % 4 == 0 && yearINT % 100 == 0 && yearINT % 400 == 0);
}

bool PeselValidator::checkDate(const std::string& Pesel){
    //Extract from given Pesel date in format [MMDD] -> M-Month | D-Day
    std::string month{Pesel.begin()+2,Pesel.begin()+4};
    std::string day{Pesel.begin()+4,Pesel.begin()+6};


    std::cout<<month<<" "<<day;

    return true;




}