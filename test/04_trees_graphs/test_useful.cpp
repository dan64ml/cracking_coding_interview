#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

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

TEST(Ch4Useful, CreateAnyTree1) {
    auto t = CreateAnyTree({});
    EXPECT_EQ(t, nullptr);

    auto t2 = CreateAnyTree({42});
    EXPECT_NE(t2, nullptr);
    EXPECT_EQ(t2->left, nullptr);
    EXPECT_EQ(t2->right, nullptr);
    EXPECT_EQ(t2->key, 42);

    auto t3 = CreateAnyTree({NULL_NODE});
    EXPECT_EQ(t3, nullptr);

    auto t4 = CreateAnyTree({42, NULL_NODE, NULL_NODE});
    EXPECT_NE(t4, nullptr);
    EXPECT_EQ(t4->left, nullptr);
    EXPECT_EQ(t4->right, nullptr);
    EXPECT_EQ(t4->key, 42);
}

TEST(Ch4Useful, CreateAnyTree2) {
    auto t = CreateAnyTree({42, NULL_NODE, 100});
    EXPECT_NE(t, nullptr);
    EXPECT_EQ(t->key, 42);
    EXPECT_EQ(t->left, nullptr);
    EXPECT_NE(t->right, nullptr);
    EXPECT_EQ(t->right->key, 100);
    EXPECT_EQ(t->right->left, nullptr);
    EXPECT_EQ(t->right->right, nullptr);

    auto t2 = CreateAnyTree({42, 10, 100, NULL_NODE, 500, 1000, NULL_NODE});
    EXPECT_EQ(t2->key, 42);
    EXPECT_EQ(t2->left->key, 10);
    EXPECT_EQ(t2->right->key, 100);

    EXPECT_EQ(t2->left->right->key, 500);
    EXPECT_EQ(t2->right->left->key, 1000);

    EXPECT_EQ(t2->left->left, nullptr);
    EXPECT_EQ(t2->right->right, nullptr);
}
