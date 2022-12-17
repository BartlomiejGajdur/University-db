#include <array>
#include <memory>
#include <string>
#include <utility>

#include "../Include/validatePesel.hpp"
#include "gtest/gtest.h"


std::vector<std::pair<std::string, bool>> PeselsWithThierResponse = {
    {"90090515836", true},
    {"92071314764", true},
    {"81100216357", true},
    {"80072909146", true},
    {"", false},
    {"42533f", false},
    {"53", false},
    {"01234567890-", false},
    {"35292569", false},
    {"SomeLetters", false},
    {"00231185429", false},
    {"47051218130", false},
    {"47040885491", false},
    {"801105124678", false}}
;


class CheckPesel : public testing::TestWithParam<std::pair<std::string,bool>>{

};

TEST_P(CheckPesel, ValidatePesel){
    auto [PeselToCheck, Response] = GetParam();

    ASSERT_EQ(PeselValidator::validatePesel(PeselToCheck),Response);
}

INSTANTIATE_TEST_SUITE_P(Pesels,
                         CheckPesel,
                         testing::ValuesIn(PeselsWithThierResponse));

