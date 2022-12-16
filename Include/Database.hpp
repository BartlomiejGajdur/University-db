#pragma once
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "Employee.hpp"
#include "Generator.hpp"
#include "Person.hpp"
#include "Student.hpp"

enum class Order {Ascending, Descending};

class Database{
    public:
        Database();
        Database(const std::vector<std::shared_ptr<Person>>& vectorOfPeople): vectorOfPeople_(vectorOfPeople){};
        
        //Getters
        std::vector<std::shared_ptr<Person>> getVectorOfPeople() const {return vectorOfPeople_;};

        //Functions
        void add(const std::shared_ptr<Person>& person);
        void add(const Student& person);
        void add(const Employee& person);

        void printDatabase();

        std::vector<std::shared_ptr<Person>> findBySurname(const std::string& surname);
        std::shared_ptr<Person> findByPesel(const std::string& pesel);
        void sortBySurname(const Order& order);
        void sortByPesel(const Order& order);
        void sortBySalary(const Order& order);
        void removeByIndex(const size_t index);
        void modifyEarnings(const std::string& pesel,const size_t& earnings);

        void saveDatabaseToFile(const std::string& fileName);
        void saveDatabaseToFile();

        void generateRandomPeople(const size_t& numberOfPeopleToGenerate);
        void generateSelectedProffesion(const size_t& numberOfPeopleToGenerate, const Proffesion& proffesion);
        

    private:
        std::vector<std::shared_ptr<Person>> vectorOfPeople_;

        std::stringstream formatPrint();
};