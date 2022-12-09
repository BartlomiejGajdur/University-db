#pragma once
#include <memory>
#include <string>
#include <vector>

#include "Student.hpp"

class Database{
    public:
        Database();
        

        //Getters
        std::vector<std::shared_ptr<Student>> getVectorOfStudents() const {return vectorOfStudents_;};


        //Functions
        void add(const std::shared_ptr<Student>& student);
        void printDatabase();
        std::vector<Student> findBySurname(const std::string& surname);


    private:
        std::vector<std::shared_ptr<Student>> vectorOfStudents_;

};