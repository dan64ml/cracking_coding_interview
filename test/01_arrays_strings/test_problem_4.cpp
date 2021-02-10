#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

TEST(Ch1Problem4, SpaceIgnoreCaseIgnore) {
    EXPECT_TRUE(is_palindrom(""));
    EXPECT_TRUE(is_palindrom("a b b "));
    EXPECT_TRUE(is_palindrom("AbBa"));
    EXPECT_TRUE(is_palindrom("    b b b "));
    EXPECT_TRUE(is_palindrom("zyxXZY"));
    EXPECT_TRUE(is_palindrom("A"));
    EXPECT_FALSE(is_palindrom("abcC"));
    EXPECT_FALSE(is_palindrom("vvvttt"));
}

TEST(Ch1Problem4, SpaceEnableCaseIgnore) {
    EXPECT_TRUE(is_palindrom("", false));
    EXPECT_FALSE(is_palindrom("a b b ", false));
    EXPECT_TRUE(is_palindrom("AbBa", false));
    EXPECT_FALSE(is_palindrom("    b b b ", false));
    EXPECT_TRUE(is_palindrom("zyxXZY", false));
    EXPECT_TRUE(is_palindrom("A", false));
    EXPECT_FALSE(is_palindrom("abcC", false));
    EXPECT_FALSE(is_palindrom("vvvttt", false));
}

TEST(Ch1Problem4, SpaceEnableCaseEnable) {
    EXPECT_TRUE(is_palindrom("", false, false));
    EXPECT_FALSE(is_palindrom("a b b ", false, false));
    EXPECT_FALSE(is_palindrom("AbBa", false, false));
    EXPECT_FALSE(is_palindrom("    b b b ", false, false));
    EXPECT_FALSE(is_palindrom("zyxXZY", false, false));
    EXPECT_TRUE(is_palindrom("A", false, false));
    EXPECT_FALSE(is_palindrom("abcC", false, false));
    EXPECT_FALSE(is_palindrom("vvvttt", false, false));
}