#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem10, Test1) {
    Tracker tr;
    EXPECT_EQ(tr.GetRank(42), -1);
    vector<int> vec {1, 2, 3};
    for (auto e : vec) {
        tr.Track(e);
    }
    EXPECT_EQ(tr.GetRank(1), 0);
    EXPECT_EQ(tr.GetRank(2), 1);
    EXPECT_EQ(tr.GetRank(3), 2);
    EXPECT_EQ(tr.GetRank(42), -1);
}

TEST(Ch10Problem10, Test2) {
    Tracker tr;
    vector<int> vec {5, 1, 4, 4, 5, 9, 7, 13, 3};
    for (auto e : vec) {
        tr.Track(e);
    }
    EXPECT_EQ(tr.GetRank(1), 0);
    EXPECT_EQ(tr.GetRank(3), 1);
    EXPECT_EQ(tr.GetRank(4), 3);
    EXPECT_EQ(tr.GetRank(42), -1);
}

TEST(Ch10Problem10, Test3) {
    Tracker tr;
    vector<int> vec {5, 5, 5, 9, 7, 13, 3, 4, 4, 4, 4, 4, 4};
    for (auto e : vec) {
        tr.Track(e);
    }
    EXPECT_EQ(tr.GetRank(1), -1);
    EXPECT_EQ(tr.GetRank(3), 0);
    EXPECT_EQ(tr.GetRank(4), 6);
    EXPECT_EQ(tr.GetRank(5), 9);
    EXPECT_EQ(tr.GetRank(13), 12);
}
