#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem8, Test1) {
    EXPECT_EQ(UniquePermutation(""), vector<string>({""}));
    EXPECT_EQ(UniquePermutation("a"), vector<string>({"a"}));
    EXPECT_EQ(UniquePermutation("aa"), vector<string>({"aa"}));
    EXPECT_EQ(UniquePermutation("aaa"), vector<string>({"aaa"}));
}

TEST(Ch8Problem8, Test2) {
    EXPECT_EQ(UniquePermutation("ab"), vector<string>({"ab", "ba"}));

    auto ret = UniquePermutation("abc");
    vector<string> answer {"abc", "acb", "bac", "bca", "cab", "cba"};
    EXPECT_EQ(ret, answer);
}

TEST(Ch8Problem8, Test3) {
    EXPECT_EQ(UniquePermutation("ab"), vector<string>({"ab", "ba"}));

    auto ret = UniquePermutation("aab");
    vector<string> answer {"aab", "aba", "baa"};
    EXPECT_EQ(ret, answer);
}
