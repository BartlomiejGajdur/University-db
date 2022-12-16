#pragma once
#include <string>

#include "Generator.hpp"

enum class Gender {Male,Female};

class Person{
    public:
        Person(const std::string& name,
                 const std::string& surname,
                 const std::string& adress,
                 const std::string& pesel) : 
                             name_(name),
                             surname_(surname),
                             adress_(adress),
                             pesel_(pesel)
                            {
                                setGender();
                                makeToUpper();
                            }
        Person(){};
        
    //Getters
    std::string getName()   const {return name_;};
    std::string getSurname()const {return surname_;};
    std::string getAdress() const {return adress_;};
    std::string getPesel()  const {return pesel_;};
    Gender getGender()      const {return gender_;};
    std::string getGenderInString() const;
    

    //Setters
    void setName    (const std::string& name) {name_ = name;};
    void setSurname (const std::string& surname) {surname_ = surname;};
    void setPesel   (const std::string& pesel) {pesel_ = pesel;};
    void setAdress  (const std::string& adress) {adress_ = adress;};
    void setGender();
    void setRandomData();

    //Operators 
    friend std::ostream& operator<<(std::ostream& os, const Person& Person);
    virtual bool operator==(const Person& other) = 0;

    //Virtual Functions 
    virtual size_t getEarnings()         const = 0;
    virtual size_t getIndex()            const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void setEarnings(const size_t& earnigns) = 0;

    protected:
        std::string name_;
        std::string surname_;
        std::string adress_;
        std::string pesel_;
        Gender gender_;
        size_t earnings_;

        void makeToUpper();
};
