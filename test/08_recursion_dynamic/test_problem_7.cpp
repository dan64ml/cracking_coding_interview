#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem7, Test1) {
    auto ret = Permutation("");
    EXPECT_EQ(ret, vector<string>({""}));

    ret = Permutation("a");
    EXPECT_EQ(ret, vector<string>({"a"}));

    ret = Permutation("ab");
    EXPECT_EQ(ret, vector<string>({"ab", "ba"}));
}

TEST(Ch8Problem7, Test2) {
    auto ret = Permutation("abc");
    vector<string> answer {"abc", "acb", "bac", "bca", "cab", "cba"};
    EXPECT_EQ(ret, answer);
}

TEST(Ch8Problem7, Test3) {
    auto ret = Permutation("abcd");
    vector<string> answer {"abcd", "abdc", "acbd", "acdb", "adbc", "adcb", 
        "bacd", "badc", "bcad", "bcda", "bdac", "bdca", "cabd", "cadb", "cbad", 
        "cbda", "cdab", "cdba", "dabc", "dacb", "dbac", "dbca", "dcab", "dcba"};
    EXPECT_EQ(ret, answer);
}
