#pragma once
#include <string>

enum class Gender {Male,Female};
//base class
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
                            }
        Person(){};
        
    //Getters
    std::string getName()   const {return name_;};
    std::string getSurname()const {return surname_;};
    std::string getAdress() const {return adress_;};
    std::string getPesel()  const {return pesel_;};
    Gender getGender()      const {return gender_;};
    std::string getGenderInString() const;

    virtual size_t getIndex()          const = 0;
    virtual void print(std::ostream& os) const = 0;

    //Operators 
    friend std::ostream& operator<<(std::ostream& os, const Person& Person);
    virtual bool operator==(const Person& other) = 0;

    //Setters
    void setGender();

    protected:
        std::string name_;
        std::string surname_;
        std::string adress_;
        std::string pesel_;
        Gender gender_;

};
