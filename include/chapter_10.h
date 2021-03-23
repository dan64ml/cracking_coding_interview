#ifndef CHAPTER_10_H_
#define CHAPTER_10_H_

#include <string>
#include <vector>
#include <optional>

namespace ch10 {

void MergeAB(std::vector<int>& a, size_t a_size, std::vector<int>& b);
void SortAnagram(std::vector<std::string>& vec);
std::optional<int> SearchNumber(const std::vector<int>& vec, int number);

} // namespace ch10

#endif // CHAPTER_10_H_