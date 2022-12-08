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
        


    private:
        std::string name_;
        std::string surname_;
        std::string adress_;
        size_t index_;
        std::string pesel_;
        Gender gender_;

};