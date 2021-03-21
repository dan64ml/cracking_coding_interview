/*********************************************************************************
 * Написать алгоритм, находящий все варианты расстановки 8 ферзей на шахматной
 * доске.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>

using namespace std;

namespace ch08 {

const int kDeskSize = 8;

bool IsAvaible(vector<int>& rows, int col, int row) {
    for (int i = 0; i < col; ++i) {
        if (rows[i] == row) {
            return false;
        }
    }

    for (int i = 0; i < col; ++ i) {
        if (col - i == abs(row - rows[i])) {
            return false;
        }
    }

    return true;
}

void AQHelper(vector<int>& rows, int col, vector<vector<int>>& result) {
    if (col == kDeskSize) {
        result.push_back(rows);
        return;
    }

    for (int r = 0; r < kDeskSize; ++r) {
        if (IsAvaible(rows, col, r)) {
            rows[col] = r;
            AQHelper(rows, col + 1, result);
            rows[col] = -1;
        }
    }
}

// Рекурсия с возвратом и полный перебор всех вариантов. При кажущейся заоблачной
// сложности ветви рекурсии очень быстро обрезаются, не уходя далево вглубь.
// Из-за того, что в одном столбце в принципе не может быть больше или меньше одного
// ферзя, вместо матрицы доску можно представить одномерным вектором с номерами рядов,
// занятых ферзями.
vector<vector<int>> AllQueens() {
    vector<vector<int>> result;
    vector<int> rows(kDeskSize);

    AQHelper(rows, 0, result);

    return result;
}

} // namespace ch08
