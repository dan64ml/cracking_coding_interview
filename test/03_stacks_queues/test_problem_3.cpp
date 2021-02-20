#include "chapter_3.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;

TEST(Ch3Problem3, S1Test1) {
    SetOfStack s(3);
    vector<int> vec {1, 2, 3, 5, 6, 7, 8, 11, 3, 0};
    for (auto e : vec) {
        s.push(e);
        EXPECT_EQ(s.peek(), e);
    }

    for (auto it = rbegin(vec); it != rend(vec); ++it) {
        auto elem = s.pop();
        EXPECT_EQ(elem, *it);
    }

    EXPECT_TRUE(s.empty());
}

TEST(Ch3Problem3, S1Test2) {
    SetOfStack s(3);
    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto e : vec) {
        s.push(e);
    }

    EXPECT_EQ(s.popAt(0), 3);
    EXPECT_EQ(s.popAt(0), 2);
    EXPECT_EQ(s.popAt(0), 1);

    EXPECT_EQ(s.popAt(0), 6);
    EXPECT_EQ(s.popAt(0), 5);
    EXPECT_EQ(s.popAt(0), 4);

    EXPECT_EQ(s.popAt(0), 9);
    EXPECT_EQ(s.popAt(0), 8);
    EXPECT_EQ(s.popAt(0), 7);

    EXPECT_EQ(s.pop(), 10);
    EXPECT_THROW({
        s.pop();
    }, runtime_error);
}

TEST(Ch3Problem3, S2Test1) {
    SetOfStack2 s(3);
    vector<int> vec {1, 2, 3, 5, 6, 7, 8, 11, 3, 0};
    for (auto e : vec) {
        s.push(e);
        EXPECT_EQ(s.peek(), e);
    }

    for (auto it = rbegin(vec); it != rend(vec); ++it) {
        auto elem = s.pop();
        EXPECT_EQ(elem, *it);
    }

    EXPECT_TRUE(s.empty());
}

TEST(Ch3Problem3, S2Test2) {
    SetOfStack2 s(3);
    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto e : vec) {
        s.push(e);
    }

    for (size_t i = 2; i < vec.size(); ++i) {
        EXPECT_EQ(s.popAt(0), vec[i]);
    }

    EXPECT_EQ(s.pop(), 2);
    EXPECT_EQ(s.pop(), 1);
    EXPECT_THROW({
        s.pop();
    }, runtime_error);
}