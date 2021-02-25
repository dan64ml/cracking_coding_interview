#include "chapter_3.h"

#include "gtest/gtest.h"

#include <stack>
#include <vector>

using namespace std;

TEST(Ch3Problem5, Test1) {
    vector vec {1, 1, 1};
    stack<int> s;
    for (auto e : vec) {
        s.push(e);
    }

    sort_stack(s);

    for (auto it = rbegin(vec); it != rend(vec); ++it) {
        EXPECT_EQ(*it, s.top());
        s.pop();
    }

    EXPECT_TRUE(s.empty());
}

TEST(Ch3Problem5, Test2) {
    vector vec {10, 71, 12, -2, 0, -100, 42};
    stack<int> s;
    for (auto e : vec) {
        s.push(e);
    }

    sort_stack(s);
    sort(begin(vec), end(vec));

    for (auto e : vec) {
        EXPECT_EQ(e, s.top());
        s.pop();
    }

    EXPECT_TRUE(s.empty());
}