#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem2, Trivial) {
    vector<int> v {};
    auto t = CreateBalancedTree(v);
    EXPECT_EQ(GetTreeHeight(t), 0);

    v = {42};
    t = CreateBalancedTree(v);
    EXPECT_EQ(GetTreeHeight(t), 1);

    v = {10, 42};
    t = CreateBalancedTree(v);
    EXPECT_EQ(GetTreeHeight(t), 2);
    EXPECT_EQ(t->key, 42);
    EXPECT_EQ(t->left->key, 10);
}

TEST(Ch4Problem2, MainTest) {
    vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto t = CreateBalancedTree(v);
    EXPECT_EQ(GetTreeHeight(t), 4);

    vector<int> result;
    PrintInOrder(result, t);
    EXPECT_EQ(v, result);
}