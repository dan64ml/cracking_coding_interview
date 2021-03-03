#include "chapter_3.h"

#include "gtest/gtest.h"

#include <vector>

using namespace std;
using namespace ch03;

TEST(Ch3Problem4, Test1) {
    MyQueue<int> q;
    EXPECT_THROW({
        q.remove();
    }, runtime_error);
    EXPECT_THROW({
        q.peek();
    }, runtime_error);
}

TEST(Ch3Problem4, Test2) {
    MyQueue<int> q;
    vector vec {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};

    for (auto e : vec) {
        q.add(e);
    }
    for (auto e : vec) {
        EXPECT_EQ(q.peek(), e);
        EXPECT_EQ(q.remove(), e);
    }
}

TEST(Ch3Problem4, Test3) {
    MyQueue<int> q;

    q.add(1);
    q.add(2);
    q.add(3);
    EXPECT_EQ(q.remove(), 1);
    EXPECT_EQ(q.remove(), 2);
    q.add(4);
    EXPECT_EQ(q.remove(), 3);
    EXPECT_EQ(q.remove(), 4);
}