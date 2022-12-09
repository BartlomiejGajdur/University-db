
#include <memory>
#include <vector>

#include "../Include/Student.hpp"
#include "../Include/Database.hpp"

#include "gtest/gtest.h"

struct DatabaseUnderTestFixture : public ::testing::Test{
    Database db;
    Student Adam{
        "Adam",
        "Kowalski",
        "Krakow 21",
        0,
        "000000000",
        Gender::Male
    };

    Student Kasia{
        "Kasia",
        "Malkowski",
        "Krakow 21dd",
        0,
        "000011000",
        Gender::Female
    };

    Student Bartek{
        "Bartek",
        "Malkowski",
        "Markowska 21",
        0,
        "000220000",
        Gender::Male
    };
 
};

TEST_F(DatabaseUnderTestFixture, CanAddStudentToDb){
    
    size_t sizeBeforeAdd = db.getVectorOfStudents().size();
    db.add(std::make_shared<Student>(Adam));
    size_t sizeAfterAdd = db.getVectorOfStudents().size();

    EXPECT_EQ(sizeBeforeAdd,sizeAfterAdd-1);
}

TEST_F(DatabaseUnderTestFixture, FindBySurname){
    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek));  

    std::vector<Student> expected{Kasia,Bartek};
    std::vector<Student> findBySurname = db.findBySurname("Malkowski");

    ASSERT_TRUE(std::equal(findBySurname.begin(),findBySurname.end(),expected.begin()));
}

TEST_F(DatabaseUnderTestFixture, FindByPesel_INCLUDE){
    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek)); 

    Student expected{Bartek};
    Student findByPesel = db.findByPesel("000220000");

    ASSERT_TRUE(expected == findByPesel);
}

TEST_F(DatabaseUnderTestFixture, FindByPesel_NOT_INCLUDE){
    db.add(std::make_shared<Student>(Adam));
    db.add(std::make_shared<Student>(Kasia));
    db.add(std::make_shared<Student>(Bartek)); 

    Student expected{Bartek};
    Student findByPesel = db.findByPesel("00022000011111111");

    ASSERT_FALSE(expected == findByPesel);
}
    