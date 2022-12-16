#pragma once
#include "Person.hpp"

class Employee : public Person{
    public:
        Employee(const std::string& name,
                 const std::string& surname,
                 const std::string& adress,
                 const std::string& pesel,
                 const size_t& earnings) : 
                             Person(name,surname,adress,pesel)
                            {
                                earnings_ = earnings;
                            }
        Employee(){};
        
    //Functions
    void print(std::ostream& os) const override;

    //Getters
    size_t getIndex()    const override {return INT_MAX;};
    size_t getEarnings()    const override {return earnings_;};
    //Setters
    void setEarnings(const size_t& earnigns) override {earnings_ = earnigns;};
     
    //Operators 
    friend std::ostream& operator<<(std::ostream& os,  Employee& Employee);
    bool operator==(const Person& other) override;

    //Setters

    private:
        
        

};
