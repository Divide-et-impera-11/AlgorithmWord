using namespace std;
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
//---------------------Vertex Cover---------------------
class Graph {
public:
        list<uint32_t>* adj;
        const size_t vrtx;
        int32_t *colors;
        int32_t chromatic;
        Graph(const uint32_t);
        ~Graph();
        Graph& addEdge(const uint32_t, const uint32_t);
        enum  Color
        {
                BLANK = -1
        };
};
Graph::Graph(const uint32_t vrtx) :
        adj(new list<uint32_t>[vrtx]),
        vrtx(vrtx),
        colors(new int32_t[vrtx]),
        chromatic(0) {
        memset(colors, BLANK, sizeof(int32_t) * vrtx);
}
Graph::~Graph() {
        delete[] this->adj;
        delete[] this->colors;
}
Graph& Graph::addEdge(const uint32_t v0, const uint32_t v1) {
        this->adj[v0].push_back(v1);
        this->adj[v1].push_back(v0);
        return *this;
}
void vertex_cover(Graph &graph) {
        bool *visited = new bool[graph.vrtx];
        memset(visited, false, graph.vrtx);
        auto srt = [](list<uint32_t> &ls0, list<uint32_t> &ls1) -> bool {
                return ls0.size() < ls1.size();
        };
        sort(graph.adj, graph.adj + graph.vrtx, srt);
        for (uint32_t offset(0); offset < graph.vrtx; offset++) {
                for (auto itr = graph.adj[offset].begin(); itr != graph.adj[offset].end(); ++itr) {
                        if (!visited[*itr]) {
                                visited[offset] = true;
                                break;
                        }
                }
        }
        for (int i = 0; i < graph.vrtx; i++) {
                cout << "node id: " << i << visited[i] << endl;
        }
}
// Parameter List:
// Graph &graph = graph reference

// Return Value Cases:
// void

// Function Call Example
/*      Graph g1(3);
        g1.addEdge(0, 1);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        vertex_cover(g1);
        vertex_cover(g1);
*/

