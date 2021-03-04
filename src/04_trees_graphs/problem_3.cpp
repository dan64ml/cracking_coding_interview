/*********************************************************************************
 * Для бинарного дерева написать алгоритм, который создает массив связных списков
 * всех узлов, находящихся на каждой глубине. Количество списков равно глубине.
 ********************************************************************************/

#include "chapter_4.h"

#include <vector>
#include <list>

using namespace std;

namespace ch04 {

void TTLHelper(vector<list<int>>& vec, size_t depth, Node* node) {
    if (!node) {
        return;
    }

    if (vec.size() <= depth) {
        vec.push_back(list<int>());
    }

    vec[depth].push_back(node->key);

    TTLHelper(vec, depth + 1, node->left);
    TTLHelper(vec, depth + 1, node->right);
}

// В целом - обычный обход дерева. Можно реализовать обход в ширину используя очередь.
// Можно рекурсивно inorder. Порядок обхода важен для правильного создания списков при
// достижении нового уровня. Сложность и память в обоих случаях O(N).
vector<list<int>> TreeToLists(Node* root) {
    vector<list<int>> result;

    TTLHelper(result, 0, root);

    return result;
}

} // namespace ch04
