#include "chapter_4.h"

#include <initializer_list>
#include <queue>

using namespace std;

namespace ch04 {

void PrintInOrder(vector<int>& v, Node* n) {
    if (!n) {
        return;
    }

    PrintInOrder(v, n->left);
    v.push_back(n->key);
    PrintInOrder(v, n->right);
}

void HeightHelper(Node* node, int h, int& max_height) {
    if (node == nullptr) {
        return;
    }

    max_height = max(max_height, ++h);
    HeightHelper(node->left, h, max_height);
    HeightHelper(node->right, h, max_height);
}

int GetTreeHeight(Node* root) {
    int height = 0;

    HeightHelper(root, 0, height);

    return height;
}

Node* CreateSimpleTree(initializer_list<int> l) {
    auto it = begin(l);
    if (it == end(l)) {
        return nullptr;
    }

    queue<Node*> q;
    Node* root = new Node(*it++);
    q.push(root);

    while (it != end(l)) {
        auto node = q.front();
        q.pop();
        node->left = new Node(*it++);
        q.push(node->left);

        if (it == end(l)) {
            break;
        }

        node->right = new Node(*it++);
        q.push(node->right);
    }

    return root;
}

} // namespace ch04