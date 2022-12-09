
#include <memory>
#include <vector>

#include "../Include/Student.hpp"
#include "../Include/Database.hpp"

#include "gtest/gtest.h"

struct DatabaseUnderTestFixture : public ::testing::Test{
    Student Adam{
        "Adam",
        "cwalski",
        "Krakow 21",
        "000000000",
        Gender::Male
    };

    Student Kasia{
        "Kasia",
        "aalkowski",
        "Krakow 21dd",
        "000011000",
        Gender::Female
    };

    Student Bartek{
        "Bartek",
        "aalkowski",
        "Markowska 21",
        "000220000",
        Gender::Male
    };
    
    std::vector<std::shared_ptr<Student>> vectorOfStudents{std::make_shared<Student>(Adam),
                                                           std::make_shared<Student>(Kasia),   
                                                           std::make_shared<Student>(Bartek)};
    Database db{vectorOfStudents};
};

TEST_F(DatabaseUnderTestFixture, CanAddStudentToDb){
    
    size_t sizeBeforeAdd = db.getVectorOfStudents().size();
    db.add(std::make_shared<Student>(Adam));
    size_t sizeAfterAdd = db.getVectorOfStudents().size();

    EXPECT_EQ(sizeBeforeAdd,sizeAfterAdd-1);
}

TEST_F(DatabaseUnderTestFixture, FindBySurname){

    std::vector<Student> expected{Kasia,Bartek};
    std::vector<Student> findBySurname = db.findBySurname("Malkowski");

    ASSERT_TRUE(std::equal(findBySurname.begin(),findBySurname.end(),expected.begin()));
}

TEST_F(DatabaseUnderTestFixture, FindByPesel_INCLUDE){
    
    Student expected{Bartek};
    Student findByPesel = db.findByPesel("000220000");

    ASSERT_TRUE(expected == findByPesel);
}

TEST_F(DatabaseUnderTestFixture, FindByPesel_NOT_INCLUDE){

    Student expected{Bartek};
    Student findByPesel = db.findByPesel("00022000011111111");

    ASSERT_FALSE(expected == findByPesel);
}

TEST_F(DatabaseUnderTestFixture, SortingBySurname_Ascending){

    std::vector<std::shared_ptr<Student>> expected{std::make_shared<Student>(Kasia),
                                                   std::make_shared<Student>(Bartek),
                                                   std::make_shared<Student>(Adam)};
    db.sortBySurname(Order::Ascending);
    std::vector<std::shared_ptr<Student>> value = db.getVectorOfStudents();

    ASSERT_TRUE(std::equal(expected.begin(),expected.end(),value.begin(),
                                                                        [](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>&rhs)
                                                                            {return *lhs == *rhs;}));
}

TEST_F(DatabaseUnderTestFixture, SortingBySurname_Descending){

    std::vector<std::shared_ptr<Student>> expected{std::make_shared<Student>(Adam),
                                                   std::make_shared<Student>(Kasia),
                                                   std::make_shared<Student>(Bartek)
                                                   };
    db.sortBySurname(Order::Descending);
    std::vector<std::shared_ptr<Student>> value = db.getVectorOfStudents();

    ASSERT_TRUE(std::equal(expected.begin(),expected.end(),value.begin(),
                                                                        [](const std::shared_ptr<Student>& lhs, const std::shared_ptr<Student>&rhs)
                                                                            {return *lhs == *rhs;}));
}