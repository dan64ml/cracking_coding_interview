#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem3, Test1) {
    vector<int> v = {};
    EXPECT_EQ(FindMagicIndex(v), -1);

    vector<int> v1 = {42};
    EXPECT_EQ(FindMagicIndex(v1), -1);

    vector<int> v2 = {-1};
    EXPECT_EQ(FindMagicIndex(v2), -1);

    vector<int> v3 = {0};
    EXPECT_EQ(FindMagicIndex(v3), 0);
}

TEST(Ch8Problem3, Test2) {
    vector<int> v = {0, 1, 2, 3};
    EXPECT_EQ(FindMagicIndex(v), 1);

    vector<int> v1 = {-3, 0, 1, 3};
    EXPECT_EQ(FindMagicIndex(v1), 3);

    vector<int> v2 = {-1, 0, 1, 2, 4, 6, 7, 12};
    EXPECT_EQ(FindMagicIndex(v2), 4);
}
