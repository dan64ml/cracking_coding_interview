/**************************************************************************
 * Дана матрица N*N. Написать метод поворота матрицы на 90 градусов.
 **************************************************************************/
#include "chapter_1.h"

#include <vector>

using namespace std;

void rotate_helper(vector<vector<int>>& vec, int layer, int len) {
    int maxIdx = layer + len - 1;

    for (int i = 0; i < len - 1; ++i) {
        int tmp = vec[layer][layer + i];
        vec[layer][layer + i] = vec[layer + i][maxIdx];
        vec[layer + i][maxIdx] = vec[maxIdx][maxIdx - i];
        vec[maxIdx][maxIdx - i] = vec[maxIdx - i][layer];
        vec[maxIdx - i][layer] = tmp;
    }
}

// Задача на внимательность. Аккуратно рисуем поворот слоя и 
// внимательно следим за индексами. Сложность O(size()) и память
// O(1). 
void rotate90(vector<vector<int>>& vec) {
    for (int i = 0; i < vec.size() / 2; ++i) {
        rotate_helper(vec, i, vec.size() - 2*i);
    }
}