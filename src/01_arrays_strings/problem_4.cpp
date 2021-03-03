/*************************************************************************
 * Напишите метод, проверяющий, является строка перестановкой палиндрома.
 * Пропуск пробелов и игнорирование регистра букв - как опция.
 *************************************************************************/
#include "chapter_1.h"

#include <string>
#include <unordered_map>

using namespace std;

namespace ch01 {

// O(size()). Возможно немного оптимизировать, но асимптотика не изменится...
bool is_palindrom(const string& str, bool ignore_space, bool ignore_case) {
    unordered_map<string::value_type, int> counter;

    for (auto c : str) {
        if (ignore_space && (c == ' ')) {
            continue;
        }
        if (ignore_case) {
            c = tolower(c);
        }

        ++counter[c];
    }

    bool odd_found = false;

    for (auto [_, number] : counter) {
        if (number % 2) {
            if (odd_found) {
                return false;
            } else {
                odd_found = true;
            }
        }
    }

    return true;
}

} // namespace ch01
