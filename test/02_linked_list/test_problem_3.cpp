#include "chapter_2.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch02;

TEST(Ch2Problem3, Main) {
    auto lst1 = create_llist({1, 2, 3});
    auto node = lst1->pNext;
    delete_node(node);
    EXPECT_EQ(lst1->value, 1);
    EXPECT_EQ(lst1->pNext->value, 3);
    EXPECT_EQ(lst1->pNext->pNext, nullptr);
}