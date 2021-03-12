#include "chapter_5.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch05;

TEST(Ch5Problem1, Trivial) {
    EXPECT_EQ(InsertNumber(0, 0, 1, 10), 0);
    EXPECT_EQ(InsertNumber(0xFFFFFFFF, 0xF, 1, 4), 0xFFFFFFFF);
    EXPECT_NE(InsertNumber(0xFFFFFFFF, 0xF, 1, 5), 0xFFFFFFFF);
    EXPECT_EQ(InsertNumber(0xFFFFFFFF, 0xF, 1, 5), 0xFFFFFFDF);
    EXPECT_EQ(InsertNumber(0xFFFFFFFF, 0x0, 4, 11), 0xFFFFF00F);
}

TEST(Ch5Problem1, Test1) {
    uint32_t n = 0b10000000000;
    uint32_t m = 0b10011;
    EXPECT_EQ(InsertNumber(n, m, 2, 6), 0b10001001100);
}