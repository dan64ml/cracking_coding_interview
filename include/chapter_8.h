#ifndef CHAPTER_8_H_
#define CHAPTER_8_H_

#include <string>
#include <vector>

namespace ch08 {

struct Point {
    int r;
    int c;
};

bool operator==(const ch08::Point& lhs, const ch08::Point& rhs);

int PathNumber(int n);
bool FindPath(const std::vector<std::vector<bool>>& maze, std::vector<Point>& path);
bool FindPath2(const std::vector<std::vector<bool>>& maze, std::vector<Point>& path);

} // namespace ch08

#endif // CHAPTER_8_H_