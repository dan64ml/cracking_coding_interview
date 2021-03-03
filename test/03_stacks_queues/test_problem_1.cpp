#include "chapter_3.h"

#include "gtest/gtest.h"

#include <vector>
#include <stack>

using namespace std;
using namespace ch03;

TEST(Ch3Problem1, TestSize) {
    FixedStack s1(3);
    for (int i = 0; i < 3; ++i) {
        EXPECT_TRUE(s1.isEmpty(i));
        EXPECT_THROW({
            s1.peek(i);
        }, std::runtime_error);
    }
    for (int i = 0; i < 3; ++i) {
        EXPECT_THROW({
            s1.pop(i);
        }, std::runtime_error);
    }

    FixedStack s2(3);
    for (int i = 0; i < 3; ++i) {
        EXPECT_NO_THROW({
            for (int j = 0; j < 3; ++j) {
                s2.push(i, j);
                EXPECT_FALSE(s2.isEmpty(i));
            }
        });
    }

    FixedStack s3(3);
    for (int i = 0; i < 3; ++i) {
        EXPECT_THROW({
            for (int j = 0; j < 4; ++j) {
                s3.push(i, j);
            }
        }, std::runtime_error);
    }
}

TEST(Ch3Problem1, TestData) {
    FixedStack s1(4);
    s1.push(0, 10);
    EXPECT_EQ(s1.peek(0), 10);
    EXPECT_THROW({
        s1.peek(1);
    }, std::runtime_error);
    EXPECT_THROW({
        s1.peek(2);
    }, std::runtime_error);
    EXPECT_EQ(s1.pop(0), 10);
    EXPECT_THROW({
        s1.peek(0);
    }, std::runtime_error);

    const int kStackSize = 7;
    FixedStack s2(kStackSize);
    for (int i = 0; i < 3; ++i) {
        for (int j = 1; j <= kStackSize; ++j) {
            s2.push(i, (3 + i) * j);
        }
    }
    for (int i = 0; i < 3; ++i) {
        for (int j = kStackSize; j > 0; --j) {
            EXPECT_EQ(s2.peek(i), (3 + i) * j);
            EXPECT_EQ(s2.pop(i), (3 + i) * j);
        }
        EXPECT_TRUE(s2.isEmpty(i));
    }
}

TEST(Ch3Problem1, DynSizeTest) {
    DynamicStack s(10);
    for (int i = 0; i < 3; ++i) {
        EXPECT_TRUE(s.isEmpty(i));
    }

    s.push(0, 42);
    EXPECT_FALSE(s.isEmpty(0));
    EXPECT_TRUE(s.isEmpty(1));
    EXPECT_TRUE(s.isEmpty(2));

    s.push(1, 142);
    EXPECT_FALSE(s.isEmpty(0));
    EXPECT_FALSE(s.isEmpty(1));
    EXPECT_TRUE(s.isEmpty(2));

    s.push(2, 142);
    EXPECT_FALSE(s.isEmpty(0));
    EXPECT_FALSE(s.isEmpty(1));
    EXPECT_FALSE(s.isEmpty(2));

    for (int i = 0; i < 3; ++i) {
        s.pop(i);
        EXPECT_TRUE(s.isEmpty(i));
    }

    for (int i = 0; i < 3; ++i) {
        EXPECT_THROW({
            s.pop(i);
        }, std::runtime_error);
    }

    int size = 42;
    DynamicStack s2(size);
    EXPECT_NO_THROW({
        for (int i = 0; i < size; ++i) {
            s2.push(0, i);
        }
    });
    EXPECT_THROW({
        s2.push(0, 42);
    }, std::runtime_error);
    EXPECT_THROW({
        s2.push(1, 42);
    }, std::runtime_error);
    EXPECT_THROW({
        s2.push(2, 42);
    }, std::runtime_error);
}

TEST(Ch3Problem1, DynData1) {
    int len = 10;
    DynamicStack s(len);

    vector<stack<int>> result(3);

    for (int i = 0; i < len; ++i) {
        int val = i + 123;
        s.push(i%3, val);
        result[i%3].push(val);
    }

    for (int i = 0; i < len; ++i) {
        int res = result[i%3].top();
        result[i%3].pop();
        EXPECT_EQ(s.peek(i%3), res);
        EXPECT_EQ(s.pop(i%3), res);
    }
}

TEST(Ch3Problem1, DynData2) {
    int len = 101;

    for (int i = 0; i < 3; ++i) {
        DynamicStack s(len);
        stack<int> result;

        for (int j = 0; j < len; ++j) {
            int value = j * 3;
            s.push(i, value);
            result.push(value);
        }
        for (int j = 0; j < len; ++j) {
            int value = result.top();
            result.pop();
            EXPECT_EQ(s.peek(i), value);
            EXPECT_EQ(s.pop(i), value);
        }
    }
}

TEST(Ch3Problem1, DynData3) {
    DynamicStack s(43);
    stack<int> result;

    s.push(0, 10);
    s.push(0, 11);
    s.push(0, 12);
    s.push(2, 30);
    s.push(2, 31);
    s.push(2, 32);

    for (int i = 0; i < 37; ++i) {
        int value = 200 + i;
        s.push(1, value);
        result.push(value);
    }

    EXPECT_EQ(s.pop(0), 12);
    EXPECT_EQ(s.pop(0), 11);
    EXPECT_EQ(s.pop(0), 10);
    EXPECT_EQ(s.pop(2), 32);
    EXPECT_EQ(s.pop(2), 31);
    EXPECT_EQ(s.pop(2), 30);

    for (int i = 0; i < 37; ++i) {
        int res = result.top();
        result.pop();
        EXPECT_EQ(s.pop(1), res);
    }
}