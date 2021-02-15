#include "chapter_2.h"

#include <initializer_list>

using namespace std;

Node* create_llist(initializer_list<int> l) {
    Node head;
    Node* last = &head;

    for (auto v : l) {
        last->pNext = new Node(v);
        last = last->pNext;
    }

    return head.pNext;
}
