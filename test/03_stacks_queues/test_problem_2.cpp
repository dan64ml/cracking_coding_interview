#include "chapter_3.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;

TEST(Ch3Problem2, Test1) {
    MinStack<int> s;
    vector<int> vec {3, 2, 1};

    for (auto e : vec) {
        s.push(e);
        EXPECT_EQ(s.min(), e);
    }

    s.pop();
    EXPECT_EQ(s.min(), 2);
    s.pop();
    EXPECT_EQ(s.min(), 3);
}

TEST(Ch3Problem2, Test2) {
    MinStack<int> s;
    vector<int> vec {3, 3, 2, 2, 1, 1};

    for (auto e : vec) {
        s.push(e);
        EXPECT_EQ(s.min(), e);
    }

    s.pop();
    EXPECT_EQ(s.min(), 1);
    s.pop();
    EXPECT_EQ(s.min(), 2);
    s.pop();
    EXPECT_EQ(s.min(), 2);
    s.pop();
    EXPECT_EQ(s.min(), 3);
    s.pop();
    EXPECT_EQ(s.min(), 3);
}

TEST(Ch3Problem2, Test3) {
    MinStack<int> s;
    vector<int> vec {3, 2, 1, 7, 10};

    for (auto e : vec) {
        s.push(e);
    }

    EXPECT_EQ(s.min(), 1);
    s.push(-100);
    EXPECT_EQ(s.min(), -100);
    s.pop();
    EXPECT_EQ(s.min(), 1);
    s.pop();
    EXPECT_EQ(s.min(), 1);
    s.pop();
    EXPECT_EQ(s.min(), 1);
    s.pop();
    EXPECT_EQ(s.min(), 2);
    s.pop();
    EXPECT_EQ(s.min(), 3);
}