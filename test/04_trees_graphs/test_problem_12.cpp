#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem12, Trivial) {
    auto t = CreateSimpleTree({});
    EXPECT_EQ(CountPaths(t, 0), 0);

    auto t2 = CreateSimpleTree({42});
    EXPECT_EQ(CountPaths(t2, 0), 0);
    EXPECT_EQ(CountPaths(t2, 42), 1);

    auto t3 = CreateSimpleTree({42, 42, 42});
    EXPECT_EQ(CountPaths(t3, 0), 0);
    EXPECT_EQ(CountPaths(t3, 42), 3);
}

TEST(Ch4Problem12, Test1) {
    auto t = CreateSimpleTree({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1});
    EXPECT_EQ(CountPaths(t, 1), 15);
    EXPECT_EQ(CountPaths(t, 2), 14);
    EXPECT_EQ(CountPaths(t, 3), 12);
    EXPECT_EQ(CountPaths(t, 4), 8);
    EXPECT_EQ(CountPaths(t, 5), 0);
}

TEST(Ch4Problem12, Test2) {
    auto t = CreateSimpleTree({1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1, -1, 1});
    EXPECT_EQ(CountPaths(t, 1), 13);
    EXPECT_EQ(CountPaths(t, 2), 7);
    EXPECT_EQ(CountPaths(t, 3), 2);
}
