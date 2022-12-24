#include <array>
#include <memory>
#include <string>
#include <utility>

#include "../Include/Validate.hpp"
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
    {"801105124678", false}};

class CheckPesel : public testing::TestWithParam<std::pair<std::string, bool>>
{
};

TEST_P(CheckPesel, ValidatePesel)
{
    auto [PeselToCheck, Response] = GetParam();

    ASSERT_EQ(PeselValidator::validatePesel(PeselToCheck), Response);
}

INSTANTIATE_TEST_SUITE_P(Pesels,
                         CheckPesel,
                         testing::ValuesIn(PeselsWithThierResponse));

std::vector<std::pair<std::string, bool>> LeapYearWithThierResponse = {
    {"48040885491", true},  // 1948
    {"80120512467", true},  // 1980
    {"0021", true},         // 2000
    {"1621", true},         // 2016
    {"2821", true},         // 2028
    {"0412", true},         // 1904
    {"47051218130", false}, // 1947
    {"", false},
    {"0001", false}, // 1900
    {"xxxx", false},
    {"12x2", false},
    {"xx02", false},
    {"1903", false}, // 1919
    {"2201", false}, // 1922
    {"2921", false}  // 2029
};

class CheckLeapYear : public testing::TestWithParam<std::pair<std::string, bool>>
{
};

TEST_P(CheckLeapYear, ValidateLeapYear)
{
    auto [LeapYearToCheck, Response] = GetParam();

    ASSERT_EQ(PeselValidator::checkLeapYear(LeapYearToCheck), Response);
}

INSTANTIATE_TEST_SUITE_P(Years,
                         CheckLeapYear,
                         testing::ValuesIn(LeapYearWithThierResponse));
