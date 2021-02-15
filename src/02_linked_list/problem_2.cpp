/*******************************************************************************
 * Напишите алгоритм для нахождении в односвязном списке к-го элемента с конца.
 *******************************************************************************/

#include "chapter_2.h"

#include <limits>

using namespace std;

// Решение с двумя бегунками. O(N) сложность и O(1) память.
// Авторская идея с рекурсией странна и требует O(N) памяти.
int get_kth(Node* head, int k) {
    if (!head || k < 1) {
        return numeric_limits<int>::min();
    }

    Node* fp = head;
    for (int i = 0; i < k; ++i) {
        if (!fp) {
            return numeric_limits<int>::min();
        }

        fp = fp->pNext;
    }

    while (fp) {
        head = head->pNext;
        fp = fp->pNext;
    }

    return head->value;
}
