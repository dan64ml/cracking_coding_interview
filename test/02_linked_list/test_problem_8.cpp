#include "chapter_2.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch02;

TEST(Ch2Problem8, Trivial) {
    auto lst1 = create_llist({});
    EXPECT_EQ(find_loop(lst1), nullptr);

    auto lst2 = create_llist({1, 2, 3, 4, 5, 6, 7});
    EXPECT_EQ(find_loop(lst2), nullptr);

    auto lst3 = create_llist({1});
    EXPECT_EQ(find_loop(lst3), nullptr);
}

TEST(Ch2Problem8, Problem8) {
    auto lst1 = create_llist({1, 2, 3, 4, 5});
    auto tail1 = find_tail(lst1);
    tail1->pNext = lst1->pNext->pNext;
    EXPECT_EQ(find_loop(lst1), lst1->pNext->pNext);

    auto lst2 = create_llist({1, 2, 3, 4, 5});
    auto tail2 = find_tail(lst2);
    tail2->pNext = lst2;
    EXPECT_EQ(find_loop(lst2), lst2);

    auto lst3 = create_llist({1, 2, 3, 4, 5, 6});
    auto tail3 = find_tail(lst3);
    tail3->pNext = tail3;
    EXPECT_EQ(find_loop(lst3), tail3);
}