#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

using namespace std;
using namespace ch01;

TEST(Ch1Problem6, Test) {
    EXPECT_EQ(compress(""), "");
    EXPECT_EQ(compress(" "), " ");
    EXPECT_EQ(compress("  "), "  ");
    EXPECT_EQ(compress("   "), " 3");
    EXPECT_EQ(compress("abcdef"), "abcdef");
    EXPECT_EQ(compress("aabbccdd"), "aabbccdd");
    EXPECT_EQ(compress("abcdef============"), "a1b1c1d1e1f1=12");
    EXPECT_EQ(compress("aabcccccaaa"), "a2b1c5a3");
    EXPECT_EQ(compress(string(1'000'000, 'a')), "a1000000");
}