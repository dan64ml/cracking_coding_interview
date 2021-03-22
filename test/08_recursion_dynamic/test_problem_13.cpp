#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem13, Test1) {
    vector<Box> box {{10, 20, 30}};
    EXPECT_EQ(MaxHeight(box), 30);
    vector<Box> box2 {{10, 20, 30}, {10, 20, 30}};
    EXPECT_EQ(MaxHeight(box2), 30);
    vector<Box> box3 {{10, 20, 25}, {100, 200, 30}};
    EXPECT_EQ(MaxHeight(box3), 55);
}

TEST(Ch8Problem13, Test2) {
    vector<Box> box {{100, 100, 30}, {150, 100, 20}, {50, 50, 15}, {10, 10, 50}};
    EXPECT_EQ(MaxHeight(box), 50);
}

TEST(Ch8Problem13, Test3) {
    vector<Box> box {{100, 100, 30}, {150, 100, 20}, {50, 50, 15}, {10, 10, 50}, {5, 5, 35}};
    EXPECT_EQ(MaxHeight(box), 85);
}
