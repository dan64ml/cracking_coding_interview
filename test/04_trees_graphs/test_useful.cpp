#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;

TEST(Ch4Useful, CreateSimpleTree) {
    auto t = CreateSimpleTree({});
    EXPECT_EQ(t, nullptr);

    auto t2 = CreateSimpleTree({42});
    EXPECT_NE(t2, nullptr);
    EXPECT_EQ(t2->key, 42);
    EXPECT_EQ(t2->left, nullptr);
    EXPECT_EQ(t2->right, nullptr);

    auto t3 = CreateSimpleTree({1, 2, 3, 4, 5, 6, 7, 8});
    vector<int> answer {8, 4, 2, 5, 1, 6, 3, 7};
    vector<int> result;
    PrintInOrder(result, t3);

    EXPECT_EQ(answer, result);
}

TEST(Ch4Useful, GetTreeHeight) {
    auto t = CreateSimpleTree({});
    EXPECT_EQ(GetTreeHeight(t), 0);

    t = CreateSimpleTree({42});
    EXPECT_EQ(GetTreeHeight(t), 1);

    auto l = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> answer(l);
    t = CreateSimpleTree(l);
    EXPECT_EQ(GetTreeHeight(t), 4);
}