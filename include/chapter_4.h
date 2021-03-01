#ifndef CHAPTER_4_H_
#define CHAPTER_4_H_

#include "graph.h"

#include <vector>
#include <initializer_list>

struct Node {
    Node(int k) : key(k) {}
    
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
};

// From useful.cpp
Node* CreateSimpleTree(std::initializer_list<int> l);
int GetTreeHeight(Node* root);
void PrintInOrder(std::vector<int>& v, Node* n);


// Problems
void BFS(Graph<BFSVertex>& gr, VertexId s);

bool IsReachable(Graph<BFSVertex> gr, VertexId from, VertexId to);

Node* CreateBalancedTree(const std::vector<int>& vec);

#endif  // CHAPTER_4_H