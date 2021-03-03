/**************************************************************************
 * Дана матрица M*N. Написать метод, заполняющий нулями строку и столбец
 * каждого нулевого элемента. 
 **************************************************************************/
#include "chapter_1.h"

#include <vector>

using namespace std;

namespace ch01 {

// Задача легко решается с использованием O(N + M) дополнительной памяти (реально почти на порядок меньше)
// Можно обойтись O(1) доппамяти если хранить результаты прохода по матрице в нулевой строке и нулевом
// столбце. Это решение некрасиво, т.к. требует двух специальных обработок нулевых строки и столбца.
// Сложность в любом случае O(M*N).
void replace_zeros(vector<vector<int>>& m) {
    vector<bool> rowflags(m.size(), false);
    vector<bool> colflags(m.front().size(), false);

    for (size_t row = 0; row < m.size(); ++row) {
        for (size_t col = 0; col < m.front().size(); ++col) {
            if (m[row][col] == 0) {
                rowflags[row] = true;
                colflags[col] = true;
            }
        }
    }

    for (size_t i = 0; i < m.size(); ++i) {
        if (rowflags[i]) {
            for (size_t j = 0; j < m.front().size(); ++j) {
                m[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < m.front().size(); ++i) {
        if (colflags[i]) {
            for (size_t j = 0; j < m.size(); ++j) {
                m[j][i] = 0;
            }
        }
    }
}

} // namespace ch01
