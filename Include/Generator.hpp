#pragma once
#include <array>
#include <random>

enum class Proffesion {Student,Employee};

namespace generate{
    
int generateRandomNumber(const int& first, const int& second);

std::string generateDay(const std::string& month);
std::string generatePesel();
std::string generateName(const std::string& pesel);
std::string generateSurname();
std::string generateAdress();
int generateEarnings();
}