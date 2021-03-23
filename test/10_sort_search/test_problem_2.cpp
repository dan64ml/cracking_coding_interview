#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem2, Test1) {
    vector<string> vec {"xyz", "acb", "bac", "yxz", "ab", "ba"};
    vector<string> result {"ab", "ba", "acb", "bac", "xyz", "yxz"};
    SortAnagram(vec);
    EXPECT_EQ(vec, result);
}