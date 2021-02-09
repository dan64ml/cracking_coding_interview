#include "chapter_1.h"

#include "gtest/gtest.h"
#include <vector>

using namespace std;

TEST(Ch1Problem1, EmptyString) {
    EXPECT_TRUE(is_unique_1(""));
    EXPECT_TRUE(is_unique_2(""));
}

TEST(Ch1Problem1, EnglishStrings) {
    vector<string> unique_str {"abc", "c d", "aA-+=!Zz", " ", "1234567890"};
    vector<string> not_unique_str {"a a", "zabcdefz", "  ", "12341", "AAaa"};

    for (const auto& s : unique_str) {
        EXPECT_TRUE(is_unique_1(s));
        EXPECT_TRUE(is_unique_2(s));
    }

    for (const auto& s : not_unique_str) {
        EXPECT_FALSE(is_unique_1(s));
        EXPECT_FALSE(is_unique_2(s));
    }
}

/* TEST(Ch1Problem1, RussianStrings) {
    vector<string> unique_str {"абвгд", "ы ё", "аАьЬбБёЁюЮ", " ", "ъь№", "сc"};
    vector<string> not_unique_str {"азбука", "ёж ёжик", "  ", "йцукеннекуцй", "САРАФАН"};

    for (const auto& s : unique_str) {
        EXPECT_TRUE(is_unique_1(s)) << s;
        EXPECT_TRUE(is_unique_2(s)) << s;
    }

    for (const auto& s : not_unique_str) {
        EXPECT_FALSE(is_unique_1(s));
        EXPECT_FALSE(is_unique_2(s));
    }
}
 */
