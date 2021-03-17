/*********************************************************************************
 * Робот стоит в верхнем левом углу сетки из r строк и с столбцов. Часть клеток
 * поля заблокирована. Робот может двигаться только вниз и направо. Построить 
 * маршрут до нижнего правого угла.
 ********************************************************************************/

#include "chapter_8.h"

#include <vector>

using namespace std;

namespace ch08 {

bool Helper1(int r, int c, const vector<vector<bool>>& maze, vector<Point>& path) {
    if (r == maze.size() || c == maze.front().size() || !maze[r][c]) {
        return false;
    }

    path.push_back({r, c});

    if (r + 1 == maze.size() && c + 1 == maze.front().size()) {
        return true;
    }

    if (Helper1(r + 1, c, maze, path) || Helper1(r, c + 1, maze, path)) {
        return true;
    } else {
        path.pop_back();
        return false;
    }
}

bool Helper2(int r, int c, const vector<vector<bool>>& maze, vector<Point>& path, vector<vector<bool>>& mem) {
        if (r == maze.size() || c == maze.front().size() || !maze[r][c] || mem[r][c]) {
        return false;
    }

    path.push_back({r, c});
    mem[r][c] = true;

    if (r + 1 == maze.size() && c + 1 == maze.front().size()) {
        return true;
    }

    if (Helper1(r + 1, c, maze, path) || Helper1(r, c + 1, maze, path)) {
        return true;
    } else {
        path.pop_back();
        return false;
    }
}

// Решение бутфорсом, рекурсия с возвратом. Из каждой доступной клетки
// пытаемся идти вниз, в случае неудачи - направо. Фактически перебираем 
// все возможные пути. Сложность O(2 ^ (r + c)), т.к. в худшем случае мы
// из каждой клетки пути сделаем 2 шага, а длина любого пути (r + c).
bool FindPath(const vector<vector<bool>>& maze, vector<Point>& path) {
    return Helper1(0, 0, maze, path);
}

// Улучшение брутфорса: отмечаем все клетки, которые уже посещались.
// Очевидно, что из неё путь не был найден и проверять её повторно нет
// смысла. Оптимизацию легко представить на вертикально перегороженном
// лабиринте: робот дойдет до нижней строки лабиринта, повернет направо
// и дойдет до препятствия. Далее рекурсия вернется в первый столбец на
// предпоследнюю строку и опять дойдет до препятствия. Но с оптимизацией
// он не будет исследовать нижние клетки, т.к. они уже посещались...
bool FindPath2(const vector<vector<bool>>& maze, vector<Point>& path) {
    vector<vector<bool>> mem(maze.size(), vector<bool>(maze.front().size(), false));
    return Helper2(0, 0, maze, path, mem);
}

bool operator==(const ch08::Point& lhs, const ch08::Point& rhs) {
    return (lhs.r == rhs.r) && (lhs.c == rhs.c);
}

} // namespace ch08