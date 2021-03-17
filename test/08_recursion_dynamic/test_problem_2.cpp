#include "chapter_8.h"

#include "gtest/gtest.h"

#include <limits>

using namespace std;
using namespace ch08;

TEST(Ch8Problem2, Test1) {
    vector<vector<bool>> maze(3, vector<bool>(4, true));
    vector<Point> path;
    EXPECT_TRUE(FindPath(maze, path));
    vector<Point> answer {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {2, 3}};
    EXPECT_EQ(path, answer);

    maze[0][2] = false;
    maze[1][2] = false;
    maze[2][2] = false;
    path.clear();
    EXPECT_FALSE(FindPath(maze, path));

    maze[0][2] = true;
    path.clear();
    EXPECT_TRUE(FindPath(maze, path));
    vector<Point> answer1 {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    EXPECT_EQ(path, answer1);
}

TEST(Ch8Problem2, Test2) {
    vector<vector<bool>> maze(3, vector<bool>(4, true));
    vector<Point> path;
    EXPECT_TRUE(FindPath2(maze, path));
    vector<Point> answer {{0, 0}, {1, 0}, {2, 0}, {2, 1}, {2, 2}, {2, 3}};
    EXPECT_EQ(path, answer);

    maze[0][2] = false;
    maze[1][2] = false;
    maze[2][2] = false;
    path.clear();
    EXPECT_FALSE(FindPath2(maze, path));

    maze[0][2] = true;
    path.clear();
    EXPECT_TRUE(FindPath2(maze, path));
    vector<Point> answer1 {{0, 0}, {0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    EXPECT_EQ(path, answer1);
}
