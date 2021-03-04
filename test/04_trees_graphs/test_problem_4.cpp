#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem4, Trivial) {
    auto t = CreateSimpleTree({});
    EXPECT_TRUE(IsTreeBalanced(t));

    auto t2 = CreateSimpleTree({100});
    EXPECT_TRUE(IsTreeBalanced(t2));

    auto t3 = CreateSimpleTree({100, 200, 300});
    EXPECT_TRUE(IsTreeBalanced(t3));
}

TEST(Ch4Problem4, Main) {
    auto t = CreateSimpleTree({10, 20, 30, 40});
    EXPECT_TRUE(IsTreeBalanced(t));

    auto t2 = CreateSimpleTree({10, 20, 30, 40, 50});
    EXPECT_TRUE(IsTreeBalanced(t2));

    auto t3 = CreateAnyTree({10, 20, 30, 40, 50, NULL_NODE, NULL_NODE, 100});
    EXPECT_FALSE(IsTreeBalanced(t3));

    auto t4 = CreateAnyTree({10, NULL_NODE, 20,   NULL_NODE, NULL_NODE, 30});
    EXPECT_FALSE(IsTreeBalanced(t4));
}