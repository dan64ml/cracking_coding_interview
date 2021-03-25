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
void HillSort(std::vector<int>& vec);

struct TrNode {
    TrNode(int num) : value(num) {}

    int value;
    TrNode* left = nullptr;
    TrNode* right = nullptr;
    int l_count = 0;
    int r_count = 0;
    int my_count = 1;
};

class Tracker {
    public:
        Tracker() = default;
        ~Tracker();
        void Track(int number);
        int GetRank(int number);

    private:
        TrNode* root_ = nullptr;

        void DtorHelper(TrNode* node);
};

} // namespace ch10

#endif // CHAPTER_10_H_