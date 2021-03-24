#ifndef CHAPTER_10_H_
#define CHAPTER_10_H_

#include <string>
#include <vector>
#include <optional>
#include <ostream>

namespace ch10 {

void MergeAB(std::vector<int>& a, size_t a_size, std::vector<int>& b);
void SortAnagram(std::vector<std::string>& vec);
std::optional<int> SearchNumber(const std::vector<int>& vec, int number);
int SearchInListy(const std::vector<int>& lst, int number);
int SearchWithEmpty(const std::vector<std::string>& vec, const std::string& str);
void DisplayDublicates(std::ostream& os, const std::vector<int>& vec);

} // namespace ch10

#endif // CHAPTER_10_H_