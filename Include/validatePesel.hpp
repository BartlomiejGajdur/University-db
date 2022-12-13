#pragma once
#include <string>
constexpr size_t peselLength{11};

enum class Month{January = 1,February,March,April,May,June,July,August,September,October,November,December};


namespace PeselValidator{

    bool checkLength(const std::string& Pesel);
    bool checkLeapYear(const std::string& Pesel);
    bool checkDate(const std::string& Pesel);
    bool checkDigit(const std::string& Pesel);
    
    
    bool validatePesel(const std::string& Pesel);

}