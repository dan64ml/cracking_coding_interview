#ifndef CHAPTER_4_H_
#define CHAPTER_4_H_

#include "graph.h"

void BFS(Graph<BFSVertex>& gr, VertexId s);

bool IsReachable(Graph<BFSVertex> gr, VertexId from, VertexId to);

#endif  // CHAPTER_4_H