#pragma once
#include <iostream>
#include <ostream>
#include <string>

#include "../Include/Person.hpp"

class Student : public Person
{
public:
    Student(const std::string &name,
            const std::string &surname,
            const std::string &adress,
            const std::string &pesel) : Person(name, surname, adress, pesel)
    {
        index_ = counter++;
        earnings_ = 0;
    }
    Student(){};

    // Getters
    size_t getIndex() const override { return index_; };
    size_t getEarnings() const override { return 0; };

    // Setters
    void setEarnings(const size_t &earnigns) override { std::cout << "ERROR! Cannot modify student earnings!\n"; };

    // Functions
    void print(std::ostream &os) const override;

    // Operators
    friend std::ostream &operator<<(std::ostream &os, Student &student);
    bool operator==(const Person &other) override;

private:
    size_t index_;
    static size_t counter;
};
