/*********************************************************************************
 * Написать метод генерации всех перестановок строки, состоящей из уникальных 
 * символов.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>
#include <string>

using namespace std;

namespace ch08 {

void PHelper(const string& str, vector<bool>& is_free, vector<string>& result, string& ps) {
    if (ps.size() == str.size()) {
        result.push_back(ps);
        return;
    }

    for (size_t i = 0; i < str.size(); ++i) {
        if (is_free[i]) {
            is_free[i] = false;
            ps.push_back(str[i]);

            PHelper(str, is_free, result, ps);

            ps.pop_back();
            is_free[i] = true;
        }
    }
}

// Фактически реализация определения перестановки. На первое место
// ставим любой из n символов. На второе - любой из оставшихся n-1
// и т.д. Чтобы не удалять из строки использованные символы отмечаем
// их в отдельном векторе. O(n!)...
vector<string> Permutation(const string& str) {
    vector<string> result;
    vector<bool> is_free(str.size(), true);
    string ps;

    PHelper(str, is_free, result, ps);

    return result;
}

} // namespace ch08
