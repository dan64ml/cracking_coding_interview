#ifndef CHAPTER_1_H_
#define CHAPTER_1_H_

#include <string>
#include <vector>

namespace ch01 {

bool is_unique_1(const std::string& str);
bool is_unique_2(std::string str);

bool is_permutation_1(const std::string& s1, const std::string& s2);
bool is_permutation_2(std::string s1, std::string s2);

void replace_spaces(std::string& str, int size);

bool is_palindrom(const std::string& str, bool ignore_space = true, bool ignore_case = true);

bool is_modifiable(std::string s1, std::string s2);

std::string compress(const std::string& str);

void rotate90(std::vector<std::vector<int>>& vec);

void replace_zeros(std::vector<std::vector<int>>& m);

bool is_shifted(const std::string& s1, const std::string& s2);

} // namespace ch01

#endif  // CHAPTER_1_H_