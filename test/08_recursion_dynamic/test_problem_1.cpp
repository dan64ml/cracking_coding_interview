#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem1, Trivial) {
    EXPECT_EQ(PathNumber(1), 1);
    EXPECT_EQ(PathNumber(2), 2);
    EXPECT_EQ(PathNumber(3), 4);
}