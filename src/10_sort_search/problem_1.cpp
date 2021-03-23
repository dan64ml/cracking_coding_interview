/*********************************************************************************
 * Даны два отсортированных массива А и В. В конце массива А есть достаточно места
 * для данных из массива В. Написать метод объединения массивов, сохраняющий 
 * сортировку.
 ********************************************************************************/

#include "chapter_10.h"

#include <vector>

using namespace std;

namespace ch10 {

// Задача для разминки, просто начинаем заполнять А с конца.
// Есть некрасивый момент - если a_size = 0, алгоритм упадет.
// В принципе фиксится проверкой a_idx на равенство numeric_limits<size_T>::max()...
void MergeAB(vector<int>& a, size_t a_size, vector<int>& b) {
    size_t dest = a.size() - 1;
    size_t a_idx = a_size - 1;
    size_t b_idx = b.size() - 1;

    while (true) {
        if (a[a_idx] > b[b_idx]) {
            a[dest--] = a[a_idx--];
        } else {
            a[dest--] = b[b_idx];
            if (b_idx == 0) {
                return;
            } else {
                --b_idx;
            }
        }
    }
}

} // namespace ch10
