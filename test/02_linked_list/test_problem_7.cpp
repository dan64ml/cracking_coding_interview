#include "chapter_2.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch02;

TEST(Ch2Problem7, Trivial) {
    auto l1 = create_llist({});
    auto l2 = create_llist({});
    EXPECT_EQ(is_intersect(l1, l2), nullptr);

    auto l3 = create_llist({1, 2, 3, 4});
    auto l4 = create_llist({});
    EXPECT_EQ(is_intersect(l3, l4), nullptr);

    auto l5 = create_llist({1, 2, 3, 4});
    auto l6 = create_llist({1, 2, 3, 4});
    EXPECT_EQ(is_intersect(l5, l6), nullptr);
}

TEST(Ch2Problem7, Main) {
    auto l1 = create_llist({1, 2, 3, 4, 5});
    auto ret1 = is_intersect(l1, l1->pNext->pNext);
    EXPECT_EQ(ret1, l1->pNext->pNext);
    EXPECT_EQ(ret1->value, 3);

    auto l2 = create_llist({1, 2, 3, 4, 5, 6, 7});
    auto l3 = create_llist({10, 11, 12, 13});
    auto tail = l3;
    while (tail->pNext) {
        tail = tail->pNext;
    }
    tail->pNext = l2->pNext->pNext;
    auto ret2 = is_intersect(l2, l3);
    EXPECT_EQ(ret2, l2->pNext->pNext);
    EXPECT_EQ(ret2, tail->pNext);
}