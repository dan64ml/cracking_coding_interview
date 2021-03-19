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

} // namespace ch08

#endif // CHAPTER_8_H_