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

//Function shall returns true if the given data extraced from Pesel is correct
bool PeselValidator::checkDate(const std::string& Pesel){
    //Extract from given Pesel date  M-Month | D-Day
    std::string month{Pesel.begin()+2,Pesel.begin()+4};
    std::string day{Pesel.begin()+4,Pesel.begin()+6};

    Month ENUMmonth = static_cast<Month>(std::stoi(month) % 20);


    return ((ENUMmonth == Month::January  ||
            ENUMmonth == Month::March    ||
            ENUMmonth == Month::May      ||
            ENUMmonth == Month::July     ||
            ENUMmonth == Month::August   ||
            ENUMmonth == Month::October  ||
            ENUMmonth == Month::December) && day <="31") ||
            ((ENUMmonth == Month::April   ||
            ENUMmonth == Month::June      ||
            ENUMmonth == Month::September ||
            ENUMmonth == Month::November)  && day <="30") ||
            (checkLeapYear(Pesel) && ENUMmonth == Month::February && day<="29") ||
            (!checkLeapYear(Pesel) && ENUMmonth == Month::February && day<="28");
}