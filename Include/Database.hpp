#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"

enum class Order {Ascending, Descending};

class Database{
    public:
        Database();
        Database(const std::vector<std::shared_ptr<Student>>& vectorOfStudents): vectorOfStudents_(vectorOfStudents){};
        

        //Getters
        std::vector<std::shared_ptr<Student>> getVectorOfStudents() const {return vectorOfStudents_;};


        //Functions
        void add(const std::shared_ptr<Student>& student);
        void printDatabase();
        std::vector<Student> findBySurname(const std::string& surname);
        Student findByPesel(const std::string& pesel);
        void sortBySurname(const Order& order);
        void sortByPesel(const Order& order);
        void removeByIndex(const size_t index);
    private:
        std::vector<std::shared_ptr<Student>> vectorOfStudents_;

};