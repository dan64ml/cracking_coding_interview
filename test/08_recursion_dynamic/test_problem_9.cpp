#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem9, Test1) {
    EXPECT_EQ(GenerateParentheses(1), vector<string>({"()"}));
    EXPECT_EQ(GenerateParentheses(2), vector<string>({"(())", "()()"}));
}

TEST(Ch8Problem9, Test2) {
    auto ret = GenerateParentheses(3);
    vector<string> answer {"((()))", "(()())", "(())()", "()(())", "()()()"};

    EXPECT_EQ(ret, answer);
}