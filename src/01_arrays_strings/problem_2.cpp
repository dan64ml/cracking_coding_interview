/**********************************************************
 * Для двух строк напишите метод, определяющий, является ли
 * одна строка перестановкой другой.
 * ********************************************************/

#include "chapter_1.h"

#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Дополнительная память O(size()), сложность O(size())
bool is_permutation_1(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    unordered_map<string::value_type, int> counter;
    
    for (auto c : s1) {
        ++counter[c];
    }
    for (auto c : s2) {
        if (counter.count(c) == 0) {
            return false;
        } else {
            --counter[c];
        }
    }

    return true;
}

// O(n*lgn)
bool is_permutation_2(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    sort(begin(s1), end(s1));
    sort(begin(s2), end(s2));

    return s1 == s2;
}
