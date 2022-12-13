#pragma once
#include <ostream>
#include <string>
#include <iostream>
#include "../Include/Person.hpp"

class Student : public Person{
    public:
        Student(const std::string& name,
                 const std::string& surname,
                 const std::string& adress,
                 const std::string& pesel) : 
                             Person(name,surname,adress,pesel)
                            {
                                index_ = counter++;
                            }
        Student(){};
        
    //Functions
    void print(std::ostream& os) const override;

    //Getters
    size_t getIndex()       const {return index_;};
    
    //Operators 
    friend std::ostream& operator<<(std::ostream& os,  Student& student);
    bool operator==(const Person& other) override;

    //Setters

    private:
        
        size_t index_;
        static size_t counter;

};

