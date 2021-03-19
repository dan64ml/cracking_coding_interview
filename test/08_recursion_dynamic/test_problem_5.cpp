#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem5, Test1) {
    EXPECT_EQ(Mult(42, 1), 42);
    EXPECT_EQ(Mult(1, 42), 42);
    EXPECT_EQ(Mult(1, 1), 1);
    EXPECT_EQ(Mult(107, 13), 107*13);
    EXPECT_EQ(Mult(22, 100), 2200);
}