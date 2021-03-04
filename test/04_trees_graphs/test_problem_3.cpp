#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem3, Trivial) {
    auto t = CreateSimpleTree({});
    auto ret = TreeToLists(t);
    EXPECT_EQ(ret.size(), 0);

    auto t2 = CreateSimpleTree({100});
    auto ret2 = TreeToLists(t2);
    EXPECT_EQ(ret2.size(), 1);
    EXPECT_EQ(ret2[0].size(), 1);
    EXPECT_EQ(ret2[0].front(), 100);
}

TEST(Ch4Problem3, BalancedTree) {
    auto data = {42, 10, 15, 100, 200, 300, 400};

    auto t = CreateSimpleTree(data);
    auto ret = TreeToLists(t);

    EXPECT_EQ(ret.size(), 3);
    EXPECT_EQ(ret[0].size(), 1);
    EXPECT_EQ(ret[1].size(), 2);
    EXPECT_EQ(ret[2].size(), 4);

    size_t idx = 0;
    vector<int> answer = data;

    for (auto l : ret) {
        while (!l.empty()) {
            EXPECT_EQ(answer[idx++], l.front());
            l.pop_front();
        }
    }
}

TEST(Ch4Problem3, UnbalancedTree) {
    auto t = CreateAnyTree({43,  100, NULL_NODE,   50, 500, NULL_NODE, NULL_NODE,   33, 333});
    auto ret = TreeToLists(t);

    EXPECT_EQ(ret.size(), 4);

    EXPECT_EQ(ret[0].size(), 1);
    EXPECT_EQ(ret[0].front(), 42);

    EXPECT_EQ(ret[1].size(), 1);
    EXPECT_EQ(ret[1].front(), 100);

    EXPECT_EQ(ret[2].size(), 2);
    EXPECT_EQ(ret[2].front(), 50);
    ret[2].pop_front();
    EXPECT_EQ(ret[2].front(), 500);

    EXPECT_EQ(ret[3].size(), 2);
    EXPECT_EQ(ret[3].front(), 33);
    ret[3].pop_front();
    EXPECT_EQ(ret[3].front(), 333);
}
