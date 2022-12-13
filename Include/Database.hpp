#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"
#include "Person.hpp"

enum class Order {Ascending, Descending};

class Database{
    public:
        Database();
        Database(const std::vector<std::shared_ptr<Person>>& vectorOfPeople): vectorOfPeople_(vectorOfPeople){};
        

        //Getters
        std::vector<std::shared_ptr<Person>> getVectorOfPeople() const {return vectorOfPeople_;};


        //Functions
        void add(const std::shared_ptr<Person>& student);
        void printDatabase();
        std::vector<std::shared_ptr<Person>> findBySurname(const std::string& surname);
        std::shared_ptr<Person> findByPesel(const std::string& pesel);
        void sortBySurname(const Order& order);
        void sortByPesel(const Order& order);
        void removeByIndex(const size_t index);
    private:
        std::vector<std::shared_ptr<Person>> vectorOfPeople_;

};