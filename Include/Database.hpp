#pragma once
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include "Employee.hpp"
#include "Generator.hpp"
#include "Person.hpp"
#include "Student.hpp"

using PersonPtr = std::shared_ptr<Person>;
using PersonVector = std::vector<PersonPtr>;

enum class Order
{
    Ascending,
    Descending
};

class Database
{
public:
    Database();
    Database(const PersonVector &vectorOfPeople) : vectorOfPeople_(vectorOfPeople){};

    // Getters
    PersonVector getVectorOfPeople() const { return vectorOfPeople_; };
    std::vector<std::string> getFIleNames() const { return fileNames; };

    // Setters
    void clearVectorOfPeople() { vectorOfPeople_.clear(); };

    // Functions
    void add(const PersonPtr &person);
    void add(const Student &person);
    void add(const Employee &person);

    void printDatabase();

    PersonVector findBySurname(const std::string &surname);
    PersonPtr findByPesel(const std::string &pesel);
    void sortBySurname(const Order &order);
    void sortByPesel(const Order &order);
    void sortBySalary(const Order &order);
    void removeByIndex(const size_t index);
    void removeRange(const size_t &lhs, const size_t &rhs);
    void modifyEarnings(const std::string &pesel, const size_t &earnings);

    void generateRandomPeople(const size_t &numberOfPeopleToGenerate);
    void generateSelectedProffesion(const size_t &numberOfPeopleToGenerate, const Proffesion &proffesion);

    void saveDatabaseToFile(const std::string &fileName);
    void saveDatabaseToFile();

    void loadDataFromFile(const std::string &fileName);
    void loadDataFromFile();

    void saveConfiguration(const std::string &fileName);
    void loadSavedDatabaseNames();
    void loadSavedDatabase(std::string &fileName);

private:
    PersonVector vectorOfPeople_;
    std::vector<std::string> fileNames;

    std::stringstream formatPrint();
    std::stringstream formatPrintToLoad();
    void saveNamesToConfigFiles();
};