#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

bool IsHillSortOk(const vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); i += 2) {
        if (vec[i - 1] > vec[i]) {
            return false;
        }
        if ((i + i) < vec.size() && vec[i] < vec[i + 1]) {
            return false;
        }
    }

    return true;
}

TEST(Ch10Problem11, TestHelper) {
    vector<int> v1 {};
    EXPECT_TRUE(IsHillSortOk(v1));
    vector<int> v2 {42};
    EXPECT_TRUE(IsHillSortOk(v2));
    vector<int> v3 {10, 42};
    EXPECT_TRUE(IsHillSortOk(v3));
    vector<int> v4 {11, 18, 6};
    EXPECT_TRUE(IsHillSortOk(v4));
    vector<int> v5 {11, 18, 6, 7, -15, 2, 1, 50};
    EXPECT_TRUE(IsHillSortOk(v5));
    vector<int> v6 {11, 18, 62};
    EXPECT_FALSE(IsHillSortOk(v6));
    vector<int> v7 {19, 18, 6};
    EXPECT_FALSE(IsHillSortOk(v7));
    vector<int> v8 {11, 11};
    EXPECT_TRUE(IsHillSortOk(v8));
}

TEST(Ch10Problem11, Test1) {
    vector<int> vec {};
    HillSort(vec);
    EXPECT_TRUE(IsHillSortOk(vec));
    vector<int> vec1 {42};
    HillSort(vec1);
    EXPECT_TRUE(IsHillSortOk(vec1));
    vector<int> vec2 {42, 42};
    HillSort(vec2);
    EXPECT_TRUE(IsHillSortOk(vec2));
}

TEST(Ch10Problem11, Test2) {
    vector<int> vec {-42, -42, -42};
    HillSort(vec);
    EXPECT_TRUE(IsHillSortOk(vec));
    vector<int> vec1 {5, 3, 1, 2, 3};
    HillSort(vec1);
    EXPECT_TRUE(IsHillSortOk(vec1));
    vector<int> vec2 {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2};
    HillSort(vec2);
    EXPECT_TRUE(IsHillSortOk(vec2));
}