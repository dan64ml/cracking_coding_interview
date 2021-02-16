/*******************************************************************************
 * Написать функцию, проверяющую, является ли связанный список палиндромом.
 *******************************************************************************/

#include "chapter_2.h"

#include <utility>

using namespace std;

pair<bool, Node*> helper(Node* lst, int size) {
    if (size == 0) {
        return {true, lst};
    } else if (size == 1) {
        return {true, lst->pNext};
    }

    auto [isOk, next] = helper(lst->pNext, size - 2);
    if (!isOk) {
        return {false, nullptr};
    } else {
        return {lst->value == next->value, next->pNext};
    }
}

// Любое решение потребует минимум O(N) памяти или брутфорс со сложностью
// O(N^2) и памятью O(1). Можно явно выделить эту память и сохранить первую
// половину списка, можно неявно, используя рекурсию. Сложность O(N).
bool is_palindrom(Node* lst) {
    int size = get_size(lst);
    if (size == 0) {
        return true; // ???
    }

    auto [ret, _] = helper(lst, size);

    return ret;
}