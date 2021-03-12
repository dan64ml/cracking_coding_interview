#include "chapter_5.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch05;

TEST(Ch5Problem2, Trivial) {
    EXPECT_EQ(NumToBinary(0), ".0");
    EXPECT_EQ(NumToBinary(0.5), ".1");
}

TEST(Ch5Problem2, Test1) {
    EXPECT_EQ(NumToBinary(0.625), ".101");
    EXPECT_EQ(NumToBinary(0.3), "error");
}
