#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string>

#include "../Include/Menu.hpp"
#include "../Include/validatePesel.hpp"

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
    std::cout<<"> 0. EXIT\n";

}

void Menu::Menu_PrintDatabase(){
    db.printDatabase();
    system("PAUSE");
}

void Menu::Menu_LoadDatabaseFromFile(){

    size_t choice;
    std::string fileName;

    std::cout<<">1. Load Database from default file\n";
    std::cout<<">2. Load Database from given file name\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            db.loadDataFromFile();
            choice = 0;
            break;
        case 2:
            system("CLS");
            std::cout<<"Insert a fileName and press ENTER\n>";
            std::cin>>fileName;
            db.loadDataFromFile(fileName);
            choice = 0;
            break;
        case 0:
            
            break;
        
        default:
            break;
        }
    }
}

void Menu::Menu_SaveDatabaseToFile(){
    size_t choice;
    std::string fileName;

    std::cout<<">1. Save Database to default file\n";
    std::cout<<">2. Load Database to given file name\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            db.saveDatabaseToFile();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            std::cout<<"Insert a fileName and press ENTER\n>";
            std::cin>>fileName;
            db.saveConfiguration(fileName);
            system("PAUSE");
            choice = 0;
            break;
        case 0:
            
            break;
        
        default:
            break;
        }
    }
}

void Menu::Menu_GenerateRandomPeople(){
    size_t numOfPeople;
    std::cout<<"How many people generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateRandomPeople(numOfPeople);
}

void Menu::Menu_GenerateRandomStudents(){
    size_t numOfPeople;
    std::cout<<"How many students generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateSelectedProffesion(numOfPeople, Proffesion::Student);
}

void Menu::Menu_GenerateRandomEmployees(){
    size_t numOfPeople;
    std::cout<<"How many employees generate?\n>";
    std::cin>>numOfPeople;
    system("CLS");
    db.generateSelectedProffesion(numOfPeople,Proffesion::Employee);
}

void Menu::Menu_SortBySurname(){
    size_t choice=1;
   

    std::cout<<">1. Sort By surname -> ASCENDING\n";
    std::cout<<">2. Sort By surname -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortBySurname(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortBySurname(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }
}
void Menu::Menu_SortByPesel(){
    size_t choice=1;
   

    std::cout<<">1. Sort By Pesel -> ASCENDING\n";
    std::cout<<">2. Sort By Pesel -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortByPesel(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortByPesel(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }

}

void Menu::Menu_SortBySalary(){
    size_t choice=1;
   

    std::cout<<">1. Sort By Salary -> ASCENDING\n";
    std::cout<<">2. Sort By Salary -> DESCENDING\n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
            db.sortBySalary(Order::Ascending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 2:
            system("CLS");
            db.sortBySalary(Order::Descending);
            db.printDatabase();
            system("PAUSE");
            choice = 0;
            break;
        case 0:  
            break;
        default:
            break;
        }
    }
}

void Menu::Menu_FindBySurname(){
    system("CLS");
    std::vector<std::shared_ptr<Person>> peopleFound;
    std::string surname;
    std::cout<<">Insert a surname to find<\n>";
    std::cin>>surname;

    peopleFound=db.findBySurname(surname);

    if(peopleFound.size()==0){
        std::cout<<"No people found for given surname >"<<surname<<"<\n";
        system("PAUSE");
    }else{
        system("CLS");
        std::cout<<"----------------------------------------------DATABASE-------------------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(17)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    std::cout<<"_______________________________________________________________________________________________________\n";
        std::for_each(peopleFound.begin(),peopleFound.end(),[](std::shared_ptr<Person> people)
                                                                                        {std::cout<<*people<<"\n";});
        std::cout<<"-------------------------------------------------------------------------------------------------------\n";                                                                               
        system("PAUSE");
    }
}

