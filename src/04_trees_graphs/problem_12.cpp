/*********************************************************************************
 * Дано бинарное дерево, в котором каждый узел содержит целое число. Разработать
 * алгоритм для подсчета всех путей (сверху вниз), сумма значений которых соответствует
 * заданной величине.
 ********************************************************************************/

#include "chapter_4.h"

#include <unordered_map>

using namespace std;

namespace ch04 {

void CountHelper(Node* node, int prev_sum, unordered_map<int, int>& sums, int& result, const int target) {
    if (!node) {
        return;
    }

    ++sums[prev_sum];
    int current = prev_sum + node->key;
    int delta = current - target;
    result += sums.count(delta) ? sums[delta] : 0;

    CountHelper(node->left, current, sums, result, target);
    CountHelper(node->right, current, sums, result, target);

    --sums[prev_sum];
}

// Здесь очень уместен метод частичных сумм. При спуске от корня до листа
// вычисляем сумму всех элементов пройденного пути и сохраняем результаты 
// в хеш-мапу. Далее находим разницу с заданной суммой и проверяем наличие 
// такой суммы в таблице (и их количество, сумм на пути может быть несколько)
// При рекурсивном "подъеме" к родительскому узлу не забываем удалять суммы.
// Сложность O(h) и память O(h) - фактически наилучшая для бинарного дерева.
int CountPaths(Node* root, int target) {
    unordered_map<int, int> sums;
    int result = 0;

    CountHelper(root, 0, sums, result, target);

    return result;
}

} // namespace ch04
