/*********************************************************************************
 * Дан отсортированный массив строк, в котором могут присутствовать пустые строки.
 * Написать метод определения позиции заданной строки.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>
#include <string>

using namespace std;

namespace ch10 {

// Задача на аккуратную реализацию. Сама идея банальна: пародия на бинарный поиск.
// Выбирая средний элемент мы можем попасть на пустую строку. Для принятия решения
// где продолжать поиск нам обязательно нужна НЕ пустая строка. И здесь уже единственный
// вариант - линейный поиск. Шагаем влево и вправо одновременно пока не найдем непустую
// строку. Если дошли до границ интервала - значит искомой строки нет вообще.
// Сложность в худшем случае O(N).
int SearchWithEmpty(const vector<string>& vec, const string& str) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (vec[mid].empty()) {
            int l = mid - 1;
            int r = mid + 1;
            while (true) {
                if (l < left && r > right) {
                    return -1;
                }
                if (l >= left && !vec[l].empty()) {
                    mid = l;
                    break;
                }
                if (r <= right && !vec[r].empty()) {
                    mid = r;
                    break;
                }

                --l;
                ++r;
            }
        }

        if (vec[mid] == str) {
            return mid;
        } else if (vec[mid] < str) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

} // namespace ch10
