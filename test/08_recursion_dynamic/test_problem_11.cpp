#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem11, Test1Change1) {
    EXPECT_EQ(Change1(1), 1);
    EXPECT_EQ(Change1(2), 1);
    EXPECT_EQ(Change1(3), 1);
    EXPECT_EQ(Change1(4), 1);
    EXPECT_EQ(Change1(5), 2);
    EXPECT_EQ(Change1(6), 3);
    EXPECT_EQ(Change1(10), 9);
}

TEST(Ch8Problem11, Test1Change2) {
    EXPECT_EQ(Change2(1), 1);
    EXPECT_EQ(Change2(2), 1);
    EXPECT_EQ(Change2(3), 1);
    EXPECT_EQ(Change2(4), 1);
    EXPECT_EQ(Change2(5), 2);
    EXPECT_EQ(Change2(6), 2);
    EXPECT_EQ(Change2(10), 4);
    EXPECT_EQ(Change2(11), 4);
    EXPECT_EQ(Change2(25), 13);
    EXPECT_EQ(Change2(26), 13);
}
