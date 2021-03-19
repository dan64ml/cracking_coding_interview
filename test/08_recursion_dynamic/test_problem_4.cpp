#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem4, Test1) {
    vector<char> vec {'a'};
    auto ret = GenerateSubsets(vec);
    EXPECT_EQ(ret, vector<string> ({"", "a"}));
}

TEST(Ch8Problem4, Test2) {
    vector<char> vec {'a', 'b', 'c'};
    auto ret = GenerateSubsets(vec);
    sort(begin(ret), end(ret));
    EXPECT_EQ(ret, vector<string> ({"", "a", "ab", "abc", "ac", "b", "bc", "c"}));
}