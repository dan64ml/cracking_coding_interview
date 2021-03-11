/*********************************************************************************
 * Реализовать с нуля класс бинарного дерева поиска, который поддерживает метод
 * GetRandomNode(). Метод должен возвращать случайный узел с равной вероятностью.
 ********************************************************************************/

#ifndef PROBLEM_11_H_
#define PROBLEM_11_H_

#include "chapter_4.h"

#include <random>

using namespace std;

namespace ch04 {

/*********************************************************************************
 * Обеспечить гарантированную случайность и  равновероятность выбора узла та еще
 * задача. Кмк лучше довериться стандартным генераторам. Можно сгенерировать 
 * порядковый номер узла и вернуть по нему случайный узел. Основная проблема - 
 * быстрый поиск узла по номеру. Для этого добавим в каждый узел количество узлов
 * в его правом и левом поддереве. Этот параметр легко поддерживается при вставке
 * и удалении узлов из дерева и позволяет за O(h) находить случайный узел. Т.е. для
 * сбалансированного дерева за O(lgN)
 ********************************************************************************/

template<class T>
struct RBSTNode {
    RBSTNode(T value) : key(value) {}

    T key;

    RBSTNode* left = nullptr;
    RBSTNode* right = nullptr;

    int l_count = 0;
    int r_count = 0;
};

template<class T = int>
class RandomBSTree {
    public:
        void AddNode(T value);
        RBSTNode<T>* GetRandomNode();

    private:
        RBSTNode<T>* root_ = nullptr;
        int count_ = 0;

    public:
        RBSTNode<T>* GetNthElement(int n);
};

template<class T>
void RandomBSTree<T>::AddNode(T value) {
    if (!root_) {
        root_ = new RBSTNode(value);
        ++count_;
        return;
    }

    RBSTNode<T>* current = root_;
    RBSTNode<T>* parent;

    while (current) {
        parent = current;
        if (current->key >= value) {
            ++current->l_count;
            current = current->left;
        } else {
            ++current->r_count;
            current = current->right;
        }
    }

    if (parent->key >= value) {
        parent->left = new RBSTNode<T>(value);
    } else {
        parent->right = new RBSTNode<T>(value);
    }
    ++count_;
}


template<class T>
RBSTNode<T>* RandomBSTree<T>::GetRandomNode() {
    if (count_ == 0) {
        return nullptr;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, count_);

    int idx = distrib(gen);

    return GetNthElement(idx);
}

template<class T>
RBSTNode<T>* NthHelper(RBSTNode<T>* node, int n) {
    if (!node) {
        return nullptr;
    }

    if (node->l_count + 1 == n) {
        return node;
    } else if (node->l_count >= n) {
        return NthHelper(node->left, n);
    } else {
        return NthHelper(node->right, n - node->l_count - 1);
    }
}

template<class T>
RBSTNode<T>* RandomBSTree<T>::GetNthElement(int n) {
    return NthHelper(root_, n);
}

} // namespace ch04

#endif  // PROBLEM_11_H_