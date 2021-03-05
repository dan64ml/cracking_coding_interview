/*********************************************************************************
 * Написать функцию, возвращающую "следующий" узел бинарного дерева поиска.
 * Узлы содержат ссылку на родителя.
 ********************************************************************************/

#include "chapter_4.h"

#include <utility>
#include <limits>

using namespace std;

namespace ch04 {

// Есть 3 частных случая:
// Узел имеет правое поддерево. В этом случае искомый узел - самый маленький в нём.
// Правого поддерева нет и узел левый у родителя. Родитель - искомый узел.
// Правого поддерева нет и узел правый у родителя. Ищем родительский узел с бОльшим
// ключем (или, что равносильно, узел в который мы придем слева). Сложность O(N) в
// худшем случае. Память O(1).
//
// PS. Эту логику очень просто понять если держать в уме inorder обход.
PNode* GetNextNode(PNode* node) {
    if (!node) {
        return nullptr;
    }

    if (node->right) {
        auto current = node->right;
        while (current->left) {
            current = current->left;
        }

        return current;
    } else {
        if (!node->parent) {
            return nullptr;
        }

        if (node == node->parent->left) {
            return node->parent;
        } else {
            auto current = node->parent;
            while (current && node->key > current->key) {
                current = current->parent;
            }

            return current;
        }
    }
}

} // namespace ch04