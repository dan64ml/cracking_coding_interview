#include "chapter_1.h"

#include "gtest/gtest.h"

#include <string>

using namespace std;

TEST(Ch1Problem8, Trivial) {
    vector<vector<int>> in = {{42}};
    vector<vector<int>> result = {{42}};
    replace_zeros(in);
    EXPECT_EQ(in, result);
    
    in = {{0}};
    result = {{0}};
    replace_zeros(in);
    EXPECT_EQ(in, result);
}

TEST(Ch1Problem8, RowColumn) {
    vector<vector<int>> in1 = {{42, 42, 42, 42, 42}};
    vector<vector<int>> result1 = {{42, 42, 42, 42, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);
    
    in1 = {{42, 42, 0, 42, 42}};
    result1 = {{0, 0, 0, 0, 0}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);
    
    vector<vector<int>> in2 = {{42}, {42}, {42}, {42}, {42}};
    vector<vector<int>> result2 = {{42}, {42}, {42}, {42}, {42}};
    replace_zeros(in2);
    EXPECT_EQ(in2, result2);

    in2 = {{42}, {42}, {42}, {42}, {0}};
    result2 = {{0}, {0}, {0}, {0}, {0}};
    replace_zeros(in2);
    EXPECT_EQ(in2, result2);
}

TEST(Ch1Problem8, Matrix) {
    vector<vector<int>> in1 = {{42, 42, 42, 42, 42},
                                {42, 42, 42, 42, 42},
                                {42, 42, 42, 42, 42}};
    vector<vector<int>> result1 = {{42, 42, 42, 42, 42},
                                {42, 42, 42, 42, 42},
                                {42, 42, 42, 42, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);

    in1 = {{0, 42, 42, 42, 42},
            {42, 42, 42, 42, 42},
            {42, 42, 42, 42, 42}};
    result1 = {{0, 0, 0, 0, 0},
            {0, 42, 42, 42, 42},
            {0, 42, 42, 42, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);

    in1 = {{42, 42, 42, 42, 42},
            {0, 42, 42, 42, 42},
            {42, 42, 42, 42, 42}};
    result1 = {{0, 42, 42, 42, 42},
            {0, 0, 0, 0, 0},
            {0, 42, 42, 42, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);

    in1 = {{42, 42, 0, 42, 42},
            {42, 42, 42, 42, 42},
            {42, 42, 42, 42, 42}};
    result1 = {{0, 0, 0, 0, 0},
            {42, 42, 0, 42, 42},
            {42, 42, 0, 42, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);

    in1 = {{42, 42, 42, 42, 42},
            {42, 42, 42, 0, 42},
            {42, 42, 42, 42, 42}};
    result1 = {{42, 42, 42, 0, 42},
               {0, 0, 0, 0, 0},
               {42, 42, 42, 0, 42}};
    replace_zeros(in1);
    EXPECT_EQ(in1, result1);
}