/**************************************************************************
 * Напишите метод, проверяющий, находятся ли две строки на расстоянии одной
 * (или нуля) модификации. Модификации: вставить/удалить/заменить символ.
 **************************************************************************/
#include "chapter_1.h"

#include <string>

using namespace std;

// Две простые мысли: вставка и удаление суть одна модификация. Она имеет смысл только
// для строк с длиной, отличающейся на единицу. 
// Замена имеет смысл только для строк равной длины.
// Сложность O(size())
bool is_modifiable(string s1, string s2) {
    if (s1.size() > s2.size()) {
        swap(s1, s2);
    }

    if (s1.size() == s2.size()) {
        int mods = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                if (mods == 0) {
                    ++mods;
                } else {
                    return false;
                }
            }
        }
        return true;
    } else if (s2.size() - s1.size() == 1) {
        int mods = 0;
        for (size_t i = 0, idx = 0; i < s1.size(); ++i, ++idx) {
            if (s1[i] != s2[idx]) {
                if (mods == 0 && s1[i] == s2[++idx]) {
                    ++mods;
                } else {
                    return false;
                }
            } 
        }
        return true;
    } else {
        return false;
    }
}