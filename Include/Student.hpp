#pragma once
#include <ostream>
#include <string>

enum class Gender {Male,Female};

class Student{
    public:
        Student(const std::string& name,
                 const std::string& surname,
                 const std::string& adress,
                 const size_t& index,
                 const std::string& pesel,
                 Gender gender) : name_(name),
                             surname_(surname),
                             adress_(adress),
                             index_(index),
                             pesel_(pesel),
                             gender_(gender) {}
        
    //Getters
    std::string getName()   const {return name_;};
    std::string getSurname()const {return surname_;};
    std::string getAdress() const {return adress_;};
    size_t getIndex()       const {return index_;};
    std::string getPesel()  const {return pesel_;};
    Gender getGender()      const {return gender_;};
    std::string getGenderInString() const;

    //Operators 
    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    bool operator==(const Student& other);

    private:
        std::string name_;
        std::string surname_;
        std::string adress_;
        size_t index_;
        std::string pesel_;
        Gender gender_;

};

