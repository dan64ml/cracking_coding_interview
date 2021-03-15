#include "chapter_5.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch05;

TEST(Ch5Problem6, Test1) {
    EXPECT_EQ(BitsForChange(42, 42), 0);
    EXPECT_EQ(BitsForChange(1, 0), 1);
    EXPECT_EQ(BitsForChange(0b1100, 0b11), 4);
    EXPECT_EQ(BitsForChange(0b1100, 0b1101), 1);
    EXPECT_EQ(BitsForChange(0b10000, 0b1), 2);
}