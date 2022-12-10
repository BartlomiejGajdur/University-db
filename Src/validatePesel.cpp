#include "../Include/validatePesel.hpp"

bool PeselValidator::checkLength(const std::string& Pesel){
    return Pesel.size() == peselLength;
}