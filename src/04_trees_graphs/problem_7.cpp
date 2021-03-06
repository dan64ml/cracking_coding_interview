/*********************************************************************************
 * Дан список проектов и зависимостей(пар проектов в которых первый проект зависит
 * от второго). Найти такой порядок построения, который позволит построить все проекты.
 * Или вернуть ошибку.
 ********************************************************************************/

#include "chapter_4.h"

#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

namespace ch04 {

bool DFSVisit(Graph<DFSVertex<char>>& gr, VertexId v, vector<VertexId>& result) {
    gr.GetVertex(v).color = VertexColor::GRAY;
    for (auto u : gr.GetEdges(v)) {
        if (gr.GetVertex(u).color == VertexColor::GRAY) {
            result.clear();
            return false;
        } else if (gr.GetVertex(u).color == VertexColor::WHITE) {
            if (!DFSVisit(gr, u, result)) {
                return false;
            }
        }
    }

    gr.GetVertex(v).color = VertexColor::BLACK;
    result.push_back(v);

    return true;
}

// Топологическая сортировка как она есть. В DFSVertex можно оставить только цвет. Он необходим
// для отслеживания циклов, при наличии которых сортировка не возможна. Сложность O(V + E).
//
// Чуть подробнее: обходим граф в глубину. В тот момент, когда вершина окрашивается в черный,
// у нее больше нет неисследованных исходящих рёбер, т.е. она больше ни от кого не зависит и
// её можно занести в решение. Если при обходе встретили серую вершину - значит "наступили
// себе на хвост", т.е. нашли цикл.
vector<VertexId> GetOrder(int project_number, const vector<pair<VertexId, VertexId>>& dep) {
    Graph<DFSVertex<char>> gr(project_number);
    
    for (auto [slave, master] : dep) {
        gr.AddEdge(slave, master);
    }

    vector<VertexId> result;
    for (size_t id = 0; id < gr.GetVertexNumber(); ++id) {
        if (gr.GetVertex(id).color == VertexColor::WHITE) {
            DFSVisit(gr, id, result);
        }
    }

    return result;
}

} // namespace ch04
