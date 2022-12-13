#include "Person.hpp"

class Employee : public Person{
    public:
        Employee(const std::string& name,
                 const std::string& surname,
                 const std::string& adress,
                 const std::string& pesel,
                 const int& earnings) : 
                             Person(name,surname,adress,pesel), earnings_(earnings)
                            {
                                index_ = counter++;
                            }
        Employee(){};
        
    //Functions
    void print(std::ostream& os) const override;

    //Getters
    size_t getEarnings()       const {return earnings_;};
    
    //Operators 
    friend std::ostream& operator<<(std::ostream& os,  Employee& Employee);
    bool operator==(const Person& other) override;

    //Setters

    private:
        
        size_t index_;
        static size_t counter;
        int earnings_;

};
