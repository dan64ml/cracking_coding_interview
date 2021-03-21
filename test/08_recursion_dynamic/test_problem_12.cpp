#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem12, TestSize) {
    auto ret = AllQueens();
    EXPECT_EQ(ret.size(), 92);
}