/*******************************************************************************
 * Два числа хранятся в виде связанных списков (по цифре на узел, в обратном порядке). 
 * Написать функцию, суммирующую два числа и возвращающую результат в виде списка.
 * Сделать то же для списков в обратном порядке.
 *******************************************************************************/

#include "chapter_2.h"

#include <string>
#include <utility>

using namespace std;

// Вариантов решения множество. Для обратного порядка напрашивается "сложение в столбик",
// главное не забыть про переносы. Сложность O(N) и память O(1).
Node* sum_list_reverse(Node* lst1, Node* lst2) {
    Node head;
    Node* result = &head;

    int carry = 0, num1 = 0, num2 = 0;
    while (lst1 || lst2 || carry) {
        num1 = lst1 ? lst1->value : 0;
        num2 = lst2 ? lst2->value : 0;

        int sum = num1 + num2 + carry;
        carry = sum / 10;
        Node* newNode = new Node(sum % 10);

        result->pNext = newNode;
        result = result->pNext;

        if (lst1) lst1 = lst1->pNext;
        if (lst2) lst2 = lst2->pNext;
    }

    return head.pNext;
}

int list_to_int(Node* lst) {
    int result = 0;

    while (lst) {
        result = result * 10 + lst->value;
        lst = lst->pNext;
    }

    return result;
}

// Вариант с преобразованием списков в числа имеет свои плюсы. Например он очень удобен
// если допустимы отрицательные числа (хотя условие неявно подразумевает только неотрицательные).
// Сложность O(N) и память O(1)
Node* sum_list_forward(Node* lst1, Node* lst2) {
    int num1 = list_to_int(lst1);
    int num2 = list_to_int(lst2);

    string number = to_string(num1 + num2);

    Node head;
    Node* current = &head;
    for (auto c : number) {
        current->pNext = new Node(c - '0');
        current = current->pNext;
    }

    return head.pNext;
}

//=====================================================================================================
// Из академического интереса рекурсивное решение. Списки придется сделать одной длины, соответственно
// придется выяснить длину каждого. Сложность останется O(N), но явно вырастет постоянный множитель.
// Рекурсия потребует O(N) памяти.
Node* expand_with_zeros(Node* lst, int count) {
    Node* current = lst;

    while(count--) {
        Node* node = new Node(0);
        node->pNext = current;
        current = node;
    }

    return current;
}

pair<Node*, int> sum_helper(Node* lst1, Node* lst2) {
    if (!lst1 && !lst2) {
        return {nullptr, 0};
    }

    auto [next, carry] = sum_helper(lst1 ? lst1->pNext : nullptr,
                                    lst2 ? lst2->pNext : nullptr);
    Node* node = new Node();
    node->pNext = next;
    node->value = carry;

    node->value += lst1 ? lst1->value : 0;
    node->value += lst2 ? lst2->value : 0;

    carry = node->value / 10;
    node->value %= 10;

    return {node, carry};
}

Node* sum_list_forward_1(Node* lst1, Node* lst2) {
    int len1 = get_size(lst1);
    int len2 = get_size(lst2);
    if (len1 < len2) {
        lst1 = expand_with_zeros(lst1, len2 - len1);
    } else {
        lst2 = expand_with_zeros(lst2, len1 - len2);
    }

    auto [next, carry] = sum_helper(lst1, lst2);
    if (carry) {
        Node* node = new Node(carry);
        node->pNext = next;
        next = node;
    }

    return next;
}