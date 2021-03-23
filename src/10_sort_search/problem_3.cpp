/*********************************************************************************
 * Дан отсортированный массив циклически сдвинутый неизвестное количество раз.
 * Написать алгоритм поиска элемента в массиве.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>
#include <optional>

using namespace std;

namespace ch10 {

// Авторская идея ковыряться со сдвинутым массивом мне не нравится. Зная
// сдвиг начала массива легко пересчитать индексы и реализовать обычный
// бинарный поиск.
// Сдвиг тоже ищется модифицированным бинарным поиском. Нам нужно, чтобы
// левый и правый индексы оказались на соседних позициях, при этом элемент
// слева был строго больше элемента справа. Это и есть наш инвариант цикла.
// В этом случае при выходе из цикла правый индекс будет равен смещению.
// Т.к. и смещение и сам элемент ищутся чистым бинарным поиском, сложность
// в отличии от авторского решения всегда O(lgN).
optional<int> SearchNumber(const vector<int>& vec, int number) {
    // find the shift
    int left = 0;
    int right = (vec.front() <= vec.back()) ? 0 : vec.size() - 1;
    while (right - left > 1) {
        int mid = (right + left) / 2;
        if (vec[left] > vec[mid]) {
            right = mid;
        } else {
            left = mid;
        }
    }

    int shift = right;
    auto idx = [shift, sz = vec.size()](int i) { return (i + shift) % sz; };

    int l = 0;
    int r = vec.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (vec[idx(mid)] == number) {
            return idx(mid);
        } else if (vec[idx(mid)] < number) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return nullopt;
}

} // namespace ch10
