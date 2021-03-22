/*********************************************************************************
 * Написать алгоритм заливки изображения краской а-ля графический редактор.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>
#include <queue>

using namespace std;

namespace ch08 {

// В целом простая задача. Тонкий момент - какие соседние точки закрашивать. Есть
// смысл только соседей по горизонтали и вертикали. Заливка диагональных соседей
// приведет к "протечке" заливки через тонкие наклонные линии.
// Можно реализовать рекурсивно. Здесь реализация в цикле.
void FloodFill(vector<vector<Color>>& img, int row, int col, Color new_color) {
    Color base_color = img[row][col];

    queue<pair<int, int>> q;
    q.push({row, col});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r >= 0 && r < img.size() && c >= 0 && c < img.front().size() && img[r][c] == base_color) {
            img[r][c] = new_color;

            q.push({r - 1, c});
            q.push({r + 1, c});
            q.push({r, c - 1});
            q.push({r, c + 1});
        }
    }
}

} // namespace ch08
