/*************************************************************************
 * Реализуйте алгоритм, определяющий, все ли символы в строке встречаются
 * только один раз. А если при этом запрещено исnользование дополнительных
 * структур данных?
 *************************************************************************/
#include "chapter_1.h"

#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

namespace ch01 {

// O(size()) и по времени и по памяти. Если известен набор допустимых символов в строке
// unordered_set можно заменить массивом, улучшив постоянный множитель. 
bool is_unique_1(const string& str) {
    unordered_set<string::value_type> counter;

    for (auto c : str) {
        if (counter.count(c)) {
            return false;
        } else {
            counter.insert(c);
        }
    }

    return true;
}

// Без доппамяти: либо брутфорс со сложностью O(N^2)
// Либо отсортировав строку - O(N*lgN)
bool is_unique_2(string str) {
    sort(begin(str), end(str));
    for (size_t i = 0; i + 1 < str.size(); ++i) {
        if (str[i] == str[i + 1]) {
            return false;
        }
    }

    return true;
}

} // namespace ch01
