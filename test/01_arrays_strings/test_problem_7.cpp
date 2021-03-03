#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

using namespace std;
using namespace ch01;

TEST(Ch1Problem7, Trivial) {
    vector<vector<int>> in = {};
    vector<vector<int>> result = {};
    rotate90(in);
    EXPECT_EQ(in, result);

    in = {{42}};
    result= {{42}};
    rotate90(in);
    EXPECT_EQ(in, result);
}

TEST(Ch1Problem7, OddMatrix) {
    vector<vector<int>> in =   {{1, 2, 3},
                                {4, 5, 6},
                                {7, 8, 9}};
    vector<vector<int>> result = {{3, 6, 9},
                                {2, 5, 8},
                                {1, 4, 7}};
    rotate90(in);
    EXPECT_EQ(in, result);
}

TEST(Ch1Problem7, EvenMatrix) {
    vector<vector<int>> in =   {{1, 2, 3, 4},
                                {12, 13, 14, 5},
                                {11, 16, 15, 6},
                                {10, 9, 8, 7}};

    vector<vector<int>> result = {{4, 5, 6, 7},
                                {3, 14, 15, 8},
                                {2, 13, 16, 9},
                                {1, 12, 11, 10}};
    rotate90(in);
    EXPECT_EQ(in, result);
}