#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem1, Test1) {
    vector<int> a {1, 5, 6, 12, 0, 0, 0, 0};
    vector<int> b {2, 3, 6, 9};
    MergeAB(a, 4, b);
    EXPECT_EQ(a, vector<int>({1, 2, 3, 5, 6, 6, 9, 12}));
}

TEST(Ch10Problem1, Test2) {
    vector<int> a {2, 5, 6, 12, 0};
    vector<int> b {1};
    MergeAB(a, 4, b);
    EXPECT_EQ(a, vector<int>({1, 2, 5, 6, 12}));
}

TEST(Ch10Problem1, Test3) {
    vector<int> a {2, 5, 6, 12, 0};
    vector<int> b {100};
    MergeAB(a, 4, b);
    EXPECT_EQ(a, vector<int>({2, 5, 6, 12, 100}));
}

TEST(Ch10Problem1, Test4) {
    vector<int> a {50, 0, 0, 0, 0};
    vector<int> b {2, 5, 6, 12};
    MergeAB(a, 1, b);
    EXPECT_EQ(a, vector<int>({2, 5, 6, 12, 50}));
}
