/*******************************************************************************
 * Напишите код для удаления дубликатов из неотсортированного связного списка.
 *******************************************************************************/

#include "chapter_2.h"

// Решение без использования доппамяти. Сложность O(N^2).
// Можно использовать unordered_set и запоминать ключи пройденных элементов.
// При обнаружении повтора удалять узел. Тогда сложность/память O(N).
Node* remove_duplicate(Node* node) {
    Node head;
    head.pNext = node;

    while(node) {
        Node* pm = node;
        while (pm->pNext) {
            if (pm->pNext->value == node->value) {
                auto tmp = pm->pNext;
                pm->pNext = pm->pNext->pNext;
                delete tmp;
            } else {
                pm = pm->pNext;
            }
        }

        node = node->pNext;
    }

    return head.pNext;
}