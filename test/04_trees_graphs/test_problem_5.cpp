#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem5, Trivial) {
    auto t = CreateSimpleTree({});
    EXPECT_TRUE(IsBST(t));

    auto t2 = CreateSimpleTree({42});
    EXPECT_TRUE(IsBST(t2));

    auto t3 = CreateSimpleTree({42, 22, 62});
    EXPECT_TRUE(IsBST(t3));

    auto t4 = CreateSimpleTree({42, 100});
    EXPECT_FALSE(IsBST(t4));

    auto t5 = CreateSimpleTree({42, 42});
    EXPECT_TRUE(IsBST(t5));

    auto t6 = CreateSimpleTree({42, 42, 42});
    EXPECT_FALSE(IsBST(t6));

    auto t7 = CreateSimpleTree({42, 100, 300});
    EXPECT_FALSE(IsBST(t7));
}

TEST(Ch4Problem5, Main) {
    auto t = CreateAnyTree({100,   50, NULL_NODE,   25, NULL_NODE, NULL_NODE, NULL_NODE,   10});
    EXPECT_TRUE(IsBST(t));

    auto t2 = CreateAnyTree({100,   50, NULL_NODE,   25, 75, NULL_NODE, NULL_NODE,   10, 30});
    EXPECT_TRUE(IsBST(t2));

    auto t3 = CreateAnyTree({100,   50, NULL_NODE,   50, 75, NULL_NODE, NULL_NODE,   10, 55});
    EXPECT_FALSE(IsBST(t3));

    auto t4 = CreateAnyTree({100,   50, NULL_NODE,   25, 50, NULL_NODE, NULL_NODE,   10, 30});
    EXPECT_FALSE(IsBST(t4));

    auto t5 = CreateAnyTree({100,   50, 200,   25, 75, 150, 250});
    EXPECT_TRUE(IsBST(t5));
}