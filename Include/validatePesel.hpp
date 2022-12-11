#include <string>
constexpr size_t peselLength{11};

enum class Month{January = 1,February,March,April,May,June,July,August,September,October,November,December};

/*
January — styczeń, 31
February — luty,  28/29
March — marzec,  31
April — kwiecień, 30
May — maj,        31
June — czerwiec,  30
July — lipiec,     31
August — sierpień,  31
September — wrzesień, 30
October — październik, 31
November — listopad, 30
December — grudzień 31
*/


namespace PeselValidator{

    bool checkLength(const std::string& Pesel);
    bool checkLeapYear(const std::string& Pesel);
    bool checkDate(const std::string& Pesel);


}