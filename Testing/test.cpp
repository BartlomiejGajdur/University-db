
#include <memory>

#include "../Include/Student.hpp"
#include "../Include/Database.hpp"

#include "gtest/gtest.h"

TEST(CheckStructure, CanAddStudentToDb){
    Student adam{
        "Adam",
        "Kowalski",
        "Krakow 21",
        0,
        "000000000",
        Gender::Male
    };

    Database db;

    size_t sizeBeforeAdd = db.getVectorOfStudents().size();
    db.add(std::make_shared<Student>(adam));
    size_t sizeAfterAdd = db.getVectorOfStudents().size();

    EXPECT_EQ(sizeBeforeAdd,sizeAfterAdd-1);
}