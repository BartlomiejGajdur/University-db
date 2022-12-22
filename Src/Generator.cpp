#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

#include "../Include/Generator.hpp"
#include "../Include/Validate.hpp"

std::array<std::string,40> femaleName_{"Joanna","Zofia","Aleksandra","Monika","Teresa","Danuta","Natalia","Karolina","Marta","Beata",
                                        "Julia","Dorota","Janina","Jadwiga","alina","Jolanta","Irena","Alicja","Grazyna","Iwona","Paulina",
                                        "Justyna","Bozena","Zuzanna","Urszula","Wiktoria","Renata","Helena","Sylwia","Agata","Hanna","Patrycja",
                                        "Izabela","Maja","Aneta","Emilia","Weronika","Ewelina","Marianna","Oliwia"}; 

std::array<std::string,40> maleName_{"Adam","Marcel","Stanislaw","Michal","Wiktor","Leon","Piotr","Nikodem","Igor","Ignacy","Tymon","Milosz",
                                        "Maksymilian","Oliwier","Tymoteusz","Mateusz","Bartosz","Alan","Oskar","Dawid","Krzysztof","Julian","Tomasz",
                                        "Karol","Dominik","Maciej","Gabriel","Hubert","Fabian","Natan","Pawel","Kamil","Ksawery","Bruno","Bartlomiej",
                                        "Patryk","Borys","Kajeta","Artur","Adrian"};    

std::array<std::string,10> surname_{"Nowak","Kowalski","Wisniewski","Wojcik","Kowalczyk","Kaminski","Lewandowski","Zielinski","Szymanski","Wozniak"};                   

std::array<std::string,10> postCode_{"21-233","62-200","34-250","62-700","62-826","66-211","69-999","12-340","41-321","77-151"};

std::array<std::string,10> cities_ ={"Warszawa","Krakow","Szczecin","Lodz","Wroclaw","Mistrzejow","Gdansk","Poznan","Sopot","Torun"};

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

    //Generate Month
    month = std::to_string(generate::generateRandomNumber(1,32)); // tu dac na 1
    
    while(std::stoi(month)>12 && std::stoi(month)<20){
        month = std::to_string(generate::generateRandomNumber(1,32));
    }
    if(month.size() == 1){
        month+="0";
        reverse(month.begin(),month.end());
    }
    
    //Generate year
    if(std::stoi(month)>=20){
        year = std::to_string(generate::generateRandomNumber(0,23));
        if(year.size() == 1)
        {
            year+="0";
            reverse(year.begin(),year.end());
        }

    }else{
         year = std::to_string(generate::generateRandomNumber(0,99));
        if(year.size() == 1)
        {
            year+="0";
            reverse(year.begin(),year.end());
        }
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

std::string generate::generateName(const std::string& pesel){

    if((int(pesel[9])-48) % 2 == 0)
        return femaleName_[generate::generateRandomNumber(0,39)];
    else return maleName_[generate::generateRandomNumber(0,39)];
}

std::string generate::generateSurname(){

        return surname_[generate::generateRandomNumber(0,9)];
}

std::string generate::generateAdress(){

        return cities_[generate::generateRandomNumber(0,9)] + " " + postCode_[generate::generateRandomNumber(0,9)];
}

int generate::generateEarnings(){

        return (generate::generateRandomNumber(2600,9000) / 100)*100;
}