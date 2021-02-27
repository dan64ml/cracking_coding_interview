/*********************************************************************************
 * Дан направленный граф. Проверить наличие маршрута между двумя узлами 
 ********************************************************************************/

#include "graph.h"

#include <queue>

using namespace std;

void BFS(Graph<BFSVertex>& gr, VertexId s) {
    queue<VertexId> q;
    gr.GetVertex(s).visited = true;
    gr.GetVertex(s).dist = 0;
    q.push(s);

    while (!q.empty()) {
        auto v = q.front();
        q.pop();

        gr.GetVertex(v).visited = true;
        for (auto w : gr.GetEdges(v)) {
            if (auto& vertex = gr.GetVertex(w); !vertex.visited) {
                vertex.visited = true;
                vertex.dist = gr.GetVertex(v).dist + 1;
                vertex.parent = v;
                q.push(w);
            }
        }
    }
}

// Класическая задача на обход графа. Обход начинаем из стартового узла.
// Здесь использован обход в ширину. 
bool IsReachable(Graph<BFSVertex> gr, VertexId from, VertexId to) {
    BFS(gr, from);
    return gr.GetVertex(to).visited;
}