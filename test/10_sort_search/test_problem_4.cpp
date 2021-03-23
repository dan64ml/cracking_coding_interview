#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem4, Test1) {
    vector<int> lst(100, -1);
    lst[0] = 1;
    EXPECT_EQ(SearchInListy(lst, 1), 0);
    EXPECT_EQ(SearchInListy(lst, 10), -1);
}

TEST(Ch10Problem4, Test2) {
    vector<int> lst(100, -1);
    lst[0] = 1;
    lst[1] = 3;
    lst[2] = 4;
    lst[3] = 7;
    lst[4] = 11;
    EXPECT_EQ(SearchInListy(lst, 11), 4);
    EXPECT_EQ(SearchInListy(lst, 10), -1);
    EXPECT_EQ(SearchInListy(lst, 42), -1);
}
