/*******************************************************************************
 * Дан метод isSubstring проверяющий, является ли одна строка подстрокой другой.
 * Для двух строк s1 и s2 написать метод, определяющий получена ли одна сторока
 * из другой циклический сдвигом. isSubstring можно вызвать только один раз
 *******************************************************************************/
#include "chapter_1.h"

#include <string>

using namespace std;

namespace ch01 {

// Простая склейка строки из двух. Важно проверить одинаковость длины исходных строк.
bool is_shifted(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return false;
    }

    string tmp = s1 + s1;
    auto ret = tmp.find(s2);

    return (ret != string::npos);
}

} // namespace ch01
