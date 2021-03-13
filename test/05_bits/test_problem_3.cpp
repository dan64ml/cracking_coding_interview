#include "chapter_5.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch05;

TEST(Ch5Problem3, Test1) {
    EXPECT_EQ(FindMaxSequence(0b0), 1);
    EXPECT_EQ(FindMaxSequence(0b1), 2);
    EXPECT_EQ(FindMaxSequence(0b1111'1111), 9);
}

TEST(Ch5Problem3, Test2) {
    EXPECT_EQ(FindMaxSequence(0b0101'0101), 3);
    EXPECT_EQ(FindMaxSequence(0b1010'1010), 3);
}

TEST(Ch5Problem3, Test3) {
    EXPECT_EQ(FindMaxSequence(0b11011101111), 8);
    EXPECT_EQ(FindMaxSequence(0b110011001), 3);
}
