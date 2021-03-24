#include "chapter_10.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch10;

TEST(Ch10Problem5, Test1) {
    vector<string> vec {"a", "b", "c", "d", "e", "f", "g"};
    EXPECT_EQ(SearchWithEmpty(vec, "a"), 0);
    EXPECT_EQ(SearchWithEmpty(vec, "b"), 1);
    EXPECT_EQ(SearchWithEmpty(vec, "c"), 2);
    EXPECT_EQ(SearchWithEmpty(vec, "d"), 3);
    EXPECT_EQ(SearchWithEmpty(vec, "e"), 4);
    EXPECT_EQ(SearchWithEmpty(vec, "f"), 5);
    EXPECT_EQ(SearchWithEmpty(vec, "g"), 6);
    EXPECT_EQ(SearchWithEmpty(vec, "h"), -1);
}

TEST(Ch10Problem5, Test2) {
    vector<string> vec {"a", "b", "b", "b", "h", "r", "z"};
    EXPECT_EQ(SearchWithEmpty(vec, "a"), 0);
    EXPECT_EQ(SearchWithEmpty(vec, "h"), 4);
    EXPECT_EQ(SearchWithEmpty(vec, "z"), 6);
}

TEST(Ch10Problem5, Test3) {
    vector<string> vec {};
    EXPECT_EQ(SearchWithEmpty(vec, "a"), -1);
}

TEST(Ch10Problem5, Test4) {
    vector<string> vec {"", "", "", "", "", "", ""};
    EXPECT_EQ(SearchWithEmpty(vec, "c++"), -1);
    EXPECT_EQ(SearchWithEmpty(vec, "haskel"), -1);
}

TEST(Ch10Problem5, Test5) {
    vector<string> vec {"asm", "c++", "java", "pyton", "", "", ""};
    EXPECT_EQ(SearchWithEmpty(vec, "c++"), 1);
    EXPECT_EQ(SearchWithEmpty(vec, "haskel"), -1);
}

TEST(Ch10Problem5, Test6) {
    vector<string> vec {"", "", "asm", "c++", "", "java", "", "", "pyton", "", "", ""};
    EXPECT_EQ(SearchWithEmpty(vec, "c++"), 3);
    EXPECT_EQ(SearchWithEmpty(vec, "haskel"), -1);
    EXPECT_EQ(SearchWithEmpty(vec, "pyton"), 8);
}
