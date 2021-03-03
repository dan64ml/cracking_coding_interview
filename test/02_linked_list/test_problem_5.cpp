#include "chapter_2.h"

#include "gtest/gtest.h"

using namespace std;
using namespace ch02;

TEST(Ch2Problem5, ReverseOrder1) {
    auto lst1 = create_llist({0, 0, 1});
    auto lst2 = create_llist({3, 2, 1});
    auto ret = sum_list_reverse(lst1, lst2);
    for (auto d : {3, 2, 2}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}

TEST(Ch2Problem5, ReverseOrder2) {
    auto lst1 = create_llist({9, 9});
    auto lst2 = create_llist({1});
    auto ret = sum_list_reverse(lst1, lst2);
    for (auto d : {0, 0, 1}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}

TEST(Ch2Problem5, ForwardOrder1) {
    auto lst1 = create_llist({1, 0, 0});
    auto lst2 = create_llist({1, 2, 3});
    auto ret = sum_list_forward(lst1, lst2);
    for (auto d : {2, 2, 3}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}

TEST(Ch2Problem5, ForwardOrder2) {
    auto lst1 = create_llist({9, 9});
    auto lst2 = create_llist({1});
    auto ret = sum_list_forward(lst1, lst2);
    for (auto d : {1, 0, 0}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}

TEST(Ch2Problem5, Forward2Order1) {
    auto lst1 = create_llist({1, 0, 0});
    auto lst2 = create_llist({1, 2, 3});
    auto ret = sum_list_forward_1(lst1, lst2);
    for (auto d : {2, 2, 3}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}

TEST(Ch2Problem5, Forward2Order2) {
    auto lst1 = create_llist({9, 9});
    auto lst2 = create_llist({1});
    auto ret = sum_list_forward_1(lst1, lst2);
    for (auto d : {1, 0, 0}) {
        EXPECT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, d);
        ret = ret->pNext;
    }
    EXPECT_EQ(ret, nullptr);
}