void Menu::Menu_FindByPesel(){
    system("CLS");
    std::shared_ptr<Person> peopleFound;
    std::string Pesel;
    std::cout<<">Insert a Pesel to find<\n>";
    std::cin>>Pesel;

    peopleFound=db.findByPesel(Pesel);

    if(peopleFound == nullptr){
        std::cout<<"No people found for given Pesel >"<<Pesel<<"<\n";
        system("PAUSE");
    }else{
        system("CLS");
        std::cout<<"----------------------------------------------DATABASE-------------------------------------------------\n";
    std::cout<<std::setw(14)<<std::left<<"Name"
      <<std::setw(14)<<std::left<<"|Surname"
      <<std::setw(17)<<std::left<<" |Adress"
      <<std::setw(14)<<std::left<<"  |Index"
      <<std::setw(14)<<std::left<<"   |Pesel"
      <<std::setw(14)<<std::left<<"    |Gender"
      <<std::setw(14)<<std::left<<"     |Earnings"<<"\n";

    std::cout<<"_______________________________________________________________________________________________________\n";
        std::cout<<*peopleFound<<"\n";
        std::cout<<"-------------------------------------------------------------------------------------------------------\n";                                                                               
        system("PAUSE");
    }
}

void Menu::Menu_Add(){
    std::string name_,surname_,adress_,pesel_;
    size_t earnings_;
    bool ValidatePesel;

    size_t choice=1;
    char c;
   

    std::cout<<">1. Add student \n";
    std::cout<<">2. Add employee \n";
    std::cout<<">0. EXIT\n";
    

    while(choice!=0){
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;
        switch (choice)
        {
        case 1:
            system("CLS");
                std::cout<<"Name: ";
                std::cin>>name_;
                system("CLS");
                std::cout<<"Surame: ";
                std::cin>>surname_;
                system("CLS");
                std::cout<<"Adress: ";
                std::getline(std::cin, adress_);
                std::getline(std::cin, adress_);
                system("CLS");
            
            do{
                std::cout<<"Pesel: ";
                std::cin>>pesel_;
                ValidatePesel = PeselValidator::validatePesel(pesel_);

                if(PeselValidator::validatePesel(pesel_)==false){
                    system("CLS");
                    std::cout<<"You entered a incorrect pesel! Try again.\n";
                    std::cout<<"Do you want to try again? [Y] - yes | [N] - no\n>";
                    std::cin>>c;

                    switch (c)
                    {
                    case 'y':
                    case 'Y':
                        break;
                    case 'N':
                    case 'n':
                        ValidatePesel = true;
                        choice = 0;
                        break;
                    default:
                        std::cout<<"U Entered wrong char!\n";
                        ValidatePesel = true;
                        choice = 0;
                        system("PAUSE");
                        break;
                    }
                    
                }
            }while(!ValidatePesel);

            if(PeselValidator::validatePesel(pesel_)){
                db.add(std::make_shared<Student>(name_,surname_,adress_,pesel_));
                std::cout<<"Student saved correctly! :)\n";
                system("PAUSE");
                choice = 0;
            }else{
                choice = 0;
            }

            break;
            case 2:
                system("CLS");
                std::cout<<"Name: ";
                std::cin>>name_;
                system("CLS");
                std::cout<<"Surame: ";
                std::cin>>surname_;
                system("CLS");
                std::cout<<"Adress: ";
                std::getline(std::cin, adress_);
                std::getline(std::cin, adress_);
                system("CLS");
                std::cout<<"Earnings: ";
                std::cin>>earnings_;
                system("CLS");
                
                do{
                    std::cout<<"Pesel: ";
                    std::cin>>pesel_;
                    ValidatePesel = PeselValidator::validatePesel(pesel_);

                    if(PeselValidator::validatePesel(pesel_)==false){
                        system("CLS");
                        std::cout<<"You entered a incorrect pesel! Try again.\n";
                        std::cout<<"Do you want to try again? [Y] - yes | [N] - no\n>";
                        std::cin>>c;

                        switch (c)
                        {
                        case 'y':
                        case 'Y':
                            break;
                        case 'N':
                        case 'n':
                            ValidatePesel = true;
                            choice = 0;
                            break;
                        default:
                            std::cout<<"U Entered wrong char!\n";
                            ValidatePesel = true;
                            choice = 0;
                            system("PAUSE");
                            break;
                        }   
                    }
                 }while(!ValidatePesel);

                

                if(PeselValidator::validatePesel(pesel_)){
                    db.add(std::make_shared<Employee>(name_,surname_,adress_,pesel_,earnings_));
                    std::cout<<"Employee saved correctly! :)\n";
                    system("PAUSE");
                    choice = 0;
                }else{
                    choice = 0;
                }
                break;
                
    }

}
}

