#include "chapter_2.h"

#include "gtest/gtest.h"

TEST(Ch2Problem1, Trivial) {
    EXPECT_NO_THROW({
        auto lst1 = create_llist({});
        auto ret1 = remove_duplicate(lst1);
        EXPECT_EQ(ret1, nullptr);

        auto lst2 = create_llist({42});
        auto ret2 = remove_duplicate(lst2);
        ASSERT_NE(ret2, nullptr);
        EXPECT_EQ(ret2->value, 42);
        EXPECT_EQ(ret2->pNext, nullptr);
    });
}

TEST(Ch2Problem1, Main) {
    const auto il1 = {1, 2, 3, 4, 5};
    EXPECT_NO_THROW({
        auto lst = create_llist(il1);
        auto ret = remove_duplicate(lst);
        for (auto v : il1) {
            ASSERT_NE(ret, nullptr);
            EXPECT_EQ(ret->value, v);
            ret = ret->pNext;
        }
        EXPECT_EQ(ret, nullptr);
    });

    auto il2 = {1, 1, 1, 2, 3, 4, 5, 5, 5, 5};
    EXPECT_NO_THROW({
        auto lst = create_llist(il2);
        auto ret = remove_duplicate(lst);
        for (auto v : il1) {
            ASSERT_NE(ret, nullptr);
            EXPECT_EQ(ret->value, v);
            ret = ret->pNext;
        }
        EXPECT_EQ(ret, nullptr);
    });

    auto il3 = {42, 42, 42, 42, 42};
    EXPECT_NO_THROW({
        auto lst = create_llist(il3);
        auto ret = remove_duplicate(lst);
        ASSERT_NE(ret, nullptr);
        EXPECT_EQ(ret->value, 42);
        EXPECT_EQ(ret->pNext, nullptr);
    });
}