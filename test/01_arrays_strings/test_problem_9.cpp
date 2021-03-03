#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>
#include <algorithm>

using namespace std;
using namespace ch01;

TEST(Ch1Problem9, Trivial) {
    string s1 = "", s2 = "";
    EXPECT_TRUE(is_shifted(s1, s2));

    s1 = "";
    s2 = "blablabla";
    EXPECT_FALSE(is_shifted(s1, s2));

    s1 = "blablabla";
    s2 = "";
    EXPECT_FALSE(is_shifted(s1, s2));

    s1 = "blablabla";
    s2 = "blablabla";
    EXPECT_TRUE(is_shifted(s1, s2));
    
    s1 = string(1'000'000, 'v');
    s2 = string(1'000'000, 'v');
    EXPECT_TRUE(is_shifted(s1, s2));
}

TEST(Ch1Problem9, Shift) {
    string s1 = "123456789qwerty---";
    string s2 = s1;
    rotate(begin(s2), begin(s2) + 1, end(s2));
    EXPECT_TRUE(is_shifted(s1, s2));

    s2 = s1;
    rotate(begin(s2), begin(s2) + 10, end(s2));
    EXPECT_TRUE(is_shifted(s1, s2));

    s2 = s1;
    rotate(rbegin(s2), rbegin(s2) + 1, rend(s2));
    EXPECT_TRUE(is_shifted(s1, s2));

    s2 = s1;
    rotate(rbegin(s2), rbegin(s2) + 13, rend(s2));
    EXPECT_TRUE(is_shifted(s1, s2));
}