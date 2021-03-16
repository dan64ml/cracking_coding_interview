#include "chapter_5.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch05;

TEST(Ch5Problem8, Trivial) {
    vector<byte> v1(6);
    vector<byte> v2(6);
    vector<byte> ret(6, byte(0));
    ret[0] = byte(0xFF);
    ret[1] = ret[0];

    DrawLine(v1, 24, 0, 15, 0);
    DrawLine2(v2, 24, 0, 15, 0);
    EXPECT_EQ(v1, ret);
    EXPECT_EQ(v2, ret);
}

TEST(Ch5Problem8, Test1) {
    vector<byte> v1(6);
    vector<byte> v2(6);
    vector<byte> ret(6, byte(0));
    ret[0] = byte(0x0F);
    ret[1] = byte(0xF0);

    DrawLine(v1, 24, 4, 11, 0);
    DrawLine2(v2, 24, 4, 11, 0);
    EXPECT_EQ(v1, ret);
    EXPECT_EQ(v2, ret);
}

TEST(Ch5Problem8, Test2) {
    vector<byte> v1(6);
    vector<byte> v2(6);
    vector<byte> ret(6, byte(0));
    ret[0] = byte(0x3E);

    DrawLine(v1, 24, 2, 6, 0);
    DrawLine2(v2, 24, 2, 6, 0);
    EXPECT_EQ(v1, ret);
    EXPECT_EQ(v2, ret);
}


TEST(Ch5Problem8, Test3) {
    vector<byte> v1(60);
    vector<byte> v2(60);

    DrawLine(v1, 96, 13, 81, 3);
    DrawLine2(v2, 96, 13, 81, 3);
    EXPECT_EQ(v1, v2);
}

TEST(Ch5Problem8, Test4) {
    vector<byte> v1(6);
    vector<byte> v2(6);
    vector<byte> ret(6);
    ret[1] = byte(0x8);

    DrawLine(v1, 24, 12, 12, 0);
    DrawLine2(v2, 24, 12, 12, 0);
    EXPECT_EQ(v1, ret);
    EXPECT_EQ(v2, ret);
}