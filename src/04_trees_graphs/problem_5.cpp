/*********************************************************************************
 * Написать функцию, проверяющую является ли бинарное дерево бинарным деревом поиска.
 ********************************************************************************/

#include "chapter_4.h"

#include <utility>
#include <limits>

using namespace std;

namespace ch04 {

const int ERROR = numeric_limits<int>::min();

pair<int, int> IsBSTHelper(Node* node) {
    int ret_l = node->key;
    int ret_r = node->key;

    if (node->left) {
        auto [l, r] = IsBSTHelper(node->left);
        if (r > node->key) {
            return {ERROR, ERROR};
        }

        ret_l = l;
    }

    if (node->right) {
        auto [l, r] = IsBSTHelper(node->right);
        if (l <= node->key) {
            return {ERROR, ERROR};
        }

        ret_r = r;
    }

    return {ret_l, ret_r};
}

// Первая мысль - обойти дерево inorder и убедиться что все ключи идут в 
// порядке возрастания. Если дерево не содержит дубликатов ключей, или 
// дубликаты хранятся списком в одном узле решение работает. 
// Более универсальный вариант - обойти дерево, составляя интервал ключей
// для левого и правого поддерева, проверяя сохранение условия BST.
// Сложность O(N), память в худшем случае тоже O(N).
bool IsBST(Node* root) {
    if (!root) {
        return true;
    }

    auto [l, _] = IsBSTHelper(root);

    return (l != ERROR);
}

} // namespace ch04
