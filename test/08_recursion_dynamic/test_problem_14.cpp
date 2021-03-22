#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem14, Test1) {
    EXPECT_EQ(CountEval("1^0|0|1", false), 2);
}

TEST(Ch8Problem14, Test2) {
    EXPECT_EQ(CountEval("0&0&0&1^1|0", true), 10);
}
