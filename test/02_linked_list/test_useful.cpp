#include "chapter_2.h"

#include "gtest/gtest.h"

#include <initializer_list>

using namespace std;

TEST(Ch2Useful, CreateLList) {
    initializer_list<int> il1 = {};
    auto list = create_llist(il1);
    EXPECT_EQ(list, nullptr);

    list = create_llist({42});
    ASSERT_NE(list, nullptr);
    EXPECT_EQ(list->value, 42);
    EXPECT_EQ(list->pNext, nullptr);

    auto il2 = {42, 0, -42};
    vector<int> v = il2;
    list = create_llist(il2);
    for (int i = 0; i < 3; ++i) {
        ASSERT_NE(list, nullptr);
        EXPECT_EQ(list->value, v[i]);
        list = list->pNext;
    }
    EXPECT_EQ(list, nullptr);
}