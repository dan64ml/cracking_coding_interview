#ifndef CHAPTER_8_H_
#define CHAPTER_8_H_

#include <string>
#include <vector>
#include <stack>

namespace ch08 {

struct Point {
    int r;
    int c;
};

struct Box {
    int x;
    int y;
    int z;
};

using Color = int;

bool operator==(const ch08::Point& lhs, const ch08::Point& rhs);

int PathNumber(int n);
bool FindPath(const std::vector<std::vector<bool>>& maze, std::vector<Point>& path);
bool FindPath2(const std::vector<std::vector<bool>>& maze, std::vector<Point>& path);
int FindMagicIndex(const std::vector<int>& vec);
std::vector<std::string> GenerateSubsets(const std::vector<char>& vec);
int Mult(int num1, int num2);
void Hanoy(std::stack<char>& src, std::stack<char>& dest, std::stack<char>& tmp, int num);
std::vector<std::string> Permutation(const std::string& str);
std::vector<std::string> UniquePermutation(const std::string& str);
std::vector<std::string> GenerateParentheses(int num);
int Change1(int sum);
int Change2(int sum);
std::vector<std::vector<int>> AllQueens();
void FloodFill(std::vector<std::vector<Color>>& img, int row, int col, Color new_color);
int MaxHeight(std::vector<Box> box);

} // namespace ch08

#endif // CHAPTER_8_H_