#include "chapter_2.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;

const static int ERROR_VALUE = numeric_limits<int>::min();

TEST(Ch2Problem2, Trivial) {
    auto emptyList = create_llist({});
    auto ret = get_kth(emptyList, 0);
    EXPECT_EQ(ret, ERROR_VALUE);

    ret = get_kth(emptyList, 1);
    EXPECT_EQ(ret, ERROR_VALUE);

    ret = get_kth(emptyList, 10);
    EXPECT_EQ(ret, ERROR_VALUE);
}

TEST(Ch2Problem2, Main) {
    auto lst1 = create_llist({42});
    auto ret1 = get_kth(lst1, 1);
    EXPECT_EQ(ret1, 42);

    auto lst2 = create_llist({42});
    auto ret2 = get_kth(lst2, 2);
    EXPECT_EQ(ret2, ERROR_VALUE);

    auto lst3 = create_llist({1, 2, 3, 4, 5, 6, 7});
    auto ret3 = get_kth(lst3, 8);
    EXPECT_EQ(ret3, ERROR_VALUE);
    ret3 = get_kth(lst3, 7);
    EXPECT_EQ(ret3, 1);
    ret3 = get_kth(lst3, 1);
    EXPECT_EQ(ret3, 7);
    ret3 = get_kth(lst3, 3);
    EXPECT_EQ(ret3, 5);
}