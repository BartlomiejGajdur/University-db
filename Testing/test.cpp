#include <memory>
#include <vector>

#include "../Include/Student.hpp"
#include "../Include/Database.hpp"

#include "gtest/gtest.h"

struct DatabaseTestFixture : public ::testing::Test{
    Database db;

    Student Krzysztof{"Krzysztof", "Wozniak", "Gdansk 69-999", "68020198530"};
    Employee Justyna{"Justyna","Kaminski","Lodz 77-151","06301105804",5800};
    Employee Maksymilian{"Maksymilian", "Zielinski", "Lodz 41-321", "89060546172", 3800};
    Student Alicja{"Alicja","Kowalski","Wroclaw 69-999", "12312970203"};
    Student Monika{"Monika", "Kaminski", "Sopot 77-151", "68021593822"};

    void addAll() {
        db.add(Krzysztof);
        db.add(Justyna);
        db.add(Maksymilian);
        db.add(Alicja);
        db.add(Monika);
    }
  
};

TEST_F(DatabaseTestFixture, Check_if_people_added_correctly){
    addAll();
    
    EXPECT_EQ(db.getVectorOfPeople().size(),5);
}