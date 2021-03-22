#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem10, Test1) {
    vector<vector<Color>> img = {{42, 42, 42}};
    vector<vector<Color>> answer = {{255, 255, 255}};
    FloodFill(img, 0, 1, 255);
    EXPECT_EQ(img, answer);
}

TEST(Ch8Problem10, Test2) {
    vector<vector<Color>> img = {{42, 42, 0, 42, 42}};
    vector<vector<Color>> answer = {{255, 255, 0, 42, 42}}; 
    FloodFill(img, 0, 1, 255);
    EXPECT_EQ(img, answer);
}

TEST(Ch8Problem10, Test3) {
    vector<vector<Color>> img = {{42, 42, 42, 42, 42},
                                 {42, 42, 42, 42, 11},
                                 {42, 42, 42, 11, 42},
                                 {42, 42, 11, 42, 42},
                                 {42, 11, 42, 42, 42}};

    vector<vector<Color>> answer = {{255, 255, 255, 255, 255},
                                 {255, 255, 255, 255, 11},
                                 {255, 255, 255, 11, 42},
                                 {255, 255, 11, 42, 42},
                                 {255, 11, 42, 42, 42}};

    FloodFill(img, 1, 1, 255);
    EXPECT_EQ(img, answer);
}

TEST(Ch8Problem10, Test4) {
    vector<vector<Color>> img = {{42, 42, 22, 42, 42},
                                 {42, 42, 22, 42, 42},
                                 {42, 42, 22, 42, 42},
                                 {11, 42, 22, 42, 42},
                                 {42, 11, 22, 42, 42}};

    vector<vector<Color>> answer = {{33, 33, 22, 42, 42},
                                 {33, 33, 22, 42, 42},
                                 {33, 33, 22, 42, 42},
                                 {11, 33, 22, 42, 42},
                                 {42, 11, 22, 42, 42}};

    FloodFill(img, 1, 1, 33);
    EXPECT_EQ(img, answer);
}

TEST(Ch8Problem10, Test5) {
    vector<vector<Color>> img = {{42, 42, 22, 42, 42},
                                 {42, 42, 22, 42, 22},
                                 {42, 42, 22, 42, 22},
                                 {11, 42, 22, 42, 42},
                                 {42, 11, 22, 42, 42}};

    vector<vector<Color>> answer = {{42, 42, 33, 42, 42},
                                 {42, 42, 33, 42, 22},
                                 {42, 42, 33, 42, 22},
                                 {11, 42, 33, 42, 42},
                                 {42, 11, 33, 42, 42}};

    FloodFill(img, 1, 2, 33);
    EXPECT_EQ(img, answer);
}
