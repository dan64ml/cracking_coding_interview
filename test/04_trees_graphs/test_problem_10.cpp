#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem10, Trivial) {
    EXPECT_TRUE(IsSubTree(nullptr, nullptr));

    auto t1 = CreateSimpleTree({100, 200, 300});
    EXPECT_TRUE(IsSubTree(t1, nullptr));

    auto t2 = CreateSimpleTree({100});
    EXPECT_FALSE(IsSubTree(t1, t2));
    t2 = CreateSimpleTree({200});
    EXPECT_TRUE(IsSubTree(t1, t2));
    t2 = CreateSimpleTree({300});
    EXPECT_TRUE(IsSubTree(t1, t2));
}

TEST(Ch4Problem10, Test1) {
    auto t1 = CreateSimpleTree({100, 42, 12, 44, 200, 77, 11, 22, 1});
    EXPECT_TRUE(IsSubTree(t1, t1));
}

TEST(Ch4Problem10, Test2) {
    auto t1 = CreateSimpleTree({42, 42, 42, 42, 42, 42, 42, 42});
    auto t2 = CreateSimpleTree({42, 42, 42});
    EXPECT_TRUE(IsSubTree(t1, t2));
}

TEST(Ch4Problem10, Test3) {
    auto t1 = CreateAnyTree({42, 42, NULL_NODE, 42, NULL_NODE, NULL_NODE, NULL_NODE, 42});
    auto t2 = CreateSimpleTree({42, 42, 42});
    EXPECT_FALSE(IsSubTree(t1, t2));
    auto t3 = CreateSimpleTree({42, 42});
    EXPECT_TRUE(IsSubTree(t1, t3));
}
