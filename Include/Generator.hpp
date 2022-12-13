#pragma once
#include <array>
#include <random>

enum class Proffesion {Student,Employee};

namespace generate{
//GenerateData 3 przeciazenia 1- dla enum Student
//GenerateData dla pracownika 
// GenerateData losowo wszedzie ilosc i enum
int generateRandomNumber(const int& first, const int& second);
std::string generateDay(const std::string& month);

std::string generatePesel();
std::string generateName(const std::string& pesel);
std::string generateSurname();
std::string generateAdress();
int generateEarnings();
}