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

    bool compareTwoVectors(const PersonVector& lhs, const PersonVector& rhs){
        return std::equal(lhs.begin(),lhs.end(),rhs.begin(),rhs.end(),[](const std::shared_ptr<Person>& lhs,const std::shared_ptr<Person>& rhs)
                                                                                {
                                                                                    return *lhs == *rhs;
                                                                                }
                                                                                );
    }
  
};

TEST_F(DatabaseTestFixture, Check_people_added_correctly){
    addAll();
    
    EXPECT_EQ(db.getVectorOfPeople().size(),5);
}

TEST_F(DatabaseTestFixture, Check_find_by_surname_works_correctly){
    addAll();
    PersonVector result = {
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Student>(Monika)
                            };

    PersonVector peopleFound = db.findBySurname("Kaminski");


    ASSERT_TRUE(compareTwoVectors(result,peopleFound));
}

TEST_F(DatabaseTestFixture, Check_find_by_Pesel_works_correctly){
    addAll();
    PersonPtr result = {std::make_shared<Employee>(Maksymilian)};

    PersonPtr peopleFound = db.findByPesel("89060546172");


    ASSERT_TRUE(*result == *peopleFound);
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Surname_works_correctly_ASCENDING){
    addAll();
    db.sortBySurname(Order::Ascending);

    PersonVector result = db.getVectorOfPeople();
    
    PersonVector expected = { 
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Student>(Monika),
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Employee>(Maksymilian),
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Surname_works_correctly_DESCENDING){
    addAll();
    db.sortBySurname(Order::Descending);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Student>(Monika),
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Pesel_works_correctly_ASCENDING){
    addAll();
    db.sortByPesel(Order::Ascending);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Student>(Monika),
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Student>(Alicja),
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Pesel_works_correctly_DESCENDING){
    addAll();
    db.sortByPesel(Order::Descending);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Student>(Monika),
                            std::make_shared<Student>(Krzysztof),
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Salary_works_correctly_ASCENDING){
    addAll();
    db.sortBySalary(Order::Ascending);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Student>(Monika),
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Employee>(Justyna),
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Sort_By_Salary_works_correctly_DESCENDING){
    addAll();
    db.sortBySalary(Order::Descending);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Student>(Monika),
    };
    
    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Remove_By_Index_works_correctly){
    addAll();
    db.removeByIndex(28);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Student>(Krzysztof),
                            std::make_shared<Employee>(Justyna),
                            std::make_shared<Employee>(Maksymilian),
                            std::make_shared<Student>(Monika)
    };

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Remove_By_Range_works_correctly){
    addAll();
    db.removeRange(1,3);

    PersonVector result = db.getVectorOfPeople();

    PersonVector expected = { 
                            std::make_shared<Student>(Alicja),
                            std::make_shared<Student>(Monika),
    };
    // for(auto& c : result){
    //     std::cout<<*c<<"\n";
    // }
    // for(auto& c : expected){
    //     std::cout<<*c<<"\n";
    // }

    ASSERT_TRUE(compareTwoVectors(result,expected));
}

TEST_F(DatabaseTestFixture, Check_Modify_Earnings_works_correctly){
    addAll();
    db.modifyEarnings("06301105804", 1000);

    ASSERT_EQ(db.findByPesel("06301105804")->getEarnings(), 1000);
}

TEST_F(DatabaseTestFixture, Check_Generate_Random_People_works_correctly){
    db.generateRandomPeople(10);

    ASSERT_EQ(db.getVectorOfPeople().size(), 10);
}