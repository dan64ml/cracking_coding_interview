#include "chapter_2.h"

#include "gtest/gtest.h"

#include <unordered_map>

using namespace std;

TEST(Ch2Problem4, Trivial) {
    auto lst1 = create_llist({});
    auto ret1 = regroup(lst1, 42);
    EXPECT_EQ(ret1, nullptr);

    auto lst2 = create_llist({1});
    auto ret2 = regroup(lst2, 42);
    EXPECT_NE(ret2, nullptr);
    EXPECT_EQ(ret2->value, 1);
    EXPECT_EQ(ret2->pNext, nullptr);

    auto lst3 = create_llist({142});
    auto ret3 = regroup(lst3, 42);
    EXPECT_NE(ret3, nullptr);
    EXPECT_EQ(ret3->value, 142);
    EXPECT_EQ(ret3->pNext, nullptr);
}

void check_list(Node* node, int border, const initializer_list<int>& pattern) {
    // check the order
    bool jump = false;
    auto current = node;
    while (current) {
        if (jump) {
            EXPECT_GE(current->value, border);
        } else {
            if (current->value >= border) {
                jump = true;
            } 
        }

        current =current->pNext;
    }

    // check all the values
    unordered_map<int, int> counter;
    for (auto v : pattern) {
        ++counter[v];
    }
    current = node;
    while (current) {
        --counter[current->value];
        current = current->pNext;
    }
    for (auto [_, num] : counter) {
        EXPECT_EQ(num, 0);
    }
}

TEST(Ch2Problem4, Main) {
    auto il1 = {1, 2, 3, 4, 5, 6, 7, 8};
    int border1 = 5;
    auto lst1 = create_llist(il1);
    auto ret1 = regroup(lst1, border1);
    EXPECT_NE(ret1, nullptr);
    check_list(ret1, border1, il1);

    auto il2 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int border2 = 4;
    auto lst2 = create_llist(il2);
    auto ret2 = regroup(lst2, border2);
    EXPECT_NE(ret2, nullptr);
    check_list(ret2, border2, il2);

    auto il3 = {1, 9, 3, 17, 6, 5, 11, 23, 42, 1, 18, 30, 1};
    int border3 = 13;
    auto lst3 = create_llist(il3);
    auto ret3 = regroup(lst3, border3);
    EXPECT_NE(ret3, nullptr);
    check_list(ret3, border3, il3);

}