#include "chapter_2.h"

#include "gtest/gtest.h"

using namespace std;

TEST(Ch2Problem6, Trivial) {
    auto lst1 = create_llist({});
    EXPECT_TRUE(is_palindrom(lst1));

    auto lst2 = create_llist({5});
    EXPECT_TRUE(is_palindrom(lst2));

    auto lst3 = create_llist({3, 3});
    EXPECT_TRUE(is_palindrom(lst3));

    auto lst4 = create_llist({3, 7});
    EXPECT_FALSE(is_palindrom(lst4));
}

TEST(Ch2Problem6, Main) {
    auto lst1 = create_llist({1, 3, 1});
    EXPECT_TRUE(is_palindrom(lst1));

    auto lst2 = create_llist({1, 3, 5});
    EXPECT_FALSE(is_palindrom(lst2));

    auto lst3 = create_llist({1, 1, 1});
    EXPECT_TRUE(is_palindrom(lst3));

    auto lst4 = create_llist({1, 2, 3, 4, 5, 42, 5, 4, 3, 2, 1});
    EXPECT_TRUE(is_palindrom(lst4));

    auto lst5 = create_llist({1, 3, 5, 5, 3, 1});
    EXPECT_TRUE(is_palindrom(lst5));

    auto lst6 = create_llist({1, 3, 5, 7, 5, 4, 1});
    EXPECT_FALSE(is_palindrom(lst6));

    auto lst7 = create_llist({1, 2, 3, 4, 5, 6, 6, 5, 4, 4, 2, 1});
    EXPECT_FALSE(is_palindrom(lst7));
}