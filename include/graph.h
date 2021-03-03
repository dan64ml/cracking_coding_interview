#ifndef CCI_GRAPH_H_
#define CCI_GRAPH_H_

#include <vector>
#include <limits>

namespace ch04 {

using VertexId = size_t;
const VertexId NIL = std::numeric_limits<VertexId>::max();

struct BFSVertex {
    bool visited = false;
    VertexId parent = NIL;
    int dist = -1;
};

template<class Vertex>
class Graph {
    public:
        Graph(int vertex_num) : vert_(vertex_num), edges_(vertex_num) {}

        void AddEdge(VertexId from, VertexId to) { edges_[from].push_back(to); }
        void AddDEdge(VertexId from, VertexId to) { 
            edges_[from].push_back(to);
            edges_[to].push_back(from);
        }

        size_t GetVertexNumber() const { return vert_.size(); }
        size_t GetEdgesNumber(VertexId v) const { return edges_[v].size(); }

        Vertex& GetVertex(VertexId v) { return vert_[v]; }
        const Vertex& GetVertex(VertexId v) const { return vert_[v]; }

        const std::vector<VertexId>& GetEdges(VertexId v) const { return edges_[v]; }

    private:
        std::vector<Vertex> vert_;
        std::vector<std::vector<VertexId>> edges_;
};

} // namespace ch04

#endif // CCI_GRAPH_H_