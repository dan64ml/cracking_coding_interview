#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

TEST(Ch1Problem5, Test) {
    EXPECT_TRUE(is_modifiable("", " "));
    EXPECT_TRUE(is_modifiable("pale", "pale"));
    EXPECT_TRUE(is_modifiable("pale", "ple"));
    EXPECT_TRUE(is_modifiable("pales", "pale"));
    EXPECT_TRUE(is_modifiable("pale", "bale"));
    EXPECT_FALSE(is_modifiable("pale", "bake"));
    EXPECT_FALSE(is_modifiable("paleha", "poleho"));
}