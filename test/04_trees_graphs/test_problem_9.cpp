#include "chapter_4.h"
#include "bs_tree.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem9, Trivial) {
    auto t = CreateSimpleTree({});
    auto ret = GetSequences(t);
    EXPECT_EQ(ret.size(), 0);

    auto t2 = CreateSimpleTree({42});
    auto ret2 = GetSequences(t2);
    EXPECT_EQ(ret2.size(), 1);
    EXPECT_EQ(ret2[0], vector<int> {42});

    auto t3 = CreateSimpleTree({42, 10});
    auto ret3 = GetSequences(t3);
    EXPECT_EQ(ret3.size(), 1);
    EXPECT_EQ(ret3[0], vector<int>({42, 10}));
}

TEST(Ch4Problem9, Test1) {
    auto t = CreateSimpleTree({42, 10, 100});
    auto ret = GetSequences(t);
    EXPECT_EQ(ret.size(), 2);
    EXPECT_EQ(ret[0], vector<int>({42, 10, 100}));
    EXPECT_EQ(ret[1], vector<int>({42, 100, 10}));
}

TEST(Ch4Problem9, Test2) {
    BSTree<int> orig;
    for (auto e : {42, 10, 100}) {
        orig.AddNode(e);
    }

    auto ret = GetSequences(orig.GetRoot());
    EXPECT_EQ(ret.size(), 2);

    for (const auto& seq : ret) {
        BSTree<int> t;
        for (auto e : seq) {
            t.AddNode(e);
        }

        EXPECT_TRUE(orig == t);
    }
}

TEST(Ch4Problem9, Test3) {
    BSTree<int> orig;
    for (auto e : {100, 50, 200, 90, 150, 180}) {
        orig.AddNode(e);
    }

    auto ret = GetSequences(orig.GetRoot());

    for (const auto& seq : ret) {
        BSTree<int> t;
        for (auto e : seq) {
            t.AddNode(e);
        }

        EXPECT_TRUE(orig == t);
    }
}

