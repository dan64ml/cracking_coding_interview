#include "chapter_5.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch05;

TEST(Ch5Problem7, Trivial) {
    EXPECT_EQ(SwapEvenOdd(0), 0);
    EXPECT_EQ(SwapEvenOdd(1), 2);
    EXPECT_EQ(SwapEvenOdd(0b1010), 0b101);
    EXPECT_EQ(SwapEvenOdd(0b100001), 0b10010);
}