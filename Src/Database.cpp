#include "../Include/Database.hpp"

Database::Database(){};

void Database::add(const std::shared_ptr<Student>& student){

    vectorOfStudents_.push_back(student);
}