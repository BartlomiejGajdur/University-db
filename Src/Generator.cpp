#include <algorithm>
#include <numeric>
#include <iostream>
#include <vector>
#include "../Include/Generator.hpp"
#include "../Include/validatePesel.hpp"

int generate::generateRandomNumber(const int& first, const int& second){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> random(first,second);

    return random(gen);
}

std::string generate::generateDay(const std::string& yearAndMonth){

    std::string day;

    Month ENUMmonth = static_cast<Month>(std::stoi(yearAndMonth) % 20);
    
    if((ENUMmonth == Month::January      ||
            ENUMmonth == Month::March    ||
            ENUMmonth == Month::May      ||
            ENUMmonth == Month::July     ||
            ENUMmonth == Month::August   ||
            ENUMmonth == Month::October  ||
            ENUMmonth == Month::December))
            {
                day = std::to_string(generate::generateRandomNumber(0,31));
                    if(day.size() == 1)
                    {
                        day+="0";
                        reverse(day.begin(),day.end());
                    }
            }

    
    if((ENUMmonth == Month::April         ||
            ENUMmonth == Month::June      ||
            ENUMmonth == Month::September ||
            ENUMmonth == Month::November))
            {
                day = std::to_string(generate::generateRandomNumber(0,30));
                    if(day.size() == 1)
                    {
                        day+="0";
                        reverse(day.begin(),day.end());
                    }
            }

    if(PeselValidator::checkLeapYear(yearAndMonth) && ENUMmonth == Month::February) {
                day = std::to_string(generate::generateRandomNumber(0,29));
                    if(day.size() == 1)
                    {
                        day+="0";
                        reverse(day.begin(),day.end());
                    }
            }

    if(!PeselValidator::checkLeapYear(yearAndMonth) && ENUMmonth == Month::February){
                day = std::to_string(generate::generateRandomNumber(0,28));
                    if(day.size() == 1)
                    {
                        day+="0";
                        reverse(day.begin(),day.end());
                    }
                }

    return day;
}


std::string generate::generatePesel(){
    std::string year,month,day,digits,pesel;
    int controlDigit;

    //Generate year
    year = std::to_string(generate::generateRandomNumber(0,99));
    if(year.size() == 1)
        year+=std::to_string(generate::generateRandomNumber(0,9));

    //Generate Month
    month = std::to_string(generate::generateRandomNumber(1,32));

    while(month>="13" && month<="20"){
        month = std::to_string(generate::generateRandomNumber(1,32));
    }
    if(month.size() == 1){
        month+="0";
        reverse(month.begin(),month.end());
    }

    //Generate day
    day = generate::generateDay(year+month);
        
    //Generate 4 digits
    for(int i =0 ; i<4 ;i++){
        digits+=std::to_string(generate::generateRandomNumber(0,9));
    }

    //Generate controlDigit
    std::vector<int> wages{1,3,7,9,1,3,7,9,1,3};
    pesel = year + month + day + digits;
    auto Operation = [](const int& wage, char zn){
      return wage * (int(zn)-48);
    };

    controlDigit = std::transform_reduce(wages.begin(),wages.end(),pesel.begin(),0,std::plus<>(),Operation);
    controlDigit = controlDigit % 10;
    if(controlDigit != 0)
        controlDigit=10-controlDigit;

    return pesel + std::to_string(controlDigit);
}