#include "chapter_4.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch04;

TEST(Ch4Problem6, trivial) {
    auto t = CreateAnyPTree({});
    EXPECT_EQ(GetNextNode(t), nullptr);

    auto t1 = CreateAnyPTree({42});
    EXPECT_EQ(GetNextNode(t1), nullptr);

    auto t2 = CreateAnyPTree({42, 22});
    EXPECT_EQ(GetNextNode(t2), nullptr);

    auto t3 = CreateAnyPTree({42, 22, 62});
    EXPECT_EQ(GetNextNode(t3), t3->right);
}

TEST(Ch4Problem6, Main) {
    auto t = CreateAnyPTree({50,  30, 100,  20, 40, 90, 200,  10, NULL_NODE, NULL_NODE, 45,
                NULL_NODE, NULL_NODE, NULL_NODE, 300,  NULL_NODE, 15});
    EXPECT_EQ(GetNextNode(t), t->right->left);
    
    auto node = t->left->left->left;
    EXPECT_EQ(GetNextNode(node), node->right);
    
    node = t->right->right->right;
    EXPECT_EQ(GetNextNode(node), nullptr);
    
    node = t->left;
    EXPECT_EQ(GetNextNode(node), node->right);
    
    node = t->left->right->right;
    EXPECT_EQ(GetNextNode(node), t);
    
    node = t->right->left;
    EXPECT_EQ(GetNextNode(node), t->right);
}