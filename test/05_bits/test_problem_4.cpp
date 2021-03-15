#include "chapter_5.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch05;

TEST (Ch5Problem4, Trivial) {
    EXPECT_EQ(GetNext(numeric_limits<uint>::max()), 0);
    EXPECT_EQ(GetPrev(0), 0);
    EXPECT_EQ(GetNext(1), 2);
    EXPECT_EQ(GetPrev(1), 0);
    EXPECT_EQ(GetPrev(2), 1);
}

TEST (Ch5Problem4, Test1) {
    EXPECT_EQ(GetNext(10), 12);
    EXPECT_EQ(GetPrev(10), 9);
}

int CountOnes(uint num) {
    int count = 0;
    while (num) {
        if (num & 0x1) {
            ++count;
        }

        num >>= 1;
    }

    return count;
}

TEST (Ch5Problem4, Test2) {
    EXPECT_EQ(CountOnes(0b110010100101), 6);

    uint num = 13948;
    int bit_num = CountOnes(num);
    uint prev = num - 1;
    while (CountOnes(prev) != bit_num) {
        --prev;
    }
    EXPECT_EQ(GetPrev(num), prev);

    uint next = num + 1;
    while (CountOnes(next) != bit_num) {
        ++next;
    }
    EXPECT_EQ(GetNext(num), next);
}

TEST (Ch5Problem4, Test3) {
    uint num = 0b100111;
    int bit_num = CountOnes(num);
    uint prev = num - 1;
    while (CountOnes(prev) != bit_num) {
        --prev;
    }
    EXPECT_EQ(GetPrev(num), prev);

    uint next = num + 1;
    while (CountOnes(next) != bit_num) {
        ++next;
    }
    EXPECT_EQ(GetNext(num), next);
}
