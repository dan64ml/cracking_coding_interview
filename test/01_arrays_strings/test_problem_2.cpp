#include "chapter_1.h"

#include "gtest/gtest.h"

#include <vector>
#include <utility>

using namespace std;
using namespace ch01;

TEST(Ch1Problem2, Permutation) {
    vector<pair<string, string>> str {{"", ""}, {"a", "a"}, {"aaaaaa", "aaaaaa"}, {"zz ssss w __", "z_s  w_zss s"},
                                        {"abcdef", "fedcba"}, {"   ", "   "}, {"1234567890", "0987654321"}};

    for (const auto& [s1, s2] : str) {
        EXPECT_TRUE(is_permutation_1(s1, s2)) << "s1 = " << s1 << ", s2 = " << s2;
        EXPECT_TRUE(is_permutation_2(s1, s2)) << "s1 = " << s1 << ", s2 = " << s2;
    }
}

TEST(Ch1Problem2, NotPermutation) {
    vector<pair<string, string>> str {{" ", ""}, {"A", "a"}, {"a a a a a a", "aaaaaa"}, {"zz ssss w __", "z_sw_zsss"},
                                        {"abcdef", ""}, {"___", "   "}, {"1234567890", "!@#$%^&*()"}};

    for (const auto& [s1, s2] : str) {
        EXPECT_FALSE(is_permutation_1(s1, s2)) << "s1 = " << s1 << ", s2 = " << s2;
        EXPECT_FALSE(is_permutation_2(s1, s2)) << "s1 = " << s1 << ", s2 = " << s2;
    }
}