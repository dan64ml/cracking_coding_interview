#ifndef CHAPTER_4_H_
#define CHAPTER_4_H_

#include "graph.h"

#include <vector>
#include <initializer_list>
#include <list>
#include <limits>

namespace ch04 {

struct Node {
    Node(int k) : key(k) {}
    
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
};

const int NULL_NODE = std::numeric_limits<int>::min();

// From useful.cpp
Node* CreateSimpleTree(std::initializer_list<int> l);
Node* CreateAnyTree(std::initializer_list<int> l);
int GetTreeHeight(Node* root);
void PrintInOrder(std::vector<int>& v, Node* n);


// Problems
void BFS(Graph<BFSVertex>& gr, VertexId s);

bool IsReachable(Graph<BFSVertex> gr, VertexId from, VertexId to);

Node* CreateBalancedTree(const std::vector<int>& vec);

std::vector<std::list<int>> TreeToLists(Node* root);

bool IsTreeBalanced(Node* root);

} // namespace ch04

#endif  // CHAPTER_4_H