void Menu::Menu_ModifyEarnings(){
    std::string pesel_;
    size_t earnings_;
    system("cls");
    std::cout<<"For which pesel number to change earnings:\n>";
    std::cin>>pesel_;
    system("cls");
    std::cout<<"Set earnings to:\n>";
    std::cin>>earnings_;
    system("cls");
    db.modifyEarnings(pesel_,earnings_);
    system("PAUSE");

}  

void Menu::Menu_RemoveRangeOfPeople(){
    size_t lhs,rhs;
    size_t temp = db.getVectorOfPeople().size();

    system("cls");
    std::cout<<"Remove people from the range > ";
    std::cin>>lhs;
    std::cout<<" to > ";
    std::cin>>rhs;
    
    system("cls");
    db.removeRange(lhs,rhs);

    if(temp!=db.getVectorOfPeople().size()){
        system("cls");
        std::cout<<"Data removed corectlly! :) \n";
        system("PAUSE");
    }else{
        system("PAUSE");
    }
}        

void Menu::Menu_RemovePersonByIndex(){
    size_t index;
    std::cout<<"Insert index to remove:\n>";
    std::cin>>index;
    size_t temp = db.getVectorOfPeople().size();


    db.removeByIndex(index);

    if(temp!=db.getVectorOfPeople().size()){
        system("CLS");
        std::cout<<"Student removed corectlly! :)\n";
        system("PAUSE");
    }else{
        system("CLS");
        std::cout<<"Can not find a student with a given index! :(\n";
        system("PAUSE");
    }

}

void Menu::Menu_LoadSave(){

    std::vector<std::string> fileNames = db.getFIleNames();
    system("cls");

    if(fileNames.size() == 0){
        std::cout<<"You have no saved databases!\n";
        std::cout<<"Let me create new database for you :)\n";
        system("PAUSE");
    }else{
        showSavedFileName();
    }

}

void Menu::showSavedFileName(){

    std::vector<std::string> fileNames = db.getFIleNames();
    std::for_each(fileNames.begin(),fileNames.end(),[i{1}](const std::string& fileName) mutable
                                                                                            {
                                                                                                std::cout<<i++<<"> "<<fileName<<"\n";
                                                                                            });
    system("PAUSE");

}

void Menu::runMenu(){

    size_t choice;
    //tutaj odczyt z pliku i przypisanie do filename
    do{
        
        system("CLS");
        std::cout<<"1. Create new database\n";
        std::cout<<"2. Load Database\n";
        std::cout<<"0. EXIT\n";
        std::cout<<"\nInsert a number between 0 - 2\n>";
        std::cin>>choice;

        switch (choice)
        {
        case 1:
            system("cls");
            std::cout<<"New database created!\n";
            system("PAUSE");
            break;
        case 2:
            Menu_LoadSave();
            break;
        case 0:
            system("cls");
            std::cout<<"EXIT!\n";
            system("PAUSE");
            break;
        default:
            system("cls");
            std::cout<<"You entered a wrong char!\n";
            system("PAUSE");
            break;
        }
    }while(choice<0 || choice>2);
        

    //
   
    while(choice!=0){

        system("CLS");
        printMENU();
        std::cout<<"\nInsert a number between 0 - 15\n>";
        std::cin>>choice;
        system("CLS");
        
        switch (choice)
        {
        case 0:
            system("cls");
            std::cout<<"EXIT!\n";
            system("PAUSE");
            break;
        case 1:
            Menu_PrintDatabase();
            break;
        case 2:
            Menu_SaveDatabaseToFile();
            break;
        case 3:
            Menu_Add();
            break;
        case 4:
            Menu_GenerateRandomPeople();
            break;
        case 5:
            Menu_GenerateRandomStudents();
            break;
        case 6:
            Menu_GenerateRandomEmployees();
            break;
        case 7:
            Menu_LoadDatabaseFromFile();
            break;
        case 8:
            Menu_FindBySurname();
            break;
        case 9:
            Menu_FindByPesel();
            break;
        case 10:
            Menu_SortBySurname();
            break;
        case 11:
            Menu_SortByPesel();
            break;
        case 12:
            Menu_SortBySalary();
            break;
        case 13:
            Menu_ModifyEarnings();
            break;
        case 14:
            Menu_RemoveRangeOfPeople();
            break;
        case 15:
            Menu_RemovePersonByIndex();
            break;
        default:
            system("cls");
            std::cout<<"You entered a wrong char!\n";
            system("PAUSE");
            break;
        }



    }

}