/*******************************************************************************
 * Напишите алгоритм разбиения односвязного списка вокруг заданного значения. 
 * Порядок узлов в группах не важен...
 *******************************************************************************/

#include "chapter_2.h"

using namespace std;

namespace ch02 {

// Общая идея - элементы меньшие граничного значения вставляем в голову нового списка,
// остальные - в хвост. Сложность O(N) и память O(1).
Node* regroup(Node* node, int border) {
    if (!node) {
        return nullptr;
    }

    Node* head = node;
    Node* tail = node;
    Node* current = node->pNext;
    head->pNext = nullptr;

    while (current) {
        Node* tmp = current->pNext;
        if (current->value < border) {
            current->pNext = head;
            head = current;
        } else {
            tail->pNext = current;
            current->pNext = nullptr;
            tail = current;
        }

        current = tmp;
    }

    return head;
}

} // namespace ch02
