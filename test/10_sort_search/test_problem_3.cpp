#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem3, Test1) {
    vector<int> vec {1, 3, 5, 7, 9};
    EXPECT_EQ(SearchNumber(vec, 3), 1);
    EXPECT_FALSE(SearchNumber(vec, 10));
}

TEST(Ch10Problem3, Test2) {
    vector<int> vec {7, 9, 1, 3, 5};
    EXPECT_EQ(SearchNumber(vec, 3), 3);
    EXPECT_EQ(SearchNumber(vec, 7), 0);
    EXPECT_FALSE(SearchNumber(vec, 10));
}

TEST(Ch10Problem3, Test3) {
    vector<int> vec {7, 9, 1, 1, 1, 1, 1, 3, 5};
    EXPECT_EQ(SearchNumber(vec, 3), 7);
    EXPECT_EQ(SearchNumber(vec, 9), 1);
    EXPECT_FALSE(SearchNumber(vec, 10));
}

TEST(Ch10Problem3, Test4) {
    vector<int> vec {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    EXPECT_EQ(SearchNumber(vec, 5), 8);
    EXPECT_FALSE(SearchNumber(vec, 30));
}