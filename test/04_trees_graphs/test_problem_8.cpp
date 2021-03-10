#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem8, Trivial) {
    auto t = CreateSimpleTree({});
    auto ret = FindAncestor(t, nullptr, nullptr);
    EXPECT_EQ(ret, nullptr);

    auto t2 = CreateSimpleTree({42});
    auto ret2 = FindAncestor(t2, nullptr, nullptr);
    EXPECT_EQ(ret2, nullptr);

    auto t3 = CreateSimpleTree({42, 100, 200});
    auto ret3 = FindAncestor(t3, t3->right, t3->left);
    EXPECT_EQ(ret3, t3);

    auto t4 = CreateSimpleTree({42, 100, 200});
    auto ret4 = FindAncestor(t4, t4, t4->left);
    EXPECT_EQ(ret4, t4);
}

TEST(Ch4Problem8, Test1) {
    auto t = CreateSimpleTree({1,  2, 3,  4, 5, 6, 7,  8, 9, 10, 11, 12, 13, 14, 15});
    auto ret = FindAncestor(t, t, t->right->right->right);
    EXPECT_EQ(ret, t);
}

TEST(Ch4Problem8, Test2) {
    auto t = CreateSimpleTree({1,  2, 3,  4, 5, 6, 7,  8, 9, 10, 11, 12, 13, 14, 15});
    auto ret = FindAncestor(t, t->left->left->left, t->right->right->right);
    EXPECT_EQ(ret, t);
}

TEST(Ch4Problem8, Test3) {
    auto t = CreateSimpleTree({1,  2, 3,  4, 5, 6, 7,  8, 9, 10, 11, 12, 13, 14, 15});
    auto ret = FindAncestor(t, t->right->left->left, t->right->right->right);
    EXPECT_EQ(ret, t->right);
}

TEST(Ch4Problem8, Test4) {
    auto t = CreateSimpleTree({1,  2, 3,  4, 5, 6, 7,  8, 9, 10, 11, 12, 13, 14, 15});
    auto ret = FindAncestor(t, t->left->left->left, t->left);
    EXPECT_EQ(ret, t->left);
}

TEST(Ch4Problem8, Test5) {
    auto t = CreateSimpleTree({1,  2, 3,  4, 5, 6, 7,  8, 9, 10, 11, 12, 13, 14, 15});
    auto ret = FindAncestor(t, t->left->left->left, t->left->right->left);
    EXPECT_EQ(ret, t->left);
}
