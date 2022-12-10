#include <string>
constexpr size_t peselLength{11};

enum class Month{January = 1,February,March,April,May,June,July,August,September,Octobet,November,December};

/*
January — styczeń, 
February — luty, 
March — marzec, 
April — kwiecień,
May — maj, 
June — czerwiec, 
July — lipiec, 
August — sierpień, 
September — wrzesień,
October — październik,
November — listopad, 
December — grudzień
*/


namespace PeselValidator{

    bool checkLength(const std::string& Pesel);
    bool checkLeapYear(const std::string& Pesel);
    bool checkDate(const std::string& Pesel);


}