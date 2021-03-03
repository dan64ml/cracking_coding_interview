/*********************************************************************************
 * Написать алгоритм создания бинарного дерева поиска с минимальной высотой для
 * отсортированного массива с уникальными целочисленными элементами.
 ********************************************************************************/

#include "chapter_4.h"

#include <vector>

using namespace std;

namespace ch04 {

void AddNodeToBSTree(Node* root, int key) {
    Node* parent;

    while (root) {
        parent = root;
        if (root->key > key) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    if (parent->key > key) {
        parent->left = new Node(key);
    } else {
        parent->right = new Node(key);
    }
}

void CreateTreeHelper(Node* root, const vector<int>& vec, size_t left, size_t right) {
    if (left >= right) {
        return;
    }

    size_t mid = (left + right) / 2;
    int key = vec[mid];

    AddNodeToBSTree(root, key);

    CreateTreeHelper(root, vec, left, mid);
    CreateTreeHelper(root, vec, mid + 1, right);
}

// Чтобы дерево имело минимальную высоту нужно выбрать корневой элемент так,
// чтобы он был (примерно) в середине отсортированного массива. Для левого и
// правого поддерева нужно выбирать ключи из середин двух получившихся подмассивов.
// Явно видна рекурсия. Сложность O(NlgN), память O(lgN).
Node* CreateBalancedTree(const vector<int>& vec) {
    if (vec.empty()) {
        return nullptr;
    }

    size_t mid = vec.size() / 2;
    auto root = new Node(vec[mid]);

    CreateTreeHelper(root, vec, 0, mid);
    CreateTreeHelper(root, vec, mid + 1, vec.size());

    return root;
}

} // namespace ch04