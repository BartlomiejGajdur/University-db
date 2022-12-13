#include <array>
#include <random>

namespace generate{

std::array<std::string,40> femaleName_{"Joanna","Zofia","Aleksandra","Monika","Teresa","Danuta","Natalia","Karolina","Marta","Beata",
                                        "Julia","Dorota","Janina","Jadwiga","alina","Jolanta","Irena","Alicja","Grażyna","Iwona","Paulina",
                                        "Justyna","Bożena","Zuzanna","Urszula","Wiktoria","Renata","Helena","Sylwia","Agata","Hanna","Patrycja",
                                        "Izabela","Maja","Aneta","Emilia","Weronika","Ewelina","Marianna","Oliwia"}; 

std::array<std::string,40> maleName_{"Adam","Marcel","Stanislaw","Michal","Wiktor","Leon","Piotr","Nikodem","Igor","Ignacy","Tymon","Milosz",
                                        "Maksymilian","Oliwier","Tymoteusz","Mateusz","Bartosz","Alan","Oskar","Dawid","Krzysztof","Julian","Tomasz",
                                        "Karol","Dominik","Maciej","Gabriel","Hubert","Fabian","Natan","Paweł","Kamil","Ksawery","Bruno","Bartlomiej",
                                        "Patryk","Borys","Kajeta","Artur","Adrian"};                           

std::array<std::string,10> cities_{"Warszawa","Krakow","Szczecin","Lodz","Wrocław","Zielona Gora","Gdańsk","Poznań","Swinoujwcie","Dabrowa Gornicza"};

std::array<std::string,10> postCode_{"21-233","62-200","34-250","62-700","62-826","66-211","69-999","12-340","41-321","77-151"};


std::string generatePesel();

}