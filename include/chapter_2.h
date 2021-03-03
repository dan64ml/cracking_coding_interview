#ifndef CHAPTER_2_H_
#define CHAPTER_2_H_

#include <initializer_list>

namespace ch02 {

struct Node {
    int value;
    Node* pNext = nullptr;

    Node(int v) : value(v) {}
    Node() = default;
};

Node* create_llist(std::initializer_list<int> l);
int get_size(Node* lst);
Node* find_tail(Node* lst);

Node* remove_duplicate(Node* node);

int get_kth(Node* head, int k);

void delete_node(Node* node);

Node* regroup(Node* node, int border);

Node* sum_list_reverse(Node* lst1, Node* lst2);
Node* sum_list_forward(Node* lst1, Node* lst2);
Node* sum_list_forward_1(Node* lst1, Node* lst2);

bool is_palindrom(Node* lst);

Node* is_intersect(Node* lst1, Node* lst2);

Node* find_loop(Node* node);

} // namespace ch02

#endif  // CHAPTER_2_H_
