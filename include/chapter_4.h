#ifndef CHAPTER_4_H_
#define CHAPTER_4_H_

#include "graph.h"
#include "../src/04_trees_graphs/problem_11.h"

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

struct PNode {
    PNode(int k) : key(k) {}
    
    int key;
    PNode* left = nullptr;
    PNode* right = nullptr;
    PNode* parent = nullptr;
};

const int NULL_NODE = std::numeric_limits<int>::min();

// From useful.cpp
Node* CreateSimpleTree(std::initializer_list<int> l);
Node* CreateAnyTree(std::initializer_list<int> l);
PNode* CreateAnyPTree(std::initializer_list<int> l);
int GetTreeHeight(Node* root);
void PrintInOrder(std::vector<int>& v, Node* n);


// Problems
void BFS(Graph<BFSVertex>& gr, VertexId s);

bool IsReachable(Graph<BFSVertex> gr, VertexId from, VertexId to);

Node* CreateBalancedTree(const std::vector<int>& vec);

std::vector<std::list<int>> TreeToLists(Node* root);

bool IsTreeBalanced(Node* root);

bool IsBST(Node* root);

PNode* GetNextNode(PNode* node);

std::vector<VertexId> GetOrder(int project_number, const std::vector<std::pair<VertexId, VertexId>>& dep);

Node* FindAncestor(Node* root, Node* p, Node* q);

std::vector<std::vector<int>> GetSequences(Node* root);

bool IsSubTree(Node* t1, Node* t2);

int CountPaths(Node* root, int target);

} // namespace ch04

#endif  // CHAPTER_4_H