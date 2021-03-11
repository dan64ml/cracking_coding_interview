#ifndef BS_TREE_H_
#define BS_TREE_H_

#include "chapter_4.h"

namespace ch04 {

template<class T>
class BSTree {
    public:
        void AddNode(T key);
        bool operator==(const BSTree& t) const;
        Node* GetRoot() { return root_; }
    private:
        Node* root_ = nullptr;
};

template<class T>
void BSTree<T>::AddNode(T key) {
    if (!root_) {
        root_ = new Node(key);
        return;
    }

    Node* parent;
    Node* current = root_;
    while (current) {
        parent = current;
        current = (current->key > key) ? current->left : current->right;
    }

    if (parent->key > key) {
        parent->left = new Node(key);
    } else {
        parent->right = new Node(key);
    }
}

bool EqHelper(Node* n1, Node* n2) {
    if (n1 == nullptr && n2 == nullptr) {
        return true;
    }

    if (n1 == nullptr || n2 == nullptr) {
        return false;
    }

    if (n1->key != n2->key) {
        return false;
    }

    if (!EqHelper(n1->left, n2->left)) {
        return false;
    }
    if (!EqHelper(n1->right, n2->right)) {
        return false;
    }

    return true;
}

template<class T>
bool BSTree<T>::operator==(const BSTree<T>& t) const {
    return EqHelper(root_, t.root_); 
}

} // namespace ch4

#endif  // BS_TREE_H_