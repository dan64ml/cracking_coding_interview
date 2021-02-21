/*******************************************************************************
 * Написать функцию, проверяющую, пересекаются ли два связанных списка. Вернуть
 * узел пересечения.
 *******************************************************************************/

#include "chapter_2.h"

using namespace std;

// Можно использовать доппамять и сохранить адреса всех узлов одного списка.
// Далее итерироваться по второму пока не найдем совпадение (или не дойдем 
// до конца). O(N + M) сложность и O(N) память.
// Можно не используя память получить длину списков и сдвинуть в длинном указатель
// на N - M. Далее просто ищем совпадение узлов. O(N + M).
Node* is_intersect(Node* lst1, Node* lst2) {
    int len1 = get_size(lst1);
    int len2 = get_size(lst2);

    if (len1 < len2) {
        for (int i = 0; i < len2 - len1; ++i) {
            lst2 = lst2->pNext;
        } 
    } else {
        for (int i = 0; i < len1 - len2; ++i) {
            lst1 = lst1->pNext;
        }
    }

    while (lst1 != lst2) {
        lst1 = lst1->pNext;
        lst2 = lst2->pNext;
    }

    return lst1;
}