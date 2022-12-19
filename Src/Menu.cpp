#include <stdlib.h>
#include <iostream>

#include "../Include/Menu.hpp"


void Menu::printMENU(){

    system("CLS");

    std::cout<<"> 1.  Print database\n";
    std::cout<<"> 2.  Save database to file\n";
    std::cout<<"> 3.  Add person\n";
    std::cout<<"> 4.  Generate random people\n";
    std::cout<<"> 5.  Generate random students\n";
    std::cout<<"> 6.  Generate random employees\n";
    std::cout<<"> 7.  Load people from file\n";
    std::cout<<"> 8.  Find person by surname\n";
    std::cout<<"> 9.  Find person by pesel\n";
    std::cout<<"> 10. Sort people by surname\n";
    std::cout<<"> 11. Sort people by pesel\n";
    std::cout<<"> 12. Sort people by salary\n";
    std::cout<<"> 13. Modify earings\n";
    std::cout<<"> 14. Remove range of people\n";
    std::cout<<"> 15. Remove person by index\n";

